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

// COORDINATES
int xCoor = 0;
int yCoor = 0;

int pair = 1;

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
// Perform a uniform frecuence depending on the ration between both steps
{
    int bigNbSteps;
    int bigPin;
    int littleNbSteps;
    int littlePin;

    if (steps1 <= steps2)
    {
        bigNbSteps = steps2;
        bigPin = stepPin2;
        littleNbSteps = steps1;
        littlePin = stepPin1;
    }
    else
    {
        bigNbSteps = steps1;
        bigPin = stepPin1;
        littleNbSteps = steps2;
        littlePin = stepPin2;
    }

    const int quotient = bigNbSteps / littleNbSteps;
    const int rest = bigNbSteps % littleNbSteps;

    for (int i = 0; i < littleNbSteps; i++)
    {
        oneStep(littlePin);
        for (int j = 0; j < quotient; j++)
        {
            oneStep(bigPin);
        }
    }
    for (int j = 0; j < rest; j++)
    {
        oneStep(bigPin);
    }
}

// =========== directionOf ===========
int directionOf(int x)
{
    if (x < 0)
    {
        return 0;
    }
    return 1;
}

// =========== absVal ===========
int absVal(int x)
{
    if (x < 0)
    {
        return x * (-1);
    }
    return x;
}

// =========== moveRel ===========
void moveRel(int x, int y)
{
    int nbSteps1 = 2 * (x + y);
    int nbSteps2 = 2 * (x - y);

    setDirections(directionOf(nbSteps1), directionOf(nbSteps2));
    move(absVal(nbSteps1), absVal(nbSteps2));
}

// =========== moveAbs ===========
void moveAbs(int x, int y)
{
    moveRel(x - xCoor, y - yCoor);
    xCoor += x;
    yCoor += y;
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
    moveRel(0, 100);
    delay(1000);

    servo.write(UP);
    delay(1000);
    servo.write(DOWN);
    delay(100);

    // ================= DOWN =================
    moveRel(-100, 0);
    delay(1000);

    servo.write(UP);
    delay(1000);
    servo.write(DOWN);
    delay(100);

    // ================= LEFT =================
    moveRel(0, -100);
    delay(1000);

    servo.write(UP);
    delay(1000);
    servo.write(DOWN);
    delay(100);

    // ================= UP =================
    moveRel(100, 0);
    delay(1000);

    servo.write(UP);
    moveRel(-250, 0);

    /*
      if (stepper1.currentPosition() == 200) {
      stepper1.moveRel(0);

      } else if (stepper1.currentPosition() == 0) {
      stepper1.moveRel(0);
      }
      stepper1.setSpeed(200);
      stepper1.runSpeedToPosition();
    */
}