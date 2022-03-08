/*
  Stepper Motor Demonstration 4
  Stepper-Demo4.ino
  Demonstrates NEMA 17 Bipolar Stepper with A4988 Driver

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Define Constants

// Connections to A4988
const int dirPin = 2;  // Direction
const int stepPin = 3; // Step

const int dirPin2 = 4;
const int stepPin2 = 5;

// Motor steps per rotation
const int STEPS_PER_REV = 210;

void setup()
{

    // Setup the pins as Outputs
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);

    pinMode(stepPin2, OUTPUT);
    pinMode(dirPin2, OUTPUT);
}
void loop()
{

    // BOTH TOGETHER ===================================
    // Set motor direction clockwise
    digitalWrite(dirPin, HIGH);
    digitalWrite(dirPin2, HIGH);

    // Spin motor one rotation slowly
    for (int x = 0; x < STEPS_PER_REV * 2; x++)
    {
        digitalWrite(stepPin, HIGH);
        digitalWrite(stepPin2, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        digitalWrite(stepPin2, LOW);
        delayMicroseconds(1000);
    }

    delay(100);

    // SIDEWAYS ===================================
    digitalWrite(dirPin, HIGH);
    digitalWrite(dirPin2, LOW);

    // Spin motor one rotation slowly
    for (int x = 0; x < STEPS_PER_REV * 2; x++)
    {
        digitalWrite(stepPin, HIGH);
        digitalWrite(stepPin2, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        digitalWrite(stepPin2, LOW);
        delayMicroseconds(1000);
    }

    delay(100);

    // BOTH TOGETHER ==========================================
    // Set motor direction clockwise
    digitalWrite(dirPin, LOW);
    digitalWrite(dirPin2, LOW);

    // Spin motor one rotation slowly
    for (int x = 0; x < STEPS_PER_REV * 2; x++)
    {
        digitalWrite(stepPin, HIGH);
        digitalWrite(stepPin2, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        digitalWrite(stepPin2, LOW);
        delayMicroseconds(1000);
    }

    delay(100);

    // SIDEWAYS ===================================
    digitalWrite(dirPin, LOW);
    digitalWrite(dirPin2, HIGH);

    // Spin motor one rotation slowly
    for (int x = 0; x < STEPS_PER_REV * 2; x++)
    {
        digitalWrite(stepPin, HIGH);
        digitalWrite(stepPin2, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        digitalWrite(stepPin2, LOW);
        delayMicroseconds(1000);
    }

    delay(100);

    /*
    // Pause for one second
    delay(1000);

    // Set motor direction counterclockwise
    digitalWrite(dirPin,LOW);

    // Spin motor two rotations quickly
    for(int x = 0; x < (STEPS_PER_REV * 2); x++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(1000);
    } */

    // Pause for one second
    // delay(1000);
}