# arudinoServo
experimenting with servo motor with the ESP32 arduino board


# ESP32 LED and Servo Toggle Control Project

This project demonstrates how to control an LED and a servo motor via a web interface using the ESP32. It includes wiring details, code logic, and steps for replication.

---

## **Wiring Diagram**
### **Components**
1. **ESP32 Board**
2. **LED**
3. **Resistor (220Ω)** (Optional)
4. **MG90S Servo Motor**
5. **Jumper Wires**

### **Connections**
#### **LED Wiring**
- **Anode (+)**: Connect to **GPIO 15** on the ESP32 through a **220Ω resistor**.
- **Cathode (-)**: Connect to **GND** on the ESP32.

#### **Servo Motor Wiring**
- **Red Wire**: Connect to **5V** pin on the ESP32 (I used the '3v3' pin on my ESP32 board).
- **Brown Wire**: Connect to **GND** on the ESP32.
- **Orange Wire**: Connect to **GPIO 22 / D22** (signal pin).

---

## **Code Logic**
### **Overview**
The code sets up the ESP32 as a web server, allowing clients to control the LED and servo motor through HTTP requests. I used the index.html from my 'arduinoLight' repository, as that website already had a toggle button ready.

### **Key Features**
1. **WiFi Connection**:
   - The ESP32 connects to a specified WiFi network using the provided SSID and password. You will need to change this in the .ino code file.

2. **Web Server**:
   - A web server listens for incoming HTTP requests on port 80.

3. **Request Handling**:
   - `/LED_ON`: Turns the LED on and moves the servo to **45 degrees**.
   - `/LED_OFF`: Turns the LED off and moves the servo to **0 degrees**.

4. **Servo Control**:
   - The servo motor is controlled using the **ESP32Servo** library, which generates PWM signals.

5. **Debugging**:
   - Serial output logs WiFi status, incoming requests, and actions performed for easy debugging.

---

## **Steps to Replicate**
1. **Prepare the Components**:
   - Assemble the ESP32, LED, and servo motor as per the wiring instructions above.

2. **Install Required Libraries**:
   - Ensure the Arduino IDE is set up for ESP32: [ESP32 Setup Guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html).
   - Install the **ESP32Servo** library through the Arduino Library Manager.

3. **Upload the Code**:
   - Copy the code into the Arduino IDE.
   - Connect the ESP32 to your computer via USB.
   - Select the correct **Board** and **Port** in `Tools`.
   - Upload the code to the ESP32.

4. **Connect to WiFi**:
   - Open the Serial Monitor at **115200 baud** to view the ESP32's IP address.

5. **Control the Devices**:
   - Open a web browser and navigate to:
     - `http://<ESP32_IP>/LED_ON` to turn the LED on and move the servo to 45°.
     - `http://<ESP32_IP>/LED_OFF` to turn the LED off and move the servo to 0°.

---

## **How the Code Works**
### **Setup**
- **WiFi Initialization**: The ESP32 connects to the specified WiFi network.
- **Peripheral Setup**:
  - The LED is set as an output and initialized to OFF.
  - The servo motor is attached to GPIO 14 and set to 0 degrees.

### **Loop**
- Continuously checks for incoming HTTP requests from clients.
- Parses requests to determine the desired action (`LED_ON` or `LED_OFF`).
- Updates the LED state and servo position based on the request.

---

## **Troubleshooting**
1. **No Serial Output**:
   - Ensure the baud rate in the Serial Monitor matches the code (115200).
   - Verify the USB cable supports data transfer.

2. **WiFi Not Connecting**:
   - Double-check the SSID and password in the code.
   - Ensure the router is operational and within range.

3. **Servo Jittering**:
   - Use an external power source for the servo if the ESP32's 5V pin cannot supply enough current.

---

## **Applications**
- Remote-controlled robotics.
- IoT-based home automation systems.
- Educational projects for learning embedded systems and web-based control.

---

## **Additional Notes**
- Ensure a stable power supply for the ESP32 and servo motor.
- Modify the GPIO pins in the code if your wiring differs.

Happy tinkering!
