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
const int DOWN = 45;
const int UP = DOWN - 3;
Servo servo;

// COORDINATES
int xCoor = 0;
int yCoor = 0;

int counter = 10;
int starX[10] = {90, 140, 105, 120, 65, 20, 35, 0, 50, 65};
int starY[10] = {50, 55, 90, 140, 115, 140, 90, 55, 50, 0};

// =========== PARSER ===========

class Instruction
{
public:
    String command = "";
    float X = 0;
    float Y = 0;
    float Z = 0;
    float I = 0;
    float J = 0;
    float F = 0;

    Instruction(String str)
    {
        str += " ";
        int pos;
        String field;
        char firstChar;
        while ((pos = str.indexOf(" ")) != -1)
        {
            field = str.substring(0, pos);
            firstChar = field.charAt(0);

            if (firstChar == 'G')
            {
                this->command = field;
            }
            else if (firstChar == 'X')
            {
                this->X = field.substring(1).toFloat();
            }
            else if (firstChar == 'Y')
            {
                this->Y = field.substring(1).toFloat();
            }
            else if (firstChar == 'Z')
            {
                this->Z = field.substring(1).toFloat();
            }
            else if (firstChar == 'I')
            {
                this->I = field.substring(1).toFloat();
            }
            else if (firstChar == 'J')
            {
                this->J = field.substring(1).toFloat();
            }
            else if (firstChar == 'F')
            {
                this->F = field.substring(1).toFloat();
            }

            str.remove(0, pos + 1);
        }
    }

    String toString()
    {
        return this->command + " " +
               this->X + " " +
               this->Y + " " +
               this->Z + " " +
               this->I + " " +
               this->J + " " +
               this->F;
    }
};

// =========== oneStep ===========
void oneStep(int pin)
{
    digitalWrite(pin, HIGH);
    delayMicroseconds(500);
    digitalWrite(pin, LOW);
    delayMicroseconds(500);
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
        littleNbSteps = steps1 + 1;
        littlePin = stepPin1;
    }
    else
    {
        bigNbSteps = steps1;
        bigPin = stepPin1;
        littleNbSteps = steps2 + 1;
        littlePin = stepPin2;
    }

    const int quotient = bigNbSteps / littleNbSteps;
    const float rest = float(bigNbSteps % littleNbSteps) / littleNbSteps;
    float restCount = 0.0;

    Serial.print("big: ");
    Serial.print(bigNbSteps);
    Serial.print(" little: ");
    Serial.print(littleNbSteps);
    Serial.print(" quotient: ");
    Serial.print(quotient);
    Serial.print(" rest: ");
    Serial.println(rest);
    delay(2000);

    for (int i = 0; i < littleNbSteps; i++)
    {
        oneStep(littlePin);
        for (int j = 0; j < quotient; j++)
        {
            oneStep(bigPin);

            restCount += rest;
            if (restCount >= 1)
            {
                oneStep(bigPin);
                restCount -= 1;
            }
        }
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
    xCoor = x;
    yCoor = y;
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
    if (counter < 10)
    {
        moveAbs(starX[counter] * 8, starY[counter] * 8);

        servo.write(UP);
        delay(1000);
        servo.write(DOWN);
        delay(500);

        counter++;
    }
    if (counter >= 10)
    {
        counter = 0;
    }
}