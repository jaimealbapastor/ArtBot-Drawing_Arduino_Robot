/*
    StepperMotor.h - Library for stepper motor mouvement
    Created by Jaime Alba Pastor, December 16, 2021.
*/

#ifndef Pen_h
#define Pen_h

#include <Arduino.h>
#include <AccelStepper.h>
#include <LiquidCrystal.h>

class Pen {
public:
  // Initialize
  Pen();
  Pen(int dirPin1, int stepPin1, int dirPin2, int stepPin2);
  void lcdbegin(int rs, int enable, int D4, int D5, int D6, int D7);

  // #### Motors ####
  void moveX(int steps);
  void moveY(int steps);
  void forward(int steps);
  int lol();

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

  // #### LCD ####
  bool _lcdexists;
  LiquidCrystal _lcd;
};

#endif