#include<Wire.h>

//IMU sensor
float  prevtime, actual_time;
float currenttime = 0;
float Z_angle , Z_error, YAW;


void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(0x68);                 //the slave address
  Wire.write(0x6B);                             // starting register
  Wire.write(0);                                // wakes up the MPU-6050
  Wire.endTransmission();
  Wire.beginTransmission(0x68);                 //set full scale range
  Wire.write(0x1B);                            //We want to write to the GYRO_CONFIG register
  Wire.write(0x10);                            //Set the register bits for +/- 1000deg/s full scale range
  Wire.endTransmission();
  delay(100);
  for (int i = 0; i < 1000; i++) {             //set the reference
    Wire.beginTransmission(0x68);
    Wire.write(0x47);                         //GYRO_ZOUT first register
    Wire.endTransmission(false);
    Wire.requestFrom(0x68, 2);                //test for YAW angle
    Z_angle = Wire.read() << 8 | Wire.read(); //shift left and sum
    Z_error = Z_error + (Z_angle / 32.8);     //32.8 is the gyroscope’s sensitivity per LSB for +/- 1000deg/s full scale range
    if (i == 999)
    {
      Z_error = Z_error / 1000;               //average value for error
    }
  }
}


void loop() {
  prevtime = currenttime;
  currenttime = millis();
  actual_time = (currenttime - prevtime) / 1000;          //set elapsed time as (second)
  Wire.beginTransmission(0x68);
  Wire.write(0x45);                         //GYRO_YOUT first register
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 2);                //ask for YAW angle
  Z_angle = Wire.read() << 8 | Wire.read(); //shift left and sum
  Z_angle = (Z_angle / 32.8) - Z_error;     //actual rate but we want the YAW angle
  YAW = YAW + Z_angle * actual_time;
  Serial.print("YAW: ");
  Serial.println(YAW);
}
