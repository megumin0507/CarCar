
#define SD1 32 // SD stands for sensor digital
#define SD2 34
#define SD3 36
#define SD4 38
#define SD5 40

/**
 * static class used for handling sensor-related utilities
 */

 class sensor
 {
public:

  static void setup()
  {
    pinMode(SD1, INPUT);
    pinMode(SD2, INPUT);
    pinMode(SD3, INPUT);
    pinMode(SD4, INPUT);
    pinMode(SD5, INPUT);
  }

  static byte read1() { return digitalRead(SD1); }
  static byte read2() { return digitalRead(SD2); }
  static byte read3() { return digitalRead(SD3); }
  static byte read4() { return digitalRead(SD4); }
  static byte read5() { return digitalRead(SD5); }

  static void log()
  {
    Serial.print(read1());
    Serial.print(' ');
    Serial.print(read2());
    Serial.print(' ');
    Serial.print(read3());
    Serial.print(' ');
    Serial.print(read4());
    Serial.print(' ');
    Serial.print(read5());
    Serial.println();
  }
 };
