
#define PWMA 11
#define AIN2 3
#define AIN1 2
#define BIN1 5
#define BIN2 6
#define PWMB 12

/**
 * static class used for handling motor-related utilities
 * remember to call initialize() when first time using this class
 */

class motor
{
public:
  static void initialize()
  {
    digitalWrite(PWMA, HIGH);
    digitalWrite(PWMB, HIGH);
  }

  static void run(int error)
  { 
    //adjusting error
    if (error > 0)
    {
        leftAdjustedSpeed = clamp(leftSpeed - error);
        rightAdjustedSpeed = clamp(rightSpeed + error/2);
    }
    else if (error < 0)
    {
        leftAdjustedSpeed = clamp(leftSpeed - error/2);
        rightAdjustedSpeed = clamp(rightSpeed + error);
    }
    else
    {
      leftAdjustedSpeed = clamp(leftSpeed);
      rightAdjustedSpeed = clamp(rightSpeed);
    }

    //left motor
    if (leftAdjustedSpeed > 0)
    {
      analogWrite(AIN2, 0);
      analogWrite(AIN1, leftAdjustedSpeed);
    }
    else
    {
      analogWrite(AIN2, -leftAdjustedSpeed);
      analogWrite(AIN1, 0);
    }

    //right motor
    if (rightAdjustedSpeed > 0)
    {
      analogWrite(BIN1, 0);
      analogWrite(BIN2, rightAdjustedSpeed);
    }
    else
    {
      analogWrite(BIN1, 0);
      analogWrite(BIN2, -rightAdjustedSpeed);
    }
  }

  static void stop()
  {
    analogWrite(AIN1, 0);
    analogWrite(AIN2, 0);
    analogWrite(BIN1, 0);
    analogWrite(BIN2, 0);
  }

  static void logSpeed()
  {
    Serial.print(leftAdjustedSpeed);
    Serial.print(' ');
    Serial.print(rightAdjustedSpeed);
    Serial.println();
  }

  static int clamp(int value)
  {
    if (value < -255) return -255;
    if (value > 255) return 255;
    return value;
  }


private:
  static int leftSpeed, rightSpeed;
  static int leftAdjustedSpeed, rightAdjustedSpeed;
};

