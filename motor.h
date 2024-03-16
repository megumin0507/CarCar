
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

  void moveForward(int duration)
  {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    delay(duration);
  }

  void moveBackward(int duration)
  {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    delay(duration);
  }

  void leftTurn(int duration)
  {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    delay(duration);
  }

  void rightTurn(int duration)
  {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    delay(duration);
  }

  void stop()
  {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
  }

private:
  motorHandle() {}
  static motorHandle s_instance;
};

