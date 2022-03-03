#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
String str;

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Started");
}

void loop()
{
    if (Serial.available() > 0)
    {
        str = Serial.readString();
        lcd.setCursor(0, 0);
        lcd.print(str);
    }
}