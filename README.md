# arudinoServo
experimenting with servo motor with the ESP32 arduino board


# Part 1: ESP32 LED and Servo Toggle Control Project

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

---
---

# Part 2: ESP32 Servo Motor Angle Control with Slider

This project demonstrates how to control a servo motor's angle using a web-based slider interface. The ESP32 acts as a web server and receives HTTP requests from the slider, which sets the servo's position based on the slider value.

---

## **What This Project Does**
- Hosts a web-based slider (0° to 360°) to control a servo motor's angle.
- Sends the slider value to the ESP32 via an HTTP GET request.
- The ESP32 updates the servo motor's position in real time to match the slider value.

---

## **Components Used**
1. **ESP32 Dev Board**
2. **MG90S Servo Motor**
3. **Jumper Wires**
4. **5V Power Supply (if required for the servo)**

---

## **Wiring Instructions**
### **Servo Motor Wiring**
- **Red Wire**: Connect to **5V** on the ESP32 (or an external 5V power supply if needed).
- **Brown Wire**: Connect to **GND** on the ESP32.
- **Orange Wire**: Connect to **GPIO 22** on the ESP32 (or any other GPIO defined in the code).

---

## **How It Works**
1. The ESP32 connects to a WiFi network and starts a web server on port 80.
2. A slider interface is hosted on a webpage.
3. When the slider value is changed, an HTTP GET request is sent to the ESP32 with the slider's value (e.g., `/setAngle?value=90`).
4. The ESP32 reads the value and updates the servo motor's position using the **ESP32Servo** library.
5. The servo motor rotates to the specified angle (0° to 180°).

---

## **Limitations**
- The MG90S servo motor has a rotation range of **0° to 180°**. Slider values outside this range are ignored.
- For 360° rotation, a continuous rotation servo or stepper motor would be required.

---

## **Steps to Replicate**
### **1. Prepare the Hardware**
- Connect the servo motor to the ESP32 as described above.

### **2. Upload the Arduino Code**
1. Install the required libraries in Arduino IDE:
   - [ESP32Servo](https://github.com/madhephaestus/ESP32Servo).
2. Copy and upload the provided Arduino code to your ESP32.
3. Open the Serial Monitor to find the ESP32's IP address.

### **3. Host the HTML File**
1. Copy the provided HTML file to your computer.
2. Open the HTML file in a web browser.
3. Replace `<ESP32_IP>` in the JavaScript section with the ESP32's actual IP address.

### **4. Control the Servo**
- Use the slider on the webpage to adjust the servo motor's angle in real time.

---

## **Code Summary**
### **HTML Code**
- Hosts a slider interface.
- Sends the slider value to the ESP32 using an HTTP GET request.

### **Arduino Code**
- Sets up the ESP32 as a WiFi-connected web server.
- Receives the slider value and moves the servo motor to the specified angle.

---

## **Applications**
- Robotics (e.g., controlling robotic joints).
- IoT systems (e.g., remote-controlled mechanisms).
- Educational projects for learning embedded systems and web-based control.

---

## **Troubleshooting**
1. **No Response from the ESP32**:
   - Ensure the ESP32 is connected to the correct WiFi network.
   - Verify that the browser and ESP32 are on the same network.

2. **Servo Motor Not Moving**:
   - Check the wiring and power supply for the servo.
   - Confirm the servo is attached to the correct GPIO pin in the code.

3. **Slider Not Sending Requests**:
   - Ensure the ESP32's IP address is correctly set in the HTML file.

---

Enjoy building and experimenting with this project! If you have any questions or need assistance, feel free to reach out.


Happy tinkering!
