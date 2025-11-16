////
//#include <TinyWireM.h>
//
//#define OLED_ADDR 0x3C
//#define IMU_ADDR 0b1101000
//#define BUTTON 4
//#define LED_PIN 1
//#define SENSOR A3
//
//void setup() {
//  TinyWireM.begin(); // Initialize I2C as master
//  
//  // Basic display initialization commands (same as before)
//  TinyWireM.beginTransmission(OLED_ADDR);
//  TinyWireM.write(0x00);
//  TinyWireM.write(0xAE); // Display OFF
//  TinyWireM.write(0xD5);
//  TinyWireM.write(0x80);
//  TinyWireM.write(0xA8);
//  TinyWireM.write(0x3F);
//  TinyWireM.write(0xD3);
//  TinyWireM.write(0x00);
//  TinyWireM.write(0x40);
//  TinyWireM.write(0x8D);
//  TinyWireM.write(0x14);
//  TinyWireM.write(0x20); // Set Memory Addressing Mode
//  TinyWireM.write(0x10); // 00 = Horizontal Addressing Mode
//  TinyWireM.write(0xA1);
//  TinyWireM.write(0xC8);
//  TinyWireM.write(0xDA);
//  TinyWireM.write(0x12);
//  TinyWireM.endTransmission();
//  TinyWireM.beginTransmission(OLED_ADDR);
//  TinyWireM.write(0x00);
//  TinyWireM.write(0x81);
//  TinyWireM.write(0x7F);
//  TinyWireM.write(0xD9);
//  TinyWireM.write(0x22);
//  TinyWireM.write(0xDB);
//  TinyWireM.write(0x40);
//  TinyWireM.write(0xA4);
//  TinyWireM.write(0xA6);
//  TinyWireM.write(0xAF); // Display ON
//  TinyWireM.endTransmission();
//  delay(500);
//  TinyWireM.beginTransmission(IMU_ADDR);
//  TinyWireM.write(0x6B);
//  TinyWireM.write(0x80);
//  TinyWireM.endTransmission();
//  delay(500);
//  TinyWireM.beginTransmission(IMU_ADDR);
//  TinyWireM.write(0x6B);
//  TinyWireM.write(0x00);
//  TinyWireM.endTransmission();
//  delay(500);
//  
//  randomSeed(1);
//  // Clear the display's memory
//  pinMode(BUTTON,INPUT_PULLUP);
//  pinMode(LED_PIN,OUTPUT);
//  digitalWrite(LED_PIN,HIGH);
//  delay(500);
//  digitalWrite(LED_PIN,LOW);
//  delay(250);
//  digitalWrite(LED_PIN,HIGH);
//  
//  clearDisplay();
//  // Draw something simple, like a rectangle
////  drawRectangle();
//}
//
//int8_t px;
//int8_t py;
//uint8_t x;
//uint8_t y;
//int8_t vx;
//int8_t vy;
//
//char dir;
//uint16_t cntr = 1;
//uint8_t whoami = 0;
//void loop() {
//  // Loop can be empty
//  if (digitalRead(BUTTON) == LOW){
////    delay(500);
//    TinyWireM.beginTransmission(IMU_ADDR);
//    TinyWireM.write(0x6B);
//    TinyWireM.endTransmission();
//    TinyWireM.begin();
//    TinyWireM.requestFrom(IMU_ADDR,1);
//    while (TinyWireM.available()){
//      whoami = TinyWireM.read();
//    }
//    TinyWireM.end();
//    digitalWrite(LED_PIN,LOW);
//    delay(500);
//    TinyWireM.beginTransmission(IMU_ADDR);
//    TinyWireM.write(0x3B);
//    TinyWireM.endTransmission();
//    TinyWireM.begin();
//    TinyWireM.requestFrom(IMU_ADDR,14);
//    while (TinyWireM.available()){
//      whoami = TinyWireM.read();
//    }
//    TinyWireM.end();
//    delay(500);
//    digitalWrite(LED_PIN,HIGH);
//  }
////  TinyWireM.beginTransmission(IMU_ADDR);
////  TinyWireM.write(0x3B);
////  TinyWireM.endTransmission();
////  TinyWireM.begin();
////  TinyWireM.requestFrom(IMU_ADDR,4);
////  px = (TinyWireM.read()<<8)+TinyWireM.read();
////  py = (TinyWireM.read()<<8)+TinyWireM.read();
////  TinyWireM.end();
//  
//  if (x == 0 or y == 0 or x == 127 or y == 63){
//    if (x == 127 or x == 0){
//      if (x == 0){
//        x = 126;
//      } else {
//        x = 1;
//      }
//    }
//    if (y == 63 or y == 0){
//      if (y == 0){
//        y = 62;
//      } else {
//        y = 1;
//      }
//    }
//  } else {
//    dir = random(2);
//    if (random(2)){
//      if (dir) {
//        vx++;
//      } else {
//        vx--;
//      }
//    } else {
//      if (dir) {
//        vy++;
//      } else {
//        vy--;
//      }
//    }
//  }
//  px = px + (vx>>1);
//  py = py + (vy>>1);
//
//  if (px < 0){
//    x = (px+127);
//  } else {
//    x = px;
//  }
//
//  if (py < 0){
//    y = (py+127)>>1;
//  } else {
//    y = py >> 1;
//  }
//  
//  DrawDot(x,y);
//  
//  if (cntr % 5000 == 0){
//    cntr = 0;
//    clearDisplay();
//    px = 64;
//    py = 32;
//    vx = 0;
//    vy = 0;
//  }
//  cntr++;
//}
//
//void DrawDot(int inptx, int inpty){
//  setCursor(inptx,inpty >> 3);
//  TinyWireM.beginTransmission(OLED_ADDR);
//  TinyWireM.write(0x40);
//  TinyWireM.write(1 << (inpty%8));
//  TinyWireM.endTransmission();
//}
//
//// Function to clear the entire display
//void clearDisplay() {
//  for (uint8_t page = 0; page < 8; page++) {
//    for (uint8_t col = 0; col < 8; col++) {
//      setCursor(col*16, page);
//      TinyWireM.beginTransmission(OLED_ADDR);
//      TinyWireM.write(0x40); // Co-command byte for data
//      for (uint8_t i = 0; i < 16; i++) {
//        TinyWireM.write(0x00); // Write 0s to turn off all pixels
//      }
//      TinyWireM.endTransmission();
//    }
//  }
//}
////
//// Function to set the cursor position
//void setCursor(uint8_t column, uint8_t page) {
//  TinyWireM.beginTransmission(OLED_ADDR);
//  TinyWireM.write(0x00); // Co-command byte
//  TinyWireM.write(0xB0 + page); // Set page address
//  TinyWireM.write(0x00 + (column & 0x0F)); // Set lower column address
//  TinyWireM.write(0x10 + ((column >> 4) & 0x0F)); // Set upper column address
//  TinyWireM.endTransmission();
//}
//
//// Function to draw a simple rectangle
//void drawRectangle() {
//  uint8_t rectangle_width = 32;
////  uint8_t rectangle_height = 8;
//  uint8_t start_col = 12; // Center the rectangle on the display
//  uint8_t start_page = 5;
//  
//  // Draw the rectangle, one page at a time
////  setCursor(start_col, start_page);
//  TinyWireM.beginTransmission(OLED_ADDR);
//  TinyWireM.write(0x40); // Co-command byte for data
//  for (uint8_t i = 0; i < rectangle_width; i++) {
//    TinyWireM.write(0xFF); // Write a full byte of "on" pixels
//  }
//  TinyWireM.endTransmission();
//}


//////////////////////////////////////////////////////////////////////////////////////////////
//
//#include <avr/io.h>
//#include <avr/interrupt.h>
////#include <TinyWireM.h>
//#include <TinyWireS.h>
//
//
//#define BUTTON 4
//#define LED_PIN 1
//#define SENSOR A3
//
//char SLAVE_ADDR = 0x24;
//volatile uint8_t blink_cnt;
//volatile bool blink_active;
//
//uint8_t val;
//uint16_t blink_timer;
//
//void sendVal(){
//  TinyWireS.write(val); 
//}
//
//void setup() {
//  TinyWireS.begin(SLAVE_ADDR);
//  TinyWireS.onRequest(sendVal);
//  pinMode(SENSOR,INPUT);
//  pinMode(BUTTON,INPUT_PULLUP);
//  pinMode(LED_PIN,OUTPUT);
//  digitalWrite(LED_PIN,HIGH);
//  delay(500);
//  digitalWrite(LED_PIN,LOW);
//  delay(250);
//  digitalWrite(LED_PIN,HIGH);
//   
//   // === Configure Timer1 for an interrupt ===
//  
//  // Clear Timer/Counter1 Control Register
//  TCCR1 = 0;
//  
//  // Set Timer1 to CTC (Clear Timer on Compare Match) mode.
//  // This mode resets the timer when it matches the value in OCR1C.
//  TCCR1 |= (1 << CTC1);
//
//  // Set the prescaler to 256. This slows down the timer clock.
//  // Timer clock = (System Clock) / 256 = 8MHz / 256 = 31250 Hz.
//  TCCR1 |= (1 << CS13);
//
//  // Set the compare match value (OCR1C).
//  // This determines the interrupt frequency:
//  // Interrupt frequency = Timer Clock / (OCR1C + 1)
//  // For a 200ms interval (5Hz), we need OCR1C = 6249:
//  // 5 = 31250 / (OCR1C + 1) => OCR1C = 6249.
//  OCR1C = 6249;
//
//  // Enable Timer1 Compare Match A interrupt.
//  TIMSK |= (1 << OCIE1A);
//
//  // Enable global interrupts.
//  sei();
//}
//
//void loop() {
//  if (digitalRead(BUTTON) == LOW){
//    val = analogRead(SENSOR);
//    digitalWrite(LED_PIN,LOW);
//    delay(500);
//  }
//  
//}
//
//// The Interrupt Service Routine (ISR) for Timer1 Compare Match A.
//// This function is automatically called by the hardware every 200ms.
//ISR(TIMER1_COMPA_vect){
//  digitalWrite(LED_PIN,!digitalRead(LED_PIN));
////    if (blink_active){
////      if (blink_cnt < 5){
////        blink_cnt=blink_cnt+1;
////      } else {
////        blink_cnt = 0;
////        blink_active = 0;
////        digitalWrite(LED_PIN,!digitalRead(LED_PIN));
////      }
////    }
//}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <TinyWireM.h>
#include <TinyWireS.h>

#define LED_PIN 1
#define SENSOR_PIN A3
#define BUTTON 4

void setup(){
  TinyWireS.begin(0x20);
  TinyWireS.onRequest(readSensor);
  TinyWireS.onReceive(setSens);
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(LED_PIN,OUTPUT);
  pinMode(SENSOR_PIN,INPUT);
  digitalWrite(LED_PIN,HIGH);
}

uint16_t val=0;
uint16_t val_prev=0;
uint16_t diff;
unsigned long tm1=micros();
unsigned long tm2;
uint16_t sensitivity = 1;
unsigned long period;
uint16_t cntr = 0;
uint16_t vth_p = 500;
uint16_t vth_n = 300;

bool bus_val = 0;

void loop(){

//  digitalWrite(LED_PIN,!digitalRead(LED_PIN));
//  delay(50);
  if (digitalRead(BUTTON) == LOW){
    digitalWrite(LED_PIN,!digitalRead(LED_PIN));
    delay(500);
  }
  
  val = analogRead(SENSOR_PIN);

  if (val > vth_p){
    bus_val = 1;
  } else if (val < vth_n){
    bus_val = 0;
  }

  if (bus_val != val_prev){
    period = micros()-tm1;
    tm1 = micros();
    val_prev = bus_val;
  }
  
}

void setSens(uint8_t numbytes){
  if (numbytes > 1){
    sensitivity = (TinyWireS.read()<<8)|TinyWireS.read();
  } else {
    sensitivity = TinyWireS.read();
  }
}

void readSensor(){
//  TinyWireS.write(sensitivity>>8);
//  TinyWireS.write(sensitivity);
  TinyWireS.write(val>>8);
  TinyWireS.write(val);
//  TinyWireS.write(period>>24);
//  TinyWireS.write(period>>16);
//  TinyWireS.write(period>>8);
//  TinyWireS.write(period);
//  TinyWireS.write(cntr>>8);
//  TinyWireS.write(cntr);
  
//  TinyWireS.write(temp>>8);
//  TinyWireS.write(temp & 0xFF);
}
