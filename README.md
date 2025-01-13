
# Arduino Servo Projects

Experimenting with a servo motor and the ESP32 Arduino board.

---

## Part 1: ESP32 LED and Servo Toggle Control Project

This project demonstrates controlling an LED and a servo motor via a web interface using the ESP32. It includes wiring details, code logic, and steps for replication.

### Wiring Diagram

#### Components
1. **ESP32 Board**
2. **LED**
3. **Resistor (220Ω)** (Optional)
4. **MG90S Servo Motor**
5. **Jumper Wires**

#### Connections

##### LED Wiring
- **Anode (+)**: Connect to **GPIO 15** on the ESP32 through a **220Ω resistor**.
- **Cathode (-)**: Connect to **GND** on the ESP32.

##### Servo Motor Wiring
- **Red Wire**: Connect to **5V** pin on the ESP32 (or the '3v3' pin, if available).
- **Brown Wire**: Connect to **GND** on the ESP32.
- **Orange Wire**: Connect to **GPIO 22** (signal pin).

### Code Logic

#### Overview
The code sets up the ESP32 as a web server, allowing clients to control the LED and servo motor through HTTP requests.

#### Key Features
1. **WiFi Connection**: Connects the ESP32 to a specified WiFi network.
2. **Web Server**: Listens for HTTP requests on port 80.
3. **Request Handling**: 
   - `/LED_ON`: Turns the LED on and moves the servo to **45°**.
   - `/LED_OFF`: Turns the LED off and moves the servo to **0°**.
4. **Servo Control**: Uses the **ESP32Servo** library to generate PWM signals.
5. **Debugging**: Serial output logs for WiFi status and actions.

### Steps to Replicate
1. **Prepare Components**: Assemble the ESP32, LED, and servo motor.
2. **Install Required Libraries**: Set up the Arduino IDE for ESP32 and install the **ESP32Servo** library.
3. **Upload Code**: Copy the code, upload to ESP32, and ensure proper board and port selection.
4. **Connect to WiFi**: Use the Serial Monitor to find the ESP32's IP address.
5. **Control Devices**: Navigate to:
   - `http://<ESP32_IP>/LED_ON` to turn the LED on and move the servo to 45°.
   - `http://<ESP32_IP>/LED_OFF` to turn the LED off and move the servo to 0°.

### Troubleshooting
1. **No Serial Output**: Check baud rate (115200) and USB cable compatibility.
2. **WiFi Issues**: Verify SSID/password and network range.
3. **Servo Jittering**: Use an external power source if necessary.

---

## Part 2: ESP32 Servo Motor Angle Control with Slider

This project demonstrates controlling a servo motor's angle using a web-based slider interface.

### Components
1. **ESP32 Dev Board**
2. **MG90S Servo Motor**
3. **Jumper Wires**
4. **5V Power Supply** (if required for the servo)

### Wiring Instructions
- **Red Wire**: Connect to **5V** (or external power supply).
- **Brown Wire**: Connect to **GND**.
- **Orange Wire**: Connect to **GPIO 22**.

### How It Works
1. ESP32 connects to WiFi and starts a web server.
2. Hosts a slider interface on a webpage.
3. Sends slider values to ESP32, which adjusts the servo angle.

### Steps to Replicate
1. **Prepare Hardware**: Connect the servo motor to the ESP32.
2. **Upload Code**: Install libraries and upload code to ESP32.
3. **Host HTML File**: Open the HTML file in a browser and set the ESP32's IP address.
4. **Control Servo**: Use the slider to adjust the servo angle.

### Troubleshooting
1. **No Response**: Verify WiFi connection and correct IP setup.
2. **Servo Issues**: Check wiring and power.
3. **Slider Issues**: Ensure correct IP in the HTML file.

---

Enjoy building and experimenting with these projects!

Happy tinkering!
