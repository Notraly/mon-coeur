#include <Arduino.h>
// led1 = I ; led2 = coeur ; led3 = U ;
const byte PIN_LED1 = 6, PIN_LED2 = 5, PIN_LED3 = 3, PIN_PR = A7, PIN_BOUTON = 8, PIN_CHECK = 10, PIN_WARNING = 11;
int typeMethod = 1;


void setup() {
	// put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_LED1, OUTPUT);
	pinMode(PIN_LED2, OUTPUT);
	pinMode(PIN_LED3, OUTPUT);
	pinMode(PIN_BOUTON,INPUT_PULLUP);
}

void clearLed(){
	digitalWrite(PIN_LED1, LOW);
	digitalWrite(PIN_LED2, LOW);
	digitalWrite(PIN_LED3, LOW);
}

void affichageLeds(byte PIN, byte intensite, long t){
	analogWrite(PIN, intensite);
	delay(t);
	analogWrite(PIN, 0);
}
void leds1(){
	affichageLeds(PIN_LED1,30,500);
	affichageLeds(PIN_LED2,127,750);
	affichageLeds(PIN_LED3,30,500);
}
void leds2(){
  analogWrite(PIN_LED1, 30);
	analogWrite(PIN_LED2, 127);
	analogWrite(PIN_LED3, 30);
  delay(500);
}

void button(){
	int etatButton = digitalRead(PIN_BOUTON);

  if (etatButton == LOW) { // Bouton enfoncé
    digitalWrite(PIN_CHECK, HIGH);
    digitalWrite(PIN_WARNING, LOW);
    if (typeMethod == 0){
      typeMethod = 1;
    }else{
      typeMethod = 0;
    }
  }else{
    digitalWrite(PIN_WARNING, HIGH);
    digitalWrite(PIN_CHECK, LOW);
  }
}

void lightUpLeds(){
	int val = analogRead(PIN_PR);
  long t = millis();
  button();
  Serial.print(val);
  Serial.print("\t");
  Serial.print(typeMethod);
	if (val < 300 ) {
		if (typeMethod == 1) {
      Serial.print("\tif\tif");
      leds1();
    }else{
      Serial.print("\tif\telse");
      leds2();
    }
	}else{
    Serial.print("\telse");
		clearLed();
	}
  Serial.print("\t");
  Serial.print(millis()-t);
  Serial.print("\t");
  Serial.print(millis()/1000);
  Serial.println();
}


void loop() {
// START LOOP
	lightUpLeds();
// END LOOP
}
