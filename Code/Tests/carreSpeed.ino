#include <AccelStepper.h>

// Define Constants

// Connections to A4988
const int dirPin1 = 2;  // Direction
const int stepPin1 = 3; // Step

const int dirPin2 = 4;
const int stepPin2 = 5;

// Motor steps per rotation
const int STEPS_PER_REV = 210;

// AccelStepper
const int MOTOR_INTERFACE_TYPE = 1;
AccelStepper stepper1(MOTOR_INTERFACE_TYPE, stepPin1, dirPin1);
AccelStepper stepper2(MOTOR_INTERFACE_TYPE, stepPin2, dirPin2);

// Functions
void bothMoveTo(float position1, float position2)
{
    stepper1.moveTo(stepper1.currentPosition() + position1);
    stepper2.moveTo(stepper2.currentPosition() + position2);
    while (stepper1.currentPosition() != stepper1.targetPosition() or stepper2.currentPosition() != stepper2.targetPosition())
    {
        stepper1.setSpeed(500);
        stepper1.runSpeedToPosition();

        stepper2.setSpeed(500);
        stepper2.runSpeedToPosition();

        Serial.print(stepper1.currentPosition());
        Serial.print(" -> ");
        Serial.print(stepper1.targetPosition());
        Serial.print("\t");
        Serial.print(stepper2.currentPosition());
        Serial.print(" -> ");
        Serial.println(stepper2.targetPosition());
    }
}

void setup()
{
    Serial.begin(9600);

    // Setup the pins as Outputs
    pinMode(stepPin1, OUTPUT);
    pinMode(dirPin1, OUTPUT);

    pinMode(stepPin2, OUTPUT);
    pinMode(dirPin2, OUTPUT);

    // Configure steppers
    stepper1.setMaxSpeed(1000);
    stepper2.setMaxSpeed(1000);
    // stepper1.setAcceleration(10000);
}
void loop()
{

    // ================= UP =================
    bothMoveTo(-200, 200);
    delay(1000);

    // ================= DOWN =================
    bothMoveTo(-200, -200);
    delay(1000);

    // ================= UP =================
    bothMoveTo(200, -200);
    delay(1000);

    // ================= DOWN =================

    bothMoveTo(200, 200);
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
    Serial.print("Current Position: ");
    Serial.print(stepper1.currentPosition());
    Serial.print(" & ");
    Serial.print(stepper2.currentPosition());

    Serial.print("\tMove To: ");
    Serial.print(stepper1.targetPosition());
    Serial.print(" & ");
    Serial.print(stepper2.targetPosition());

    Serial.print("\tSpeed : ");
    Serial.print(stepper1.speed());
    Serial.print(" & ");
    Serial.println(stepper2.speed());
}