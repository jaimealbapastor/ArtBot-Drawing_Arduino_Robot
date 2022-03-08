#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
String str;

class Instruction
{
public:
    String command = "";
    float X = 0;
    float Y = 0;
    float Z = 0;
    float I = 0;
    float J = 0;
    float F = 0;

    Instruction(String str)
    {
        str += " ";
        int pos;
        String field;
        char firstChar;
        while ((pos = str.indexOf(" ")) != -1)
        {
            field = str.substring(0, pos);
            firstChar = field.charAt(0);

            if (firstChar == 'G')
            {
                this->command = field;
            }
            else if (firstChar == 'X')
            {
                this->X = field.substring(1).toFloat();
            }
            else if (firstChar == 'Y')
            {
                this->Y = field.substring(1).toFloat();
            }
            else if (firstChar == 'Z')
            {
                this->Z = field.substring(1).toFloat();
            }
            else if (firstChar == 'I')
            {
                this->I = field.substring(1).toFloat();
            }
            else if (firstChar == 'J')
            {
                this->J = field.substring(1).toFloat();
            }
            else if (firstChar == 'F')
            {
                this->F = field.substring(1).toFloat();
            }

            str.remove(0, pos + 1);
        }
    }

    String toString()
    {
        return this->command + " " +
               this->X + " " +
               this->Y + " " +
               this->Z + " " +
               this->I + " " +
               this->J + " " +
               this->F;
    }
};

void clear()
{
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
}

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Started");

    str = "G01 X42.234836 Y35.901313 Z-1.000000";

    Instruction inst(str);
    Serial.println(inst.toString());
}

void loop()
{

    /*
      if (Serial.available() > 0)
      {
       str = Serial.readString();
       clear();
       lcd.print(str);
      }
    */
}