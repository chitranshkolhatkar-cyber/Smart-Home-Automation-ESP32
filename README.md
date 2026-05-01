# Smart Home Automation System (ESP32 + MQTT + Node-RED)

## 📌 Project Overview
This project implements a Smart Home Automation System to control **two light bulbs remotely** using ESP32, MQTT protocol, and a Node-RED web dashboard. The system demonstrates real-time communication, low latency, and efficient IoT-based automation.

---

## 🎯 Objectives
- Control two bulbs remotely using web interface
- Implement MQTT communication
- Demonstrate IoT-based automation
- Achieve low-latency response (<200 ms)

---

## ⚙️ Features
- Independent control of 2 bulbs
- Web-based dashboard (Node-RED)
- MQTT publish/subscribe communication
- Active-LOW relay logic
- Low-cost and scalable system

---

## 🛠️ Hardware Components
- ESP32 Microcontroller
- 2-Channel Relay Module
- 2 Light Bulbs
- Jumper Wires
- Power Supply

---

## 💻 Software Used
- Arduino IDE
- Node-RED
- MQTT Broker: broker.emqx.io

---

## 🔌 Circuit Connections
| ESP32 Pin | Relay |
|----------|------|
| GPIO 5   | IN1  |
| GPIO 18  | IN2  |
| 5V       | VCC  |
| GND      | GND  |

---

## 📡 MQTT Topics
| Bulb | Topic |
|------|--------|
| Bulb 1 | home/bulb1 |
| Bulb 2 | home/bulb2 |

Commands:
- ON → Turn ON bulb  
- OFF → Turn OFF bulb  

---

## 🚀 Working Principle
1. User interacts with Node-RED dashboard  
2. Node-RED publishes MQTT message  
3. ESP32 subscribes and receives message  
4. Relay module switches bulb ON/OFF  
5. Active-LOW logic: LOW = ON, HIGH = OFF  

---

## 📊 Results
- Stable communication using MQTT  
- Fast response time (<200 ms)  
- Reliable control of both bulbs  
- Successful implementation of IoT-based automation  

---

## 🔮 Future Scope
- Add more appliances  
- Mobile app integration  
- Voice control (Alexa/Google Assistant)  
- Cloud data monitoring  

---

## 👨‍💻 Author
Chitransh Kolhatkar
