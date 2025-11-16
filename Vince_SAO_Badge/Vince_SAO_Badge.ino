
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <TinyWireM.h>
#include <TinyWireS.h>

#define LED_PIN 1
#define SENSOR_PIN A3
#define BUTTON 4

void setup(){
  TinyWireS.begin(0x20);
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(LED_PIN,OUTPUT);
  pinMode(SENSOR_PIN,INPUT);
  digitalWrite(LED_PIN,HIGH);
}


void loop(){
  if (digitalRead(BUTTON) == LOW){
    digitalWrite(LED_PIN,!digitalRead(LED_PIN));
    delay(500);
  }
  
}
