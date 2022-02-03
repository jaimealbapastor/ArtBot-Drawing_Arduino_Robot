/*
    StepperMotor.h - Library for stepper motor mouvement
    Created by Jaime Alba Pastor, December 16, 2021.
*/

#include "Pen.h"

#define motorInterfaceType 1
#define stepsPerRev 200
#define cmPerRev 200

Pen::Pen() : _lcd(2, 4, 5, 6, 7, 8) {}

Pen::Pen(int dirPin1, int stepPin1, int dirPin2, int stepPin2)
    : _lcd(2, 4, 5, 6, 7, 8) {
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

  // #### LCD ####
  _lcdexists = false;
}

void Pen::lcdbegin(int rs, int enable, int D4, int D5, int D6, int D7) {
  _lcdexists = true;
  _lcd = LiquidCrystal(rs, enable, D4, D5, D6, D7);
  _lcd.begin(16, 2);
  _lcd.print("Initialized");
}

void Pen::moveX(int steps) {
  _stepper1.move(steps);
  _stepper2.move(steps);

  if (_lcdexists) {
    String s = String(steps);
    _lcd.clear();
    _lcd.setCursor(0, 0);
    _lcd.print(String("X : " + s));
    _lcd.setCursor(0, 1);
    _lcd.print(String("Y : 0"));
  }
}

void Pen::moveY(int steps) {
  _stepper1.move(steps);
  _stepper2.move(-steps);
  if (_lcdexists) {
    String s = String(steps);
    _lcd.clear();
    _lcd.setCursor(0, 0);
    _lcd.print(String("X : 0"));
    _lcd.setCursor(0, 1);
    _lcd.print(String("Y : " + s));
  }
}

void Pen::forward(int steps) {
  _stepper1.setCurrentPosition(0);
  _stepper1.setCurrentPosition(0);
}

int Pen::lol() { return 123; }