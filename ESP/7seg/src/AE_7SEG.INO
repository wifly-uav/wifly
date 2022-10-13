//ARDUINO UNO
//AE-7SEG-BOARD * 2
//SCK D13
//LATCH D10
//SDI D11
#include<Wire.h>
#include<SPI.h>
int sck = 18;
int latch = 5;
int sdi = 23;
int scroll_speed = 500;
const byte digits[] = {
  /*
  0b11111100, // 0
  0b01100000, // 1
  0b11011010, // 2
  0b11110010, // 3
  0b01100110, // 4
  0b10110110, // 5
  0b10111110, // 6
  0b11100000, // 7
  0b11111110, // 8
  0b11110110, // 9
  */
  0b00111111,
  0b00000110,
  0b01011011,
  0b01001111,
  0b01100110,
  0b01101101,
  0b01111101,
  0b00000111,
  0b01111111,
  0b01101111,
    //下、右下、右上、上
};

void setup() {
  pinMode(latch, OUTPUT);
  pinMode(sck, OUTPUT);
  pinMode(sdi, OUTPUT);
  SPI.begin();
  //SPI.setBitOrder(LSBFIRST);
  SPI.setDataMode(0);
}

void loop() {
  for (int j = 0; j < 10; j ++) {//１０の桁
    for (int i = 0; i < 10; i ++) {//１の桁
      //SPI
      digitalWrite(latch, 0);
      SPI.transfer (digits[j]+1);//10の桁 +1でドット表示
      SPI.transfer (digits[i]);//1の桁
      digitalWrite(latch, 1);
      //
      delay(scroll_speed);
    }
  }
}

