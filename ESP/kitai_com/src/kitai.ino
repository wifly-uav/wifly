#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Servo.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#include <SPI.h>

//#define DEBUG
#define sensor

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

int com_flag = 0;
int command[8] = {0};
uint8_t data[11];
uint8_t broadcastAddress[6];

unsigned long lastTime = 0; 
unsigned long recvTime = 0;  
unsigned long Ti = 0;
unsigned long loopTi = 0;
unsigned long timerDelay = 20;  // send readings timer
unsigned long watchdogtime = 100;  // timer

double w,x,y,z = 0;

double old_y = 0;
double d_y = 0;
double old_d_y = 0;
double dd_y = 0;

int i = 0;

void led_onoff(int i);
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus);

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac_addr, uint8_t *data, uint8_t len) {
  digitalWrite(led, HIGH);
  if(com_flag == 0){
    char macStr[18];
    snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X",
        mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
    broadcastAddress[0] = mac_addr[0];
    broadcastAddress[1] = mac_addr[1];
    broadcastAddress[2] = mac_addr[2];
    broadcastAddress[3] = mac_addr[3];
    broadcastAddress[4] = mac_addr[4];
    broadcastAddress[5] = mac_addr[5];
    com_flag = 1;
  }else{
    if(mac_addr[5] == broadcastAddress[5]){
      #ifdef DEBUG_RCV
        Serial.println();
        //Serial.printf("Last Packet Recv from: %s\n", macStr);
        Serial.printf("Last Packet Recv Data(%d): ", len);
      #endif
      for (i = 0; i < len; ++i) {
        command[i] = data[i];
        #ifdef DEBUG_RCV
          Serial.print(data[i]);
          Serial.print(" ");
        #endif
      }
      digitalWrite(led, LOW);
      recvTime = millis();
    }
  }
}

void setup() {
  #ifdef DEBUG
    Serial.begin(115200);
    Serial.println();
  #endif

  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(led, OUTPUT);
  analogWriteFreq(PWM_FREQ);
  analogWriteRange(PWM_RANGE);

  digitalWrite(led, HIGH);
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
 
   #ifdef sensor
    if(!bno.begin()){
      /* There was a problem detecting the BNO055 ... check your connections */
      #ifdef DEBUG
        Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
      #endif
      digitalWrite(led, HIGH);
      while(1){
        led_onoff(1);
        analogWrite(pwm1, PWM_RANGE);
        analogWrite(pwm2, PWM_RANGE);
      }
    }
  #endif
  digitalWrite(led, LOW);

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

  esp_now_register_recv_cb(OnDataRecv);

  while(!com_flag){
    led_onoff(2);
    analogWrite(pwm1, PWM_RANGE);
    analogWrite(pwm2, PWM_RANGE);
  }
  
  // Register peer
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

float mapfloat(float x, long in_min, long in_max, long out_min, long out_max)
{
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
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
    //imu::Quaternion quaternion = bno.getQuat();
  #endif

  Ti = millis();
  loopTi = Ti - lastTime;
  if (loopTi > timerDelay) {
    // Set values to send
    data[0] = command[0];
    data[1] = command[1];
    //data[2] = command[2];
    //data[3] = command[3];
    #ifdef sensor
      if(euler.z()>=0){
        data[5] = euler.z(); //pitch
        data[6] = 0;
      }else{
        data[5] = 0;
        data[6] = abs(euler.z());
      }
      if(abs(euler.z())<90){ //yaw
        if(euler.y()>=0){
          data[7] = abs(euler.y());
          data[8] = 0;
        }else{
          data[7] = 0;
          data[8] = abs(euler.y());
        }
      }else{
        if(euler.y()>0){
          data[7] = abs(180-abs(euler.y()));
          data[8] = 0;
        }else{
          data[7] = 0;
          data[8] = abs(abs(euler.y())-180);
        }
      }
      d_y = (euler.y()-old_y)*1000/loopTi;
      if(d_y>0){
        data[9] = int(d_y);
        data[10] = 0;
      }else{
        data[9] = 0;
        data[10] = int(-1*d_y);
      }
      old_y = euler.y();
      dd_y = (d_y-old_d_y)/(loopTi*0.01)
      if(dd_y>0){
        data[2] = int(dd_y);
        data[3] = 0;
      }else{
        data[2] = 0;
        data[3] = int(-1*dd_y);
      }
      old_d_y = d_y;
      /*
      if(euler.x()<180){
        data[9] = euler.x(); //roll
        data[10] = 0;
      }else{
        data[9] = 180;
        data[10] = euler.x()-180;
      }
      */
      /*
      data[5] = (quaternion.w()+1)*100;
      data[6] = (quaternion.x()+1)*100;
      data[7] = (quaternion.y()+1)*100;
      data[8] = (quaternion.z()+1)*100;
      */
    #else
      data[5] = 0;
      data[6] = 0;
      data[7] = 0;
    #endif
    data[4] = loopTi;
    #ifdef DEBUG
      #ifdef sensor
      //Serial.print("y:");
      //Serial.print(euler.y());
      //Serial.print("z:");
      /*
      Serial.print(quaternion.w());
      Serial.print(" , ");
      Serial.print(quaternion.x());
      Serial.print(" , ");
      Serial.print(quaternion.y());
      Serial.print(" , ");
      Serial.print(quaternion.z());
      Serial.print(" , ");
      */
      Serial.print(euler.x());
      Serial.print(" , ");
      Serial.print(euler.z());
      Serial.print(" , ");
      if(abs(euler.z())<90){
        Serial.print(euler.y());
      }else{
        if(euler.y()>0){
          Serial.print(180-abs(euler.y()));
        }else{
          Serial.print(abs(euler.y())-180);
        }
      }
      Serial.println();
      #endif
    #endif

    esp_now_send(broadcastAddress, (uint8_t *) &data, sizeof(data));
    lastTime = millis();
  }
  /*
  if ((Ti - recvTime) > watchdogtime){
    digitalWrite(led, HIGH);
    analogWrite(pwm1, 0);
    analogWrite(pwm2, 0);
  }
  */
  analogWrite(pwm1, command[0]);
  analogWrite(pwm2, command[1]);
  ladder.write(min(max(0,command[2]),180));
  cog.write(min(max(0,command[3]),180));
  
  delay(5);
}

void led_onoff(int i){
  for(int j = 0; j<i; j++){
        digitalWrite(led, HIGH);
        delay(100);
        digitalWrite(led, LOW);
        delay(100);
  }
  delay(600);
}

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