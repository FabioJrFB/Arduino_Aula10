#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h>

#define pino_trigger 4
#define pino_echo 5

LiquidCrystal_I2C lcd(0x27,16,2);
Ultrasonic ultrasonic(pino_trigger, pino_echo);

int x = A0;
int y = A1;
int clickz = 2;

void setup() {
  lcd.init();
  
  pinMode (x, INPUT);
  pinMode (y, INPUT);
  pinMode (clickz, INPUT);
  Serial.begin (9600);

}
void loop() {
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  lcd.setBacklight(HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distancia em cm: ");
  lcd.setCursor(0,1);
  lcd.print(cmMsec);
  delay (250);

  if (analogRead (x > 0 && x <= 511)){
    Serial.println ("Para baixo");
  }

   if (analogRead (y > 0 && y <= 511)){
    Serial.println ("Para esquerda");
  }

   if (analogRead (x > 511 && x <= 1023)){
    Serial.println ("Para cima");
  }

   if (analogRead (y > 511 && y <= 1023)){
    Serial.println ("Para direita");
  }

  if (digitalRead (clickz == LOW)){
    Serial.println ("Botao pressionado");
  }
  delay (1000);

}
