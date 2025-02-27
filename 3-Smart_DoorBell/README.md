# Smart Door Bell

    If the person is detected in the door step, Notification send via blynk app and Turn on the Door Bell.

## Components

- Multi Output Power module
- Adapter
- Node MCU ESP8266
- PIR Sensor
- Relay

## Connection

| Node MCU | Components |
| -------- | ---------- |
| D2       | PIR sensor |
| D5       | Relay bell |
| D7       | Servo      |
| Vin      | Multi 5V   |
| Gnd      | Gnd        |

PIR - 3.3 V
relay - 5V

## References

- [PIR sensor](https://www.electronicwings.com/sensors-modules/pir-sensor)
