
#define SA1 32 // SA stands for sensor analog
#define SA2 34
#define SA3 36
#define SA4 38
#define SA5 40

/*
 ** signleton used for handling sensor-related utilities
 */

 class sensorHandle
 {
public:
  static sensorHandle& get() { return s_instance; }

  byte read1() { return analogRead(SA1); }
  byte read2() { return analogRead(SA2); }
  byte read3() { return analogRead(SA3); }
  byte read4() { return analogRead(SA4); }
  byte read5() { return analogRead(SA5); }

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
