#include "Arduino.h"
#include <AccelStepper.h>

/*
 * BLINKER CLASS DEFINITION
 */
class Pen {
private:
  // #### Motors ####
  const int motorInterfaceType = 1;
  const int stepsPerRev = 200;
  const int cmPerRev = 200;

  int _dir1;
  int _step1;
  int _dir2;
  int _step2;

  AccelStepper _stepper1;
  AccelStepper _stepper2;

  // Status
  double _direction;
  int _x;
  int _y;

public:
  Pen(int dirPin1, int stepPin1, int dirPin2, int stepPin2) {
    // #### Motors ####
    this->_dir1 = dirPin1;
    this->_step1 = stepPin1;
    this->_dir2 = dirPin2;
    this->_step2 = stepPin2;

    pinMode(dirPin1, OUTPUT);
    pinMode(stepPin1, OUTPUT);
    pinMode(dirPin2, OUTPUT);
    pinMode(stepPin2, OUTPUT);

    this->_stepper1 = AccelStepper(motorInterfaceType, _step1, _dir1);
    this->_stepper2 = AccelStepper(motorInterfaceType, _step2, _dir2);

    _stepper1.setSpeed(100); // in steps per second
    _stepper2.setSpeed(100);

    // #### Pen state ####
    double _direction = 0;
    int _x = 0;
    int _y = 0;
  }

  // Moves in x axe.
  void moveX(int steps) {
    _stepper1.move(steps);
    _stepper2.move(steps);
  }
  // Moves in y axe.
  void moveY(int steps) {
    _stepper1.move(steps);
    _stepper2.move(-steps);
  }

  void forward(int steps) {
    // void
  }
};

// ---------------------

Pen pen = Pen(2, 3, 4, 5);

void setup() {}

void loop() {
  pen.moveX(500);
  delay(2000);
}