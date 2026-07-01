# 🔐 Smart Door Lock System

An embedded access control system developed using **Arduino Nano** that combines **RFID authentication**, **PIN-based verification**, and **PIR motion detection** to provide secure, reliable, and low-cost door access management. The system unlocks a solenoid lock only after successful authentication, enhancing security while remaining simple to deploy in homes, offices, laboratories, and educational institutions.

---

## 📌 Project Highlights

- Dual authentication using RFID card and keypad PIN
- Automatic solenoid door lock control
- PIR-based motion sensing
- Visual and audible access status indication
- Protection against unauthorized access attempts
- Modular design for future IoT integration
- Cost-effective embedded security solution

---

## 🏗 System Architecture

```
                 RFID Card
                     │
                     ▼
              RFID RC522 Module
                     │
                     │
Keypad ─────────────►│
                     ▼
              Arduino Nano
          ┌──────────┼──────────┐
          │          │          │
          ▼          ▼          ▼
      Solenoid     Buzzer      LEDs
        Lock

          ▲
          │
     PIR Motion Sensor
```

---

## ⚙ Hardware Components

| Component | Purpose |
|-----------|---------|
| Arduino Nano | Main controller |
| RFID RC522 | RFID authentication |
| RFID Tags | User identification |
| 4×4 Matrix Keypad | Password entry |
| PIR Sensor | Motion detection |
| Solenoid Lock | Door locking mechanism |
| Relay Module | Controls lock |
| Buzzer | Security alert |
| LEDs | Status indication |
| Power Supply | System power |

---

## 🚀 Working Principle

### Step 1 – Idle State
The Arduino continuously monitors both the RFID reader and keypad while the door remains locked.

### Step 2 – Authentication
The user can either:

- Scan an authorized RFID card
- Enter the correct password using the keypad

### Step 3 – Verification
The controller compares the received credentials with the stored authorized data.

### Step 4 – Access Control

**Authorized User**

- Unlocks the solenoid lock
- Activates green status indication
- Keeps the door unlocked for a predefined duration
- Automatically locks the door again

**Unauthorized User**

- Door remains locked
- Red LED turns ON
- Buzzer generates an alert
- Access request is rejected

### Step 5 – Motion Detection

The PIR sensor detects nearby movement and can be integrated for additional monitoring or security notifications.

---

## 📂 Repository Structure

```
Smart-Door-Lock-System
│
├── Arduino_Code/
│   └── Smart_Door_Lock.ino
│
├── Circuit_Diagram/
│
├── Components_List/
│
├── Documentation/
│
├── Images/
│
├── README.md
└── LICENSE
```

---

## 📷 Project Images

Project images will be added here.

| Prototype | Working Setup |
|------------|---------------|
| Coming Soon | Coming Soon |

---

## 💡 Applications

- Smart Home Security
- Office Access Control
- College Laboratories
- Hostel Rooms
- Server Rooms
- Restricted Areas
- Small Business Security

---

## 🔮 Future Enhancements

- ESP32 Wi-Fi connectivity
- Mobile application control
- Cloud-based access logging
- Fingerprint authentication
- Face recognition
- Remote unlock functionality
- Temporary visitor access
- Telegram or Email alerts

---

## 🛠 Software

- Arduino IDE
- Embedded C / Arduino Framework

---

## 👨‍💻 Author

**Obito Justin**

B.E. Electronics and Communication Engineering

Knowledge Institute of Technology, Salem

---

## ⭐ Support

If you found this project useful, consider giving this repository a **⭐ Star**.

---

## 📄 License

This project is licensed under the MIT License.
