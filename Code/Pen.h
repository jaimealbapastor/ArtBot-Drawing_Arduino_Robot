/*
    StepperMotor.h - Library for stepper motor mouvement
    Created by Jaime Alba Pastor, December 16, 2021.
*/
#ifndef Pen_h
#define Pen_h

#include "Arduino.h"
#include <AccelStepper>

class Pen
{
  public:
    Pen();
    void moveSteps();
  private:
    int _dir;
    int _step;
    AccelStepper _stepper1;
    AccelStepper _stepper2;
};

#endif