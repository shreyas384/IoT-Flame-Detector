# IoT-Based Flame Detector 🔥

An IoT-based flame detection system that alerts users locally (buzzer) and remotely (Telegram + Arduino IoT Cloud).

## Features
- Detects flame using a digital flame sensor.
- Triggers buzzer for local alert with repeatable beep pattern.
- Optional: sends instant notifications via Telegram bot.
- Optional: streams state to Arduino IoT Cloud (view on Arduino IoT Remote app).
- Clean repo structure with templates for docs and setup guides.

## Hardware (example)
- ESP8266
- Flame sensor module (digital OUT)
- Active buzzer
- Jumper wires, breadboard

### Suggested Wiring
| Function | Pin (ESP8266) |
|---------|----------------|
| Flame sensor DOUT | D6 |
| Buzzer +          | D5 |
| Buzzer −          | GND |
| Sensor VCC        | 3V3 |
| Sensor GND        | GND |

> Many flame sensors are **active LOW** on DOUT (LOW means flame detected). Adjust `FLAME_ACTIVE_LOW` in code if yours differs.

## Firmware
- See `firmware/flame_detector.ino`
- Copy `firmware/config.example.h` to `firmware/config.h` and fill secrets (Wi‑Fi, Telegram, etc.).
- Install libraries if you enable Telegram or Arduino IoT Cloud.

## Repository Structure
```
IoT-Flame-Detector/
├─ README.md
├─ LICENSE
├─ .gitignore
├─ hardware/
│  ├─ components_list.md
│  └─ PLACEHOLDER
├─ firmware/
│  ├─ flame_detector.ino
│  └─ config.example.h
├─ cloud/
│  ├─ arduino_iot_setup.md
│  └─ telegram_bot_setup.md
└─ docs/
   ├─ project_report_template.md
   └─ screenshots/.gitkeep
```

## Quick Start
1. Clone or download this repo.
2. In `firmware/`, make a copy of `config.example.h` named `config.h` and add your Wi‑Fi + Telegram details (optional).
3. Open `flame_detector.ino` in Arduino IDE.
4. Select your ESP8266 board and COM port, then **Upload**.
5. Open Serial Monitor @ 115200 baud to see logs.

## Future Improvements
- SMS alerts (Twilio).
- False positive reduction (moving average, adaptive threshold).
- Web dashboard for historical events.
