#include <Arduino.h>
#include "Pen.h"

// VARIABLE DECLARATION

Pen pen(8, 9, 2, 3);

void setup() { 
    Serial.begin(9600);
}

void loop() {
    int a = Serial.read();
    if (a!=0){
        pen.testMotor1(a);
        delay(2000);
        pen.testMotor2(a);
        delay(2000);
        pen.testMotor1(-a);
        delay(2000);
        pen.testMotor2(-a);
        a = 0;
    }
}