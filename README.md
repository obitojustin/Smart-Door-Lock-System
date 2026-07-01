# Smart Door Lock System

## Overview

The Smart Door Lock System is an Arduino Nano-based embedded security project designed to provide secure and reliable access control. The system combines RFID authentication, keypad password verification, and PIR motion detection to enhance security. A solenoid door lock is activated only after successful authentication, preventing unauthorized access.

---

## Features

- RFID card-based authentication
- Password-based authentication using a keypad
- Dual-layer security for improved protection
- PIR sensor for motion detection
- Solenoid lock control
- LED and buzzer status indication
- Low-cost embedded security solution

---

## Components Used

| Component | Quantity |
|----------|----------|
| Arduino Nano | 1 |
| RFID RC522 Module | 1 |
| RFID Card/Tag | 1 or more |
| 4×4 Matrix Keypad | 1 |
| PIR Motion Sensor | 1 |
| Solenoid Door Lock | 1 |
| Relay Module | 1 |
| Buzzer | 1 |
| LEDs | 2 |
| Power Supply | 1 |
| Jumper Wires | As required |

---

## Working Principle

1. The system continuously waits for an RFID card or keypad input.
2. When an RFID card is scanned, its UID is compared with stored authorized IDs.
3. Alternatively, the user can enter a password using the keypad.
4. If authentication is successful, the relay activates the solenoid lock to unlock the door.
5. After a predefined delay, the door locks automatically.
6. The PIR sensor detects nearby motion and can be used for additional monitoring or alerts.
7. Invalid authentication attempts trigger a buzzer and access is denied.

---

## Project Structure

```
Smart-Door-Lock-System/
│
├── Arduino_Code/
├── Circuit_Diagram/
├── Components_List/
├── Documentation/
├── Images/
├── README.md
└── LICENSE
```

---

## Applications

- Home Security
- Office Access Control
- Laboratory Security
- Hostel Rooms
- Smart Buildings

---

## Future Improvements

- Wi-Fi monitoring using ESP32
- Mobile application control
- Fingerprint authentication
- Face recognition
- Cloud-based access logs
- Temporary visitor passwords

---

## Author

**Obito Justin**

Electronics and Communication Engineering (ECE)

Knowledge Institute of Technology

---

## License

This project is licensed under the MIT License.
