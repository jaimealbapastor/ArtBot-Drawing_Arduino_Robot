#include <Servo.h>

// =========== Constants ===========
// STEPPER MOTOR
const int dirPin1 = 2;  // Direction
const int stepPin1 = 3; // Step

const int dirPin2 = 4;
const int stepPin2 = 5;

const int STEPS_PER_REV = 210;

// SERVO MOTOR
const int servoPin = 6;
const int DOWN = 46;
const int UP = DOWN - 3;
Servo servo;

// =========== oneStep ===========
void oneStep(int pin)
{
    digitalWrite(pin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(pin, LOW);
    delayMicroseconds(1000);
}

// =========== setDirections ===========
void setDirections(int direction1, int direction2)
{
    digitalWrite(dirPin1, direction1);
    digitalWrite(dirPin2, direction2);
}

// =========== Move ===========
void move(int steps1, int steps2)
{
    int bigNbSteps;
    int littleNbSteps;

    int bigPin;
    int littlePin;

    if (steps1 <= steps2)
    {
        bigNbSteps = steps2;
        littleNbSteps = steps1;

        bigPin = stepPin2;
        littlePin = stepPin1;
    }
    else
    {
        bigNbSteps = steps1;
        littleNbSteps = steps2;

        bigPin = stepPin1;
        littlePin = stepPin2;
    }

    // const int quotient = bigNbSteps / littleNbSteps;
    // const int rest = bigNbSteps % littleNbSteps;

    int pos1 = 0;
    int pos2 = 0;

    for (int i = 0; i < littleNbSteps; i++)
    {
        oneStep(littlePin);

        // for (int j = 0; j < quotient; j++) {
        oneStep(bigPin);
        //}
    }
    // for (int j = 0; j < rest ; j++) {
    //   oneStep(bigPin);
    // }
}
// =========== SETUP ===========
void setup()
{
    Serial.begin(9600);

    // STEPPER MOTOR
    pinMode(stepPin1, OUTPUT);
    pinMode(dirPin1, OUTPUT);

    pinMode(stepPin2, OUTPUT);
    pinMode(dirPin2, OUTPUT);

    // SERVO MOTOR
    servo.attach(servoPin);
}
// =========== LOOP ===========
void loop()
{

    servo.write(UP);
    delay(2000);
    servo.write(DOWN);
    delay(2000);

    // ================= RIGHT =================
    setDirections(HIGH, HIGH);
    move(300, 300);
    delay(1000);

    // ================= DOWN =================
    setDirections(LOW, HIGH);
    move(300, 300);
    delay(1000);

    // ================= LEFT =================
    setDirections(LOW, LOW);
    move(300, 300);
    delay(1000);

    // ================= UP =================
    setDirections(HIGH, LOW);
    move(300, 300);
    delay(1000);

    /*
      if (stepper1.currentPosition() == 200) {
      stepper1.moveTo(0);

      } else if (stepper1.currentPosition() == 0) {
      stepper1.moveTo(0);
      }
      stepper1.setSpeed(200);
      stepper1.runSpeedToPosition();
    */
}