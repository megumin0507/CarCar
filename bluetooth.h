
#include <SoftwareSerial.h>

#define RXD 18
#define TXD 19

SoftwareSerial BT(RXD, TXD);

class bluetooth
{
public:
  static void setup()
  {
    Serial.println("BT is ready!");
    BT.begin(9600);
  }

  static void loop()
  {
    if (Serial.available()) BT.write(Serial.read());

    if (BT.available()) Serial.write(BT.read());
  }
};
