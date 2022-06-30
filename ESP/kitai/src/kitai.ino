#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Servo.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#include <SPI.h>

//#define DEBUG
//#define sensor

#define PWM_FREQ 1000
#define PWM_RANGE 255

#ifdef sensor
  Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);
#endif

const int pwm1 = 12;
const int pwm2 = 13;
const int pwmch = 0;
const int cog_pin = 16;
const int ladder_pin = 14;
const int led = 15;

Servo cog;
Servo ladder;

int command[7] = {0};
uint8_t data[7];

// REPLACE WITH RECEIVER MAC Address
//uint8_t broadcastAddress[] = {0xC8, 0x2B, 0x96, 0xB9, 0x17, 0xC4};
uint8_t broadcastAddress[] = {0x8C, 0x4B, 0x14, 0x16, 0x63, 0x0C}; //A
//uint8_t broadcastAddress[] = {0xC8, 0x2B, 0x96, 0xB9, 0x69, 0x54}; //B

unsigned long lastTime = 0; 
unsigned long recvTime = 0;  
unsigned long Ti = 0;
unsigned long loopTi = 0;
unsigned long timerDelay = 20;  // send readings timer
unsigned long watchdogtime = 100;  // timer

int i = 0;

// Callback when data is sent
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  #ifdef DEBUG_SENT
    Serial.println();
    Serial.print("Last Packet Send Status: ");
  if (sendStatus == 0){
    Serial.println("Delivery success");
  }
  else{
    Serial.println("Delivery fail");
  }
  #endif
}

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac_addr, uint8_t *data, uint8_t len) {
  digitalWrite(led, HIGH);
  //char macStr[18];
  //snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X",
  //    mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  #ifdef DEBUG
    Serial.println();
    //Serial.printf("Last Packet Recv from: %s\n", macStr);
    Serial.printf("Last Packet Recv Data(%d): ", len);
  #endif
  for (i = 0; i < len; ++i) {
    command[i] = data[i];
    #ifdef DEBUG
      Serial.print(data[i]);
      Serial.print(" ");
    #endif
  }
  digitalWrite(led, LOW);
  recvTime = millis();
}

void setup() {
  Serial.begin(115200);
  Serial.println();

  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(led, OUTPUT);
  analogWriteFreq(PWM_FREQ);
  analogWriteRange(PWM_RANGE);

  digitalWrite(led, LOW);
  analogWrite(pwm1, PWM_RANGE);
  analogWrite(pwm2, PWM_RANGE);
  
  cog.attach(cog_pin,900,1900);
  ladder.attach(ladder_pin,900,1900);
  
  cog.write(0);
  ladder.write(0);
  
  #ifdef DEBUG
    Serial.println("-");
    Serial.println("start");

    Serial.print("ESP8266 Board MAC Address:  ");
    Serial.println(WiFi.macAddress());
  #endif
 
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    #ifdef DEBUG
      Serial.println("Error initializing ESP-NOW");
    #endif
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  //esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);

  esp_now_register_recv_cb(OnDataRecv);

  #ifdef sensor
    if(!bno.begin()){
      /* There was a problem detecting the BNO055 ... check your connections */
      #ifdef DEBUG
        Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
      #endif
      digitalWrite(led, HIGH);
      while(1);
    }
  #endif
  digitalWrite(led, LOW);
}

float mapfloat(float x, long in_min, long in_max, long out_min, long out_max)
{
  //return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
  return (float)(x - in_min) * (out_max - out_min) *0.003921568627451 + out_min; // 1/255
}
 
void loop() {

  #ifdef sensor
    // Possible vector values can be:
    // - VECTOR_ACCELEROMETER - m/s^2
    // - VECTOR_MAGNETOMETER  - uT
    // - VECTOR_GYROSCOPE     - rad/s
    // - VECTOR_EULER         - degrees
    // - VECTOR_LINEARACCEL   - m/s^2
    // - VECTOR_GRAVITY       - m/s^2
    imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  #endif

  Ti = millis();
  loopTi = Ti - lastTime;
  if (loopTi > timerDelay) {
    // Set values to send
    data[0] = command[0];
    data[1] = command[1];
    data[2] = command[2];
    data[3] = command[3];
    #ifdef sensor
      data[4] = (int)mapfloat(euler.y(), -90, 90, 0, 255);
      data[5] = (int)mapfloat(euler.z(), -180, 180, 0, 255);
    #else
      data[4] = 0;
      data[5] = 0;
    #endif
    data[6] = loopTi;
    #ifdef DEBUG
      //Serial.print("y:");
      //Serial.print(euler.y());
      Serial.print("z:");
      Serial.println(data[4]);
    #endif

    esp_now_send(broadcastAddress, (uint8_t *) &data, sizeof(data));
    lastTime = millis();
  }
  
  if ((Ti - recvTime) > watchdogtime){
    digitalWrite(led, HIGH);
    analogWrite(pwm1, 255);
    analogWrite(pwm2, 255);
  }

  analogWrite(pwm1, command[0]);
  analogWrite(pwm2, command[1]);
  ladder.write(command[2]);
  cog.write(command[3]);
  
  //delay(50);
}