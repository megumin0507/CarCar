
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
  pinMode(SA1, INPUT);
  pinMode(SA2, INPUT);
  pinMode(SA3, INPUT);
  pinMode(SA4, INPUT);
  pinMode(SA5, INPUT);
  Serial.begin(9600);
}

void loop()
{
  //motor test
  static motorHandler& MotorHandler = motorHandler::get();
  MotorHandler.initialize();
  MotorHandler.moveForward(3000);
  MotorHandler.moveBackward(3000);
  MotorHandler.leftTurn(3000);
  MotorHandler.rightTurn(3000);
  MotorHandler.stop();

  //sensor test
  sensorHandler::get().log();

  delay(1000);
}
