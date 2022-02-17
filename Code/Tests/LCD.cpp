#include <Arduino.h>
#include <LiquidCrystal.h>

// VARIABLE DECLARATION
const int rs = 2; // Register Select
const int enable = 3;
const int D4 = 4;
const int D5 = 5;
const int D6 = 6;
const int D7 = 7;

LiquidCrystal lcd(rs, enable, D4, D5, D6, D7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Bonjour");
  lcd.setCursor(0, 1);
  lcd.print("Ca va");
}

void loop() {}