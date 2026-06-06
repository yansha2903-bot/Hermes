# HERMES 🚀

## Project Overview
The goal of this project was to design an hardware board integrated with an IMU sensor and program it using low-level I2C register configuration.

### Hardware Details
* **Microcontroller:** Seeed Studio XIAO RP2040
* **Sensor:** MPU-6050 Accelerometer & Gyroscope
* **Components:** 0402 SMD resistors and filtering/decoupling capacitors (2.2nF for CPOUT, 100nF for REGOUT, and 0.1uF bypass caps)
* **Bus:** I2C interface pulled up via 4.7kΩ resistors on a single top copper layer (`F.Cu`).

### Firmware Details
* Written in **Arduino C++** using the built-in `Wire.h` library.
* Directly reads and configures registers (`0x6B` for sensor power boot-up and `0x1B` for gyroscope scaling).
* Implements sequential reading starting from register `0x43` using bit-shifting (`<< 8`) to turn 8-bit pieces into real 16-bit data.
* Calculates cumulative angular rotation (`rotationZ`) dynamically using time intervals (`dt`).
  
<img width="2560" height="1440" alt="2026-06-06_19-20-15" src="https://github.com/user-attachments/assets/95029742-203d-4b23-b46b-b32cb1541c15" />
<img width="2560" height="1440" alt="IMG_7633" src="https://github.com/user-attachments/assets/ffe8637c-0166-475b-9f77-05ec0e4fc9ea" />
<img width="2560" height="1440" alt="IMG_7637" src="https://github.com/user-attachments/assets/23c30427-efb8-47e7-afc8-78e3a8112f1f" />
