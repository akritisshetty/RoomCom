# RoomCom - IoT-Based Temperature & Humidity Monitoring System

**RoomCom** is an IoT project that uses the ESP32 microcontroller and a DHT11 sensor to monitor real-time room temperature and humidity. It serves a responsive web interface over Wi-Fi, allowing users to view sensor data on any browser-enabled device. A blue LED turns on when the room temperature exceeds a set comfort threshold.

---

## Features

* Wi-Fi-enabled web dashboard hosted on ESP32
* Real-time temperature and humidity display using DHT11
* Condition-based LED indicator for comfortable environment
* Responsive design using HTML, CSS, and JavaScript

---

## Technologies Used

* **Hardware:** ESP32, DHT11 Sensor, LED
* **Software:** Embedded C++, HTML, CSS, JavaScript
* **Libraries:** WiFi.h, WebServer.h, Adafruit Sensor Library, DHT.h
* **Tools:** Arduino IDE, Serial Monitor

---

## How It Works

1. ESP32 connects to the local Wi-Fi using credentials.
2. DHT11 sensor reads temperature and humidity every 5 seconds.
3. If temperature > 24°C, the blue LED is turned on.
4. Data is displayed on a web page hosted by the ESP32.

---

## Preview

> *(Add screenshots or a diagram here if available)*
> Example:
> ![RoomCom UI Screenshot](preview.png)

---

## Setup Instructions

1. **Install Libraries**

   * `Adafruit Sensor`
   * `DHT sensor library`
   * Ensure `WiFi.h` and `WebServer.h` are available (ESP32 core)

2. **Upload Code**

   * Open the project in **Arduino IDE**
   * Select the correct **ESP32 board** and COM port
   * Update Wi-Fi credentials in code
   * Upload the sketch to ESP32

3. **Access the Web Interface**

   * Open Serial Monitor to get the IP address
   * Visit the IP in your browser to view real-time data

---

## File Structure

```
RoomCom/
├── RoomCom.ino        # Main project file
├── README.md          # Project documentation
```

---
