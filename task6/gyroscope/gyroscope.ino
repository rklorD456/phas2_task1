#include <Wire.h>

#define IMU_ADDR 0x68
#define GYRO_CONFIG 0x1B
#define GYRO_XOUT_H 0x42
#define PWR_MGMT_1 0x6B
#define GYRO_SCALE 2000

void MPU_init();
void MPU_GyroConfig();
void MPU_ReadGyro_XYZ();

int16_t gyro_X = 0,gyro_Y = 0,gyro_Z = 0;
float elapsedTime = 0, currentTime = 0, previousTime = 0;
float AngleYaw=0;



void setup()
{
    Wire.begin();
    Serial.begin(9600);
    MPU_init();
    MPU_GyroConfig(); //turn on gyro
}


void loop()
{
    MPU_ReadGyro_XYZ();
    previousTime = currentTime;
    currentTime = millis();
    elapsedTime = (currentTime - previousTime) / 1000;

    AngleYaw = AngleYaw + gyro_Z * elapsedTime;

    Serial.print("Yaw angle: ");
    Serial.println(AngleYaw);
    delay(10);
}

void MPU_init()
{
  //activate the MPU-6050
    Wire.beginTransmission(IMU_ADDR);
    Wire.write(PWR_MGMT_1);
    Wire.write(0x00);
    Wire.endTransmission();
}

void MPU_GyroConfig()
{
    Wire.beginTransmission(IMU_ADDR);
    Wire.write(GYRO_CONFIG);
    //set sacle range = +-1000 deg/s
    Wire.write(0x10);
    Wire.endTransmission();
}

void MPU_ReadGyro_XYZ()
{
    Wire.beginTransmission(IMU_ADDR);
    Wire.write(GYRO_XOUT_H);
    Wire.endTransmission();

    Wire.requestFrom(IMU_ADDR, 6);
    while(Wire.available() < 6);  // Wait until the all data available
    gyro_X = Wire.read() << 8 | Wire.read();
    gyro_Y = Wire.read() << 8 | Wire.read();
    gyro_Z = Wire.read() << 8 | Wire.read();

}