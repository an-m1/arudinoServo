#include <WiFi.h>
#include <ESP32Servo.h> // Include the Servo library for ESP32

// WiFi credentials
const char* ssid = "<Your Wifi Name>";      // Replace with your WiFi SSID
const char* password = "<Your Wifi Password>"; // Replace with your WiFi Password

// GPIO pin for the LED and Servo
const int ledPin = 15;    // Adjust based on your circuit
const int servoPin = 22;  // GPIO pin for the servo signal (change as needed)

WiFiServer server(80); // Create a web server on port 80

Servo myServo;         // Create a Servo object

void setup() {
  // Initialize LED
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Initially off

  // Initialize Servo
  myServo.attach(servoPin); // Attach the servo to the specified pin
  myServo.write(0);         // Start at 0 degrees

  // Initialize Serial for debugging
  Serial.begin(115200);
  delay(1000);

  // Connect to WiFi
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Start the web server
  server.begin();
}

void checkWiFiConnection() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Reconnecting to WiFi...");
    WiFi.disconnect();
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("\nReconnected to WiFi");
  }
}

void loop() {
  checkWiFiConnection(); // Check and reconnect WiFi if it gets disconnected
  WiFiClient client = server.available(); // Check for incoming client

  if (client) {
    String request = client.readStringUntil('\r'); // Read the HTTP request
    Serial.println("Request: " + request);        // Debug: Print the request
    client.flush();

    // Handle LED and Servo control
    if (request.indexOf("/LED_ON") != -1) {
      digitalWrite(ledPin, HIGH);   // Turn LED ON
      myServo.write(45);           // Move servo to 45 degrees
      Serial.println("LED ON, Servo at 45 degrees");
    } else if (request.indexOf("/LED_OFF") != -1) {
      digitalWrite(ledPin, LOW);   // Turn LED OFF
      myServo.write(0);            // Move servo to 0 degrees
      Serial.println("LED OFF, Servo at 0 degrees");
    }

    // Send response headers with CORS support
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/plain");
    client.println("Access-Control-Allow-Origin: *"); // CORS header
    client.println("Connection: close");
    client.println();
    client.println("OK");
    client.stop();
  }
}
