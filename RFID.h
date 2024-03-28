
#include <SPI.h>
#include <MFRC522.h>

#define RST 9
#define SS 53

MFRC522 *mfrc522;

class RFID
{
public:
  static void setup()
  {
    SPI.begin();
    mfrc522 = new MFRC522(SS, RST);
    mfrc522->PCD_Init();
    Serial.println(F("Read UID on a MIFARE PICC:")); 
  }

  static void loop()
  {
    if(!mfrc522->PICC_IsNewCardPresent()) {
    goto FuncEnd;
    }
    if(!mfrc522->PICC_ReadCardSerial()) {
    goto FuncEnd;
    }
    Serial.println(F("**Card Detected:**"));
    mfrc522->PICC_DumpDetailsToSerial(&(mfrc522->uid));
    mfrc522->PICC_HaltA();
    mfrc522->PCD_StopCrypto1();
    FuncEnd:;
  }

};