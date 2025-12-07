
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <TinyWireM.h>
#include <TinyWireM.h>

#define LED_PIN 1
#define SENSOR_PIN A3
#define BUTTON 4
#define LP5810_ADDR 0x50
#define LED0 0x40
#define LED1 0x41
#define LED2 0x42
#define LED3 0x43

int val = 0xff;
char tst;

void setup(){
  TinyWireM.begin();
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(LED_PIN,OUTPUT);
  pinMode(SENSOR_PIN,INPUT);
  digitalWrite(LED_PIN,LOW);
  
  leddriver_w(0x000,0x01);
  leddriver_w(0x00d,0x0b);
  leddriver_w(0x010,0x55);
  leddriver_w(0x020,0x0f);
  leddriver_w(0x030,0xbf);
  leddriver_w(0x031,0xbf);
  leddriver_w(0x032,0xbf);
  leddriver_w(0x033,0xbf);
  leddriver_w(0x040,0xff);
  leddriver_w(0x041,0xff);
  leddriver_w(0x042,0xff);
  leddriver_w(0x043,0xff);
  
}


void loop(){
  val = analogRead(SENSOR_PIN);
  while (!digitalRead(BUTTON)){
    nib_out(val>>8 & 0xf);
    digitalWrite(LED_PIN,HIGH);
    delay(1000);
    nib_out(val>>4 & 0xf);
    digitalWrite(LED_PIN,LOW);
    delay(1000);
    nib_out(val & 0xf);
    digitalWrite(LED_PIN,HIGH);
    delay(500);
    digitalWrite(LED_PIN,LOW);
    delay(500);
  }
//  if (digitalRead(LED_PIN)){
//    val = analogRead(SENSOR_PIN);
//    nib_out((val >> 4)&0xff);
//  } else {
//    nib_out(val&0xff);
//  }
//  digitalWrite(LED_PIN,!digitalRead(LED_PIN));
//  if (tst >= 0b1111){
//    tst = 0;
//  } else {
//    tst = (tst << 1)|0b1;
//  }
//  for (int i=0;i<4;i++){
//    leddriver_w(0x40+i,255*((tst>>i)&0b1));
//  }
//  val = val>>1;
//  leddriver_w(0x040,val);
//  leddriver_w(0x041,val);
//  leddriver_w(0x042,val);
//  leddriver_w(0x043,val);
//  if (val == 0){
//    val = 0xFF;
//  }
}

void all_off(){
  all_leds(0);
}

void all_on(){
  all_leds(255);
}

void all_leds(int inval){
  for (int i=0;i<4;i++){
    dim_led(i,inval);
  }
}

void led_off(char inpt_led){
  leddriver_w(0x40+constrain(inpt_led,0,3),0);
}

void led_on(char inpt_led){
  leddriver_w(0x40+constrain(inpt_led,0,3),255);
}

void nib_out(char inptnib){
  for (char i = 0;i<4;i++){
    leddriver_w(0x40+i,255*((inptnib>>(3-i))&0b1));
  }
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

void dim_led(char inpt_led,char inval){
  leddriver_w(0x40+constrain(inpt_led,0,3),inval);
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
