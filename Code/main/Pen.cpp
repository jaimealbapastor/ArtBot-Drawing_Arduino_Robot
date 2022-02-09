/*
    StepperMotor.h - Library for stepper motor mouvement
    Created by Jaime Alba Pastor, December 16, 2021.
*/

#include "Pen.h"

#define motorInterfaceType 1
#define stepsPerRev 200
#define cmPerRev 200

Pen::Pen() {}

Pen::Pen(int dirPin1, int stepPin1, int dirPin2, int stepPin2) {
  // #### Motors ####
  _dir1 = dirPin1;
  _step1 = stepPin1;
  _dir2 = dirPin2;
  _step2 = stepPin2;

  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(stepPin2, OUTPUT);

  _stepper1 = AccelStepper(motorInterfaceType, _step1, _dir1);
  _stepper2 = AccelStepper(motorInterfaceType, _step2, _dir2);

  _stepper1.setSpeed(100); // in steps per second
  _stepper2.setSpeed(100);

  // #### Pen state ####
  _currentDirection = 0;
  _x = 0;
  _y = 0;

}

void Pen::testMotor1(int steps){
  _stepper1.move(steps);
}

void Pen::testMotor2(int steps){
  _stepper2.move(steps);
}

void Pen::moveX(int steps) {
  _stepper1.move(steps);
  _stepper2.move(steps);


}

void Pen::moveY(int steps) {
  _stepper1.move(steps);
  _stepper2.move(-steps);
}

void Pen::forward(int steps) {
  _stepper1.setCurrentPosition(0);
  _stepper1.setCurrentPosition(0);
}

int Pen::lol() { return 123; }