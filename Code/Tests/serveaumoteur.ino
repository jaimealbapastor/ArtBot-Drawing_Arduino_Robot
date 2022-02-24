
#include <Servo.h>


Servo monServomoteur;

void setup() {
    
  
  monServomoteur.attach(9);
}

void loop() {

  // Fait bouger le bras de 0° à 180°
  for (int position = 0; position <= 90; position++) {
    monServomoteur.write(position);
    delay(15);
  }
  
  // Fait bouger le bras de 180° à 10°
  for (int position = 90; position >= 0; position--) {
    monServomoteur.write(position);
    delay(15);
  }
}
