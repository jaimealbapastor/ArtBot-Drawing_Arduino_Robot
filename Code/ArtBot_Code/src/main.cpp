#include <Arduino.h>
#include "Pen.h"

// VARIABLE DECLARATION

Pen pen(8, 9, 2, 3);

void setup() { pen.moveX(100); }

void loop() {}