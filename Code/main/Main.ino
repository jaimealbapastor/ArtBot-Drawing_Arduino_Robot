#include <Arduino.h>
#include "Pen.h"

// VARIABLE DECLARATION

Pen pen(8, 9, 2, 3);
String a;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready !");
}

void loop() {
  while (Serial.available() == 0) {}
  a = Serial.readString();
  Serial.println(a);

  if (a == "1") {
    Serial.println(pen.testMotor1(50));
    delay(2000);
  } else if (a == 50) {
    pen.testMotor2(50);
    delay(2000);
  } else if (a == "3") {
    pen.testMotor1(-50);
    delay(2000);
  } else if (a == "4") {
    pen.testMotor2(-50);
    delay(2000);

  }




}
