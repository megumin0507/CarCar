
#include "motor.h"
#include "sensor.h"
#include "RFID.h"
#include "bluetooth.h"

int motor::leftSpeed = 90;
int motor::rightSpeed = 90;
int motor::leftAdjustedSpeed = 0;
int motor::rightAdjustedSpeed = 0;

int getError(int l2, int l1, int m, int r1, int r2) {
  if (l2 + l1 + r1 + r2 == 0 || m) return 0;
  return (l2 * 90 + l1 * 60 + r1 * (-60) + r2 * (-90)) / (l2 + l1 + r1 + r2);
}

void setup() {
  motor::setup();
  sensor::setup();
  RFID::setup();
  bluetooth::setup();
  Serial.begin(9600);
}

void loop() {
  //motor test
  // motor::initialize();
  // byte l2 = sensor::read1(), l1 = sensor::read2(), m = sensor::read3(), r1 = sensor::read4(), r2 = sensor::read5();
  // motor::run(getError(l2, l1, m, r1, r2));

  //sensor test
  // sensor::log();

  //RFID test
  //RFID::loop();

  //bluetooth test
  bluetooth::loop();

  delay(100);
}
