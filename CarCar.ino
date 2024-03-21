
#include "motor.h"
#include "sensor.h"

int getError(int l2, int l1, int m, int r1, int r2)
{
  return l2*30 + l1*50 + r1*(-50) + r2*(-30);
}

void setup()
{
  pinMode(PWMA, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(SD1, INPUT);
  pinMode(SD2, INPUT);
  pinMode(SD3, INPUT);
  pinMode(SD4, INPUT);
  pinMode(SD5, INPUT);
  Serial.begin(9600);
}

void loop()
{
  //motor test
  static motorHandle& MotorHandle = motorHandle::get();
  MotorHandle.initialize();

  static sensorHandle& SensorHandle = sensorHandle::get();
  byte l2 = SensorHandle.read1(), l1 = SensorHandle.read2(), m = SensorHandle.read3(), r1 = SensorHandle.read4(), r2 = SensorHandle.read5();

  MotorHandle.run(getError(l2, l1, m, r1, r2));
  MotorHandle.logSpeed();

  //sensor test
  sensorHandle::get().log();

  delay(100);
}
