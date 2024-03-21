
#define SD1 32 // SA stands for sensor digital
#define SD2 34
#define SD3 36
#define SD4 38
#define SD5 40

/*
 ** signleton used for handling sensor-related utilities
 */

 class sensorHandle
 {
public:
  static sensorHandle& get() { return s_instance; }

  byte read1() { return digitalRead(SD1); }
  byte read2() { return digitalRead(SD2); }
  byte read3() { return digitalRead(SD3); }
  byte read4() { return digitalRead(SD4); }
  byte read5() { return digitalRead(SD5); }

  void log()
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

private:
  sensorHandle() {}
  static sensorHandle s_instance;
 };
