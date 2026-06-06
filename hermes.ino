#include <Wire.h>

#define MPU_ADDR 0x68
#define OLED_ADDR 0x3C

float rotationZ = 0;
unsigned long lastTime = 0;
int16_t gyroZ = 0; // added to store sensor data

void setup() {
  Serial.begin(9600);
  Wire.begin();
  initMPU(); // calling the boot-up function
}

void initMPU() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B); // sleep mode address
  Wire.write(0x00); // hex to start sensor
  
  Wire.write(0x1B); // calibration address
  Wire.write(0x00); // hex for +/- 250 range
  Wire.endTransmission();
}

void readGyro() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x43); // GYRO_XOUT_H
  Wire.endTransmission(false);
  
  Wire.requestFrom(MPU_ADDR, 6);
  
  // reading data from registers
  if (Wire.available() >= 6) {
    Wire.read(); Wire.read(); // skip X
    Wire.read(); Wire.read(); // skip Y
    gyroZ = (Wire.read() << 8) | Wire.read(); // read Z
  }
}

void displayRotation(float rot) {
  Serial.println(rot); // simple print for debug
}

void loop() {
  readGyro();
  
  //converting to degrees/second
  float gyroRate = gyroZ / 131.0;
  
  //calculating time elapsed
  unsigned long now = millis();
  float dt = (now - lastTime) / 1000.0;
  
  //math to get total rotation
  rotationZ += gyroRate * dt;
  
  displayRotation(rotationZ);
  lastTime = now;
  delay(10);
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
