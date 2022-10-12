#include <ESP32Servo.h>

#define MAX_SIGNAL 2000  //PWMä¿¡å·ã«ãããæå¤§ã®ãã«ã¹å¹[ãã¤ã¯ã­ç§]
#define MIN_SIGNAL 1000  //PWMä¿¡å·ã«ãããæå°ã®ãã«ã¹å¹[ãã¤ã¯ã­ç§]
#define ESC_PIN 23  //ESCã¸ã®åºåãã³
int volume = 0;  //å¯å¤æµæã®å¤ãå¥ããå¤æ°
int volume_pin = 4;
char message[50];  //ã·ãªã¢ã«ã¢ãã¿ã¸è¡¨ç¤ºããæå­åãå¥ããå¤æ°

Servo esc;  //Servoãªãã¸ã§ã¯ããä½æããï¼ä»åã¯ESCã«PWMä¿¡å·ãéãã®ã§ï¼`esc`ã¨å½åãã¦ããï¼

void setup() {
  Serial.begin(115200);
  Serial.println("Program begin...");
  Serial.println("This program will calibrate the ESC.");
  Serial.println("Turn on power source, then wait 2 seconds and press any key.");
  
  while (!Serial.available());  //ã·ãªã¢ã«ãã¼ãã§ä½ãå¥åãããã¾ã§å¾ã¡ã¾ã
  Serial.read();

  esc.attach(ESC_PIN);  //ESCã¸ã®åºåãã³ãã¢ã¿ãããã¾ã
  Serial.println("Writing maximum output.");
  esc.writeMicroseconds(MAX_SIGNAL);  //ESCã¸æå¤§ã®ãã«ã¹å¹ãæç¤ºãã¾ã
  Serial.println("Wait 3 seconds.");
  delay(3000);
  Serial.println("Writing minimum output");
  esc.writeMicroseconds(MIN_SIGNAL);  //ESCã¸æå°ã®ãã«ã¹å¹ãæç¤ºãã¾ã
  Serial.println("Wait 3 seconds. Then motor starts");
  delay(3000);
}

void loop() {  
  volume = analogRead(volume_pin) / 2.0L;  //å¯å¤æµæã®å¤ã1.0ã§æãã¦å¤æ°volumeã«å¥ããï¼å¤ãèª¿æ´ãããå ´åã¯åçãå¤æ´ããï¼
  sprintf(message, "Pulse Width: %d micro sec", volume);  //ã·ãªã¢ã«ã¢ãã¿ã«è¡¨ç¤ºããã¡ãã»ã¼ã¸ãä½æ
  Serial.println(message);  //å¯å¤æµæã®å¤ãã·ãªã¢ã«ã¢ãã¿ã«è¡¨ç¤º
  esc.writeMicroseconds(volume);  // ãã«ã¹å¹ `volume` ã®PWMä¿¡å·ãéä¿¡ãã
  //ã¹ã­ããã«ãä¸­å¤®(1500)ã«æ»ãã¦ããã¹ã¿ã¼ã
}
