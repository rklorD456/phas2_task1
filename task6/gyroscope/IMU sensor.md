# IMU sensor

# Introduction

This code for use of an MPU-6050 sensor to retrieve the **Yaw angle** along the z-axis 

---

# Questions

- The recommended **cutoff frequency** is 260Hz based on Programmable Low Pass Filter Response Range in embedded sensor
- The complementary filter is used with MPU-6050 sensor as it can be a union of two different filters: a high-pass filter for the gyroscope and a low-pass filter for the accelerometer.