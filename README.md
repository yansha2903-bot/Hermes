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
