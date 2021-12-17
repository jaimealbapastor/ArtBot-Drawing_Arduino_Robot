/*
    StepperMotor.h - Library for stepper motor mouvement
    Created by Jaime Alba Pastor, December 16, 2021.
*/

#include "Arduino.h"
#include "StepperMotor.h"
#include <AccelStepper.h>

#define motorInterfaceType 1

StepperMotor::StepperMotor(int dirPin, int stepPin)
{
    _dir = dirPin;
    _step = stepPin;

    pinMode(dirPin,OUTPUT);
    pinMode(stepPin, OUTPUT);
    
    AccelStepper _steper = AccelStepper(motorInterfaceType, _step,_dir);
}

void Morse::dot()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);  
}

void Morse::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}