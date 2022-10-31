
#include <esp_now.h>
#include <WiFi.h>

#include <SPI.h>
//#define DEBUG

unsigned long lastTime = 0;  
unsigned long timerDelay = 60;  // send readings timer
size_t data_pc_;
uint8_t data_pc[5] = {0};
int re_data[11] = {0};
double re_data_angle[3] = {0};
int eular[3] = {0};
char send_pc[40];
int left_pwm,right_pwm,servo_angle,cog_angle;
uint8_t data[5];

uint8_t address[][9] = {{0x8C, 0xCE, 0x4E, 0xEA, 0xB1, 0xC9},
                        {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0x60},
                        {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0x3D},
                        {0xB4, 0xE6, 0x2D, 0x2F, 0xA2, 0x22},
                        {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0xAC},
                        {0xB4, 0xE6, 0x2D, 0x2F, 0x95, 0x98},
                        {0xB4, 0xE6, 0x2D, 0x2F, 0x80, 0xA6},
                        {0xB4, 0xE6, 0x2D, 0x2F, 0xA3, 0x2D},
                        {0xB4, 0xE6, 0x2D, 0x2F, 0x95, 0x2A}
                        };
// REPLACE WITH RECEIVER MAC Address
uint8_t castAddress[6] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0x60};

const byte digits[] = {
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
};

esp_now_peer_info_t peerInfo;

//pin
//7seg
int sck = 18;
int latch = 5;
int sdi = 23;
int scroll_speed = 500;
int kitai_num = 0;
//controller
struct input{
  int stick_lr;
  int stick_ud;
  int slider_l;
  int slider_r;
  int switch_c;
  int switch_l;
  int switch_r;
  int led;
};
input pin;
input state;

void qu2eu(int eular[3], double quotanion[4]);
void onReceive(const uint8_t* mac_addr, const uint8_t* data, int data_len);
void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status);
void recieve_pc();

void setup() {

    pin.stick_lr = 34;
    pin.stick_ud = 35;
    pin.slider_l = 39;
    pin.slider_r = 36;
    pin.switch_c = 33;
    pin.switch_l = 4;
    pin.switch_r = 2;
    pin.led = 32;
    pinMode(pin.stick_lr, INPUT);
    pinMode(pin.stick_ud, INPUT);
    pinMode(pin.slider_l, INPUT);
    pinMode(pin.slider_r, INPUT);
    pinMode(pin.switch_c, INPUT_PULLUP);
    pinMode(pin.switch_l, INPUT_PULLUP);
    pinMode(pin.switch_r, INPUT_PULLUP);
    pinMode(pin.led, OUTPUT);
    pinMode(latch, OUTPUT);
    pinMode(sck, OUTPUT);
    pinMode(sdi, OUTPUT);
    SPI.begin();
    SPI.setBitOrder(LSBFIRST);
    SPI.setDataMode(0);

    Serial.begin(460800);    

    Serial.println(WiFi.macAddress());
    
    state.switch_c = digitalRead(pin.switch_c);


    while(state.switch_c){      
      //SPI
      kitai_num += 1;
      if(kitai_num == 9){
        kitai_num = 0;
      }
      digitalWrite(latch, 0);
      SPI.transfer (digits[kitai_num]);//10の桁 +1でドット表示
      digitalWrite(latch, 1);
      delay(scroll_speed);
      state.switch_c = digitalRead(pin.switch_c);
    }
    for(int i=0; i<6 ; i++){
      castAddress[i] = address[kitai_num][i];
    }
    digitalWrite(pin.led, HIGH);
    
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    if (esp_now_init() == ESP_OK) {
        //Serial.println("ESP-Now Init Success");
    }
    memcpy(peerInfo.peer_addr, address[kitai_num], 6);
    //memcpy(peerInfo.peer_addr, castAddress, 6);
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;
    
    // Add peer        
    if (esp_now_add_peer(&peerInfo) != ESP_OK){
      Serial.println("Failed to add peer");
      return;
    }
    
    //esp_now_register_send_cb(OnDataSent);
    esp_now_register_recv_cb(onReceive);
    
}

void loop() {
  
  state.switch_c = digitalRead(pin.switch_c);
  state.switch_l = digitalRead(pin.switch_l);
  state.switch_r = digitalRead(pin.switch_r);

  if ((millis() - lastTime) > timerDelay) {
    if(state.switch_l == 1){
      recieve_pc();
      for(int i=0;i<2;++i){
        data[i] = 254 - data_pc[i];
      }
      for(int i=2;i<4;++i){
        data[i] = data_pc[i];
      }
    }else{
          state.stick_lr = map(analogRead(pin.stick_lr),0,4096,0,255);
          state.stick_ud = map(analogRead(pin.stick_ud),0,4096,0,180);
          state.slider_l = map(analogRead(pin.slider_l),0,4096,0,255);
          state.slider_r = map(analogRead(pin.slider_r),0,4096,0,255);

          data[0] = state.slider_l;
          data[1] = state.slider_r;
          data[2] = state.stick_ud;
          data[3] = state.stick_ud;
    }
    
    if(data[0]>240){data[0] = 255;}
    if(data[1]>240){data[1] = 255;}

    #ifdef DEBUG
      Serial.print("lx:");
      Serial.print(state.stick_lr);
      Serial.print("ly:");
      Serial.print(state.stick_ud);
      Serial.print("sli_L:");
      Serial.print(state.slider_l);
      Serial.print("sli_R:");
      Serial.print(state.slider_r);
      Serial.print("swi_c:");
      Serial.print(state.switch_c);
      Serial.print("swi_l:");
      Serial.print(state.switch_l);
      Serial.print("swi_r:");
      Serial.print(state.switch_r);
      //Serial.print(data[0]);
      //Serial.print(data[1]);
      //Serial.print(data[2]);
      //Serial.print(data[3]);
      Serial.println();
      /*
      Serial.print("rx:");
      Serial.print(right_LR);
      Serial.print("ry:");
      Serial.print(right_UD);
      Serial.print("btnr:");
      Serial.print(btn_r);
      Serial.print("btnl");
      Serial.print(btn_l);
      Serial.println();
      */
    #endif

    //delay(10);

    // Send message via ESP-NOW
    esp_now_send(castAddress, (uint8_t *) &data, sizeof(data));
    //esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
    lastTime = millis();
  }
}

void qu2eu(int eular[3], double quotanion[4]){
  
  double w = quotanion[0];
  double x = quotanion[1];
  double y = quotanion[2];
  double z = quotanion[3];


  double sz = -(2 * x * y - 2 * z * w);  
  double a = asin(sz);
  int flag = cos(a) != 0;
  eular[0] = flag ? atan2(2 * y * z + 2 * x * w, 2 * w * w + 2 * y * y - 1)/PI*180 : atan2(-(2 * y * z - 2 * x * w), 2 * w * w + 2 * z * z - 1)/PI*180;
  eular[1] = flag ? atan2(2 * x * z + 2 * y * w, 2 * w * w + 2 * x * x - 1)/PI*180 : 0;
  eular[2] = a/PI*180;
}

void onReceive(const uint8_t* mac_addr, const uint8_t* data, int data_len) {
    char macStr[18];
    snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X",
        mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
    //Serial.println();
    //Serial.printf("ESP32\n");
    //Serial.printf("Last Packet Recv from: %s\n", macStr);
    //Serial.printf("Last Packet Recv Data(%d): ", data_len);
    //Serial.println();
    for (int i = 0; i < 5; i++) {
      re_data[i] = data[i];
      //Serial.print(re_data[i]);
      //Serial.print(",");
    }
    if(data[5] != 0){
      re_data[5] = data[5];
    }else{
      re_data[5] = -1*data[6];
    }
    if(data[7] != 0){
      re_data[6] = data[7];
    }else{
      re_data[6] = -1*data[8];
    }
    re_data[7] = data[9]+data[10];
    /*
    for(int i = 5; i<8; i++){
      Serial.print(re_data[i]);
      if(i!=7){
        Serial.print(",");
      }
    }
    */
   sprintf(send_pc, "%d,%d,%d,%d,%d,%d,%d,%d",re_data[0],re_data[1],re_data[2],re_data[3],re_data[4],re_data[5],re_data[6],re_data[7]);
   Serial.println(send_pc);
   Serial.flush();
}

void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status) {
  Serial.println();
  Serial.printf("ESP32\n");
  Serial.print("Last Packet Send Status: ");
  if (status == 0){
    Serial.println("Delivery success");
  }
  else{
    Serial.println("Delivery fail");
  }
}

void recieve_pc(){
  if(Serial.available()){
    if((int)Serial.read() == 255){
      data_pc_ = Serial.readBytesUntil('\n',data_pc,5);
    }
  }
}