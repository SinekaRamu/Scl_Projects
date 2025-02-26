# IOT based Home Automation

IoT-based home automation enables smart control of household appliances using internet-connected devices. It enhances convenience, energy efficiency, and security by allowing remote operation and automation of devices through mobile apps, voice assistants, or web interfaces.

## Key Components:

- Microcontroller – Node MCU (ESP8266) to process commands.
- Actuators – Relays, motors, and smart switches to control appliances.
- Communication Modules – WiFi for connectivity.
- Cloud Platform – Blynk for remote access and data storage.
- Mobile/Web App – Blynk App For real-time monitoring and control.

## Components Used:

- ESP8266 NodeMCU
- 2-Channel Relay
- Servo Motor
- Dc Motor with Fan
- LED (12V)
- Multi Output power module
- Adapter

## Connection

| Node MCU | Components |
| -------- | ---------- |
| D1       | Relay Fan  |
| D2       | Relay LED  |
| D7       | Servo      |
| Vin      | Multi 5V   |
| Gnd      | Gnd        |

- DC motor is connected with relay with 3.3 V Supply
- LED is connected with relay with 12 V supply
- Node MCU is power via Vin with 5V.
