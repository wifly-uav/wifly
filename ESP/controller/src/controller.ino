#include <esp_now.h>
#include <WiFi.h>

#include <SPI.h>
#define DEBUG

unsigned long lastTime = 0;  
unsigned long timerDelay = 60;  // send readings timer
size_t data_pc_;
uint8_t data_pc[5] = {0};

// REPLACE WITH RECEIVER MAC Address
//機体側のマイコンの番号にあったアドレスのみコメントアウトを外す。
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0x60}; //1
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0x3D}; //2
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0x95, 0xE4}; //3
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0xAC}; //4
uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0x95, 0x98}; //5
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA2, 0xBF};   //6

esp_now_peer_info_t peerInfo;

const int controller_num = 2; //1:A 2:B
//pin
int stick_lr;
int stick_ud;
int slider_l;
int slider_r;
int switch_1;
int switch_2;
int volume;

void onReceive(const uint8_t* mac_addr, const uint8_t* data, int data_len) {
    char macStr[18];
    snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X",
        mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
    //Serial.println();
    //Serial.printf("ESP32\n");
    //Serial.printf("Last Packet Recv from: %s\n", macStr);
    //Serial.printf("Last Packet Recv Data(%d): ", data_len);
    //Serial.println();
    /*
    for (int i = 0; i < data_len; i++) {
        if(i == 4){
          Serial.print(map(data[i], 0, 255, -90, 90));
        }else if(i == 5){
          Serial.print(map(data[i], 0, 255, -180, 180));
        }else{
          Serial.print(data[i]);
        }
        if(i != data_len-1){
          Serial.print(",");
        }
    }
    Serial.println();
    */
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

void setup() {

  switch(controller_num){
    case 1:
      stick_lr = 34;
      stick_ud = 35;
      slider_l = 33;
      slider_r = 32;
      switch_1 = 23;
      switch_2 = 13;
      volume = 39;
      break;        //忘れずに!
    case 2:
      stick_lr = 36;
      stick_ud = 39;
      slider_l = 33;
      slider_r = 32;
      switch_1 = 23;
      switch_2 = 13;
      volume = 39;
      break;
    }

    Serial.begin(460800);    
    
    pinMode(stick_lr, INPUT);
    pinMode(stick_ud, INPUT);
    pinMode(slider_l, INPUT);
    pinMode(slider_r, INPUT);
    pinMode(volume, INPUT);
    pinMode(switch_1, INPUT_PULLUP);
    pinMode(switch_2, INPUT_PULLUP);

    Serial.println(WiFi.macAddress());

    
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    if (esp_now_init() == ESP_OK) {
        //Serial.println("ESP-Now Init Success");
    }
      // Register peer
    memcpy(peerInfo.peer_addr, castAddress, 6);
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

int left_LR;
int left_UD;
int sli_L;
int sli_R;
int vol;

void loop() {
  
  int btn_L = digitalRead(switch_1);
  int btn_R = digitalRead(switch_2);

  if ((millis() - lastTime) > timerDelay) {
    uint8_t data[5];
    if(btn_L == 1){
      recieve_pc();
      for(int i=0;i<5;++i){
        data[i] = data_pc[i];
      }
    }else{  
    
      switch(controller_num){
        case 1:
          left_LR = map(analogRead(stick_lr),0,4096,0,255);
          left_UD = map(analogRead(stick_ud),0,4096,0,180);
          sli_L = map(analogRead(slider_l),0,4096,0,255);
          sli_R = map(analogRead(slider_r),0,4096,0,255);
          vol = map(analogRead(volume),0,4096,0,255);
          //btn_R = digitalRead(switch_2);

          if(left_LR<152 && left_LR>102){left_LR = 127;}
          if(left_UD<105 && left_UD>75){left_UD = 90;}

          data[0] = sli_L;
          data[1] = sli_R;
          data[2] = left_UD;
          data[3] = left_UD;
          data[4] = btn_R;
          break;
        
        case 2:
          left_LR = map(analogRead(stick_lr),0,4096,0,255); //揚力差
          left_UD = map(analogRead(stick_ud),0,4096,0,255); //割り当てなし
          sli_L = map(analogRead(slider_l),0,4096,0,180);   //尾翼サーボ
          sli_R = map(analogRead(slider_r),0,4096,0,255);   //羽ばたき出力
          //btn_L = digitalRead(switch_1);
          //vol = map(analogRead(volume),0,4096,0,255);
          btn_R = digitalRead(switch_2);

          //スライドボリューム左（尾翼）最小
          if(sli_L>170){sli_L = 180;}
          //スライドボリューム右最小
          if(sli_R>240){sli_R = 255;}
          //ジョイスティック左右中央
          if(left_LR<152 && left_LR>102){left_LR = 127;}
          //ジョイスティック上下中央
          if(left_UD<152 && left_UD>102){left_UD = 127;}

          /*
          int left_pwm = abs(sli_R - 255) - (left_LR - 127)/4;  //左（要確認）
          int right_pwm = abs(sli_R - 255) + (left_LR - 127)/4; //右（要確認）
          int servo_angle = abs(sli_L-180);                     //尾翼サーボ角
          */

          int left_pwm = max(0,sli_R - max(0, (left_LR - 127)/4 ));  //左（要確認）
          int right_pwm = max(0,sli_R - max(0, (127 - left_LR)/4)); //右（要確認）
          int servo_angle = sli_L;                   //尾翼サーボ角
          int cog_angle = 180*btn_R;                 //重心移動機構の角度

          data[0] = left_pwm;          
          data[1] = right_pwm;
          data[2] = servo_angle;
          data[3] = cog_angle;

          break;
      }
    }
    
    if(data[0]>240){data[0] = 255;}
    if(data[1]>240){data[1] = 255;}

    #ifdef DEBUG
      Serial.print("lx:");
      Serial.print(left_LR);
      Serial.print("ly:");
      Serial.print(left_UD);
      Serial.print("sli_L:");
      Serial.print(sli_L);
      Serial.print("sli_R:");
      Serial.print(sli_R);
      Serial.print("vol:");
      Serial.print(vol);
      Serial.print("btn1:");
      Serial.print(btn_R);
      Serial.print("btn2:");
      Serial.print(btn_L);
      Serial.print(data[0]);
      Serial.print(data[1]);
      Serial.print(data[2]);
      Serial.print(data[3]);
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
