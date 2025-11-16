
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <TinyWireM.h>
#include <TinyWireM.h>

#define LED_PIN 1
#define SENSOR_PIN A3
#define BUTTON 4
#define LP5810_ADDR 0x50

int val = 0;

void setup(){
  TinyWireM.begin();
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(LED_PIN,OUTPUT);
  pinMode(SENSOR_PIN,INPUT);
  digitalWrite(LED_PIN,HIGH);

  
  leddriver_w(0x020,0x0f);
  leddriver_w(0x030,0xbf);
  leddriver_w(0x031,0xbf);
  leddriver_w(0x032,0xbf);
  leddriver_w(0x033,0xbf);
  leddriver_w(0x040,0xff);
  leddriver_w(0x041,0xff);
  leddriver_w(0x042,0xff);
  leddriver_w(0x043,0xff);
  leddriver_w(0x010,0x55);
}


void loop(){
  if (digitalRead(BUTTON) == LOW){
    digitalWrite(LED_PIN,!digitalRead(LED_PIN));
    delay(500);
  }
  delay(1000);
//  TinyWireM.beginTransmission(0x50);
//  TinyWireM.send(0x00);
//  TinyWireM.send(0x01);
//  TinyWireM.endTransmission();
//  digitalWrite(LED_PIN,HIGH);
//  leddriver_w(0x000,0x01);
//  leddriver_w(0x00d,0x0b);
//  leddriver_w(0x010,0x55);
//  data_pulse(leddriver_r(0x300));
//  digitalWrite(LED_PIN,LOW);
  delay(1000);
}

void data_pulse(uint8_t inpt){
  digitalWrite(LED_PIN,0);
  delay(500);
  for (int i=0;i<8;i++){
    digitalWrite(LED_PIN,HIGH);
    delay(50);
    digitalWrite(LED_PIN,LOW);
    delay(50);
    if ((inpt>>i)&0b1){
      digitalWrite(LED_PIN,HIGH);
    }
    delay(500);
    digitalWrite(LED_PIN,LOW);
    delay(125);
  }
}

void pulse(int inpt){
  digitalWrite(LED_PIN,0);
  delay(500);
  for (int i=0;i<inpt;i++){
    digitalWrite(LED_PIN,HIGH);
    delay(500);
    digitalWrite(LED_PIN,LOW);
    delay(500);
  }
}

void leddriver_w(uint32_t in_addr,uint8_t val){
  TinyWireM.beginTransmission(LP5810_ADDR|((in_addr>>7)&0b110));
  TinyWireM.send(uint8_t(in_addr&0xFF));
  TinyWireM.send(val);
  TinyWireM.endTransmission();
}

uint8_t leddriver_r(uint32_t in_addr){
  TinyWireM.beginTransmission(LP5810_ADDR|((in_addr>>7)&0b110)|0b1);
  TinyWireM.send(uint8_t(in_addr&0xFF));
  TinyWireM.endTransmission();
  return(TinyWireM.read());
}
