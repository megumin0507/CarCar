
#include "motor.h"
#include "sensor.h"

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
  MotorHandle.moveForward(3000);
  MotorHandle.moveBackward(3000);
  MotorHandle.leftTurn(3000);
  MotorHandle.rightTurn(3000);
  MotorHandle.stop();

  //sensor test
  sensorHandle::get().log();

  delay(1000);
}
