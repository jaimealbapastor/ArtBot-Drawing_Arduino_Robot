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
  this->_dir1 = dirPin1;
  this->_step1 = stepPin1;
  this->_dir2 = dirPin2;
  this->_step2 = stepPin2;

  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(stepPin2, OUTPUT);

  this->_stepper1 = AccelStepper(motorInterfaceType, this->_step1, this->_dir1);
  this->_stepper2 = AccelStepper(motorInterfaceType, this->_step2, this->_dir2);

  this->_stepper1.setSpeed(100); // in steps per second
  this->_stepper2.setSpeed(100);

  // #### Pen state ####
  this->_currentDirection = 0;
  this->_x = 0;
  this->_y = 0;

}

String Pen::testMotor1(int steps) {

  //this->_stepper1.move(steps);
  return String(this->_dir1);
}

void Pen::testMotor2(int steps) {
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

int Pen::lol() {
  return 123;
}
