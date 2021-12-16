#include <AccelStepper.h>

#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1

AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
  stepper.setMaxSpeed(1000); // in steps per second
}

void loop() { 
  stepper.setCurrentPosition(0);

  // Run the motor forward at 200 steps/second until the motor reaches 400 steps (2 revolutions):
  while(stepper.currentPosition() != 400)
  {
    stepper.setSpeed(200);
    stepper.runSpeed();
  }

  delay(1000);

  stepper.setCurrentPosition(0);

  // Run the motor backwards at 600 steps/second until the motor reaches -200 steps (1 revolution):
  while(stepper.currentPosition() != -200) 
  {
    stepper.setSpeed(-600);
    stepper.runSpeed();
  }

  delay(1000);

  stepper.setCurrentPosition(0);

  // Run the motor forward at 400 steps/second until the motor reaches 600 steps (3 revolutions):
  while(stepper.currentPosition() != 600)
  {
    stepper.setSpeed(400);
    stepper.runSpeed();
  }

  delay(3000);
}