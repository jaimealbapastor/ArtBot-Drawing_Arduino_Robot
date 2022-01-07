/*
    StepperMotor.h - Library for stepper motor mouvement
    Created by Jaime Alba Pastor, December 16, 2021.
*/
#ifndef Pen_h
#define Pen_h

#include "Arduino.h"
#include <AccelStepper>

class Pen {
public:
  Pen();
  void forward();

private:
  // #### Motors ####
  int _dir1;
  int _step1;
  int _dir2;
  int _step2;
  AccelStepper _stepper1;
  AccelStepper _stepper2;

  // #### Pen state ####
  float _currentDirection;
  int _x;
  int _y;

  // #### Functions ####
  void moveX();
  void moveY();
};

#endif