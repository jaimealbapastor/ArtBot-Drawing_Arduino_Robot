#include <Arduino.h>
#include "Pen.h"

// VARIABLE DECLARATION

Pen pen(8, 9, 10, 11);

void setup() {
  pen.lcdbegin(2, 3, 4, 5, 6, 7);
  pen.moveX(101);
}

void loop() {}