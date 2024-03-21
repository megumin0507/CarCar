
#define PWMA 11
#define AIN2 3
#define AIN1 2
#define BIN1 5
#define BIN2 6
#define PWMB 12

/**
 * singleton used for handling motor-related utilities
 * remember to call initialize() when first time using this class
 */

class motorHandle
{
public:
  static motorHandle& get() { return s_instance; }

  void initialize()
  {
    digitalWrite(PWMA, HIGH);
    digitalWrite(PWMB, HIGH);
  }

  void run(int error)
  { 
    //adjusting error
    if (error > 0)
    {
        leftAdjustedSpeed = clamp(leftSpeed - error*4);
        rightAdjustedSpeed = clamp(rightSpeed + error/2);
    }
    else if (error < 0)
    {
        leftAdjustedSpeed = clamp(leftSpeed - error/2);
        rightAdjustedSpeed = clamp(rightSpeed + error*4);
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

   void stop()
  {
    analogWrite(AIN1, 0);
    analogWrite(AIN2, 0);
    analogWrite(BIN1, 0);
    analogWrite(BIN2, 0);
  }

  void logSpeed()
  {
    Serial.print(leftAdjustedSpeed);
    Serial.print(' ');
    Serial.print(rightAdjustedSpeed);
    Serial.println();
  }

  int clamp(int value)
  {
    if (value < -255) return -255;
    if (value > 255) return 255;
    return value;
  }


private:
  motorHandle() {}
  static motorHandle s_instance;

  int leftSpeed = 130, rightSpeed = 150;
  int leftAdjustedSpeed = 130, rightAdjustedSpeed = 150;
};

motorHandle motorHandle::s_instance;

