#include <Arduino.h>
// led1 = I ; led2 = coeur ; led3 = U ;
const byte PIN_LED1 = 50, PIN_LED2 = 40, PIN_LED3 = 30;


void setup() {
    // put your setup code here, to run once:
pinMode(PIN_LED1, OUTPUT);
pinMode(PIN_LED2, OUTPUT);
pinMode(PIN_LED3, OUTPUT);
}

void clearLed(){
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, LOW);
  digitalWrite(PIN_LED3, LOW);
}

void affichageLeds(byte PIN, long t){
  digitalWrite(PIN, HIGH);
  delay(t);
  digitalWrite(PIN, LOW);
}
void leds(){
    affichageLeds(PIN_LED1,500);
    affichageLeds(PIN_LED2,1000);
    affichageLeds(PIN_LED3,500);
}

void loop() {
// START LOOP
leds();
// END LOOP
}
