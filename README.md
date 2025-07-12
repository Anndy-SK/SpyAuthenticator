# 🔐 Spy Authenticator for Children's English Camp
**Spy Authenticator** is a playful RFID-based access system designed for kids at an English-themed summer camp.
It randomly decides whether to grant or deny access when a card is scanned — making the experience suspenseful and exciting!

## 🎯 Project Purpose and 👦👧 Target Audience
- Spark curiosity with spy-themed elements
- Kids (8+) in camps, STEM activities, and schools
- Educators and mentors running workshops

## 🧩 Components Used
| Component         | Description                                         |
|-------------------|-----------------------------------------------------|
| Arduino Nano      | Microcontroller for handling logic                  |
| RFID Reader RC522 | Scans 13.56 MHz RFID cards                          |
| RFID Cards        | Used by "agents" to request access                  |
| LCD Display (I2C) | Shows messages like "Access Approved!" or "Denied!" |
| Relay Modules     | Used to control lights or external devices          |
| Red Beacon Light  | Blinks on access denial                             |
| Green Beacon Light| Lights up on access approval                        |
| Buzzer/Alarm      | Plays tones based on access result                  |
| Voltage Converter | Powers components at the correct voltages          |


## ⚙️ How It Works
1. The system displays **"Scan card!"** on the LCD.
2. A child scans an RFID card.
3. The system generates a random number between 1 and 100.
4. If the number is **15 or lower** (15% chance):  
   - **Access is Denied!**
   - Red light blinks via relay.
   - Buzzer plays a warning tone pattern.
5. If the number is **greater than 15** (85% chance):  
   - **Access is Approved!**
   - Green light turns on.
   - Buzzer plays a short success melody.
6. The system resets and waits for the next card.

> ⚠️ The decision is completely **random** — it does **not** depend on the specific RFID card.

## 📦 Setup & Installation
1. Upload the Arduino sketch to the Nano using the Arduino IDE.
2. Connect all components based on the wiring guide below.
3. Power the system via USB or external source.
4. You're ready to play!

## 🔌 Wiring Diagram
| Component        | Arduino Pin       |
|------------------|-------------------|
| RC522 - SDA      | D10               |
| RC522 - SCK      | D13               |
| RC522 - MOSI     | D11               |
| RC522 - MISO     | D12               |
| RC522 - RST      | D9                |
| LCD Display (I2C)| SDA/SCL (A4, A5)  |
| Green Relay      | D4                |
| Red Relay        | D5                |
| Green LED        | D6                |
| Red LED          | D7                |
| Buzzer           | D8                |
> 📌 Note: Used inter pull-up resistor `INPUT_PULLUP` for I2C lines.

## 📚 License
This project is open-source and may be reused or modified for educational and non-commercial purposes. 
Created by AnndySK.
