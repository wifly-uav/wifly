#include <esp_now.h>
#include <WiFi.h>

#include <SPI.h>
//#define DEBUG

unsigned long lastTime = 0;  
unsigned long timerDelay = 100;  // send readings timer

// REPLACE WITH RECEIVER MAC Address
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0x60}; //1
uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0x95, 0xE4}; //3
//uint8_t castAddress[] = {0xEC, 0xFA, 0xBC, 0xBB, 0x56, 0x54}; //4


esp_now_peer_info_t peerInfo;

//pin
const int stick_lr = 34;
const int stick_ud = 35;
const int slider_l = 33;
const int slider_r = 32;
const int switch_1 = 23;
const int switch_2 = 13;
const int volume = 39;


void onReceive(const uint8_t* mac_addr, const uint8_t* data, int data_len) {
    char macStr[18];
    snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X",
        mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
    Serial.println();
    Serial.printf("ESP32\n");
    Serial.printf("Last Packet Recv from: %s\n", macStr);
    Serial.printf("Last Packet Recv Data(%d): ", data_len);
    for (int i = 0; i < data_len; i++) {
        Serial.print(data[i]);
        Serial.print(" ");
    }
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

void setup() {
    Serial.begin(115200);    
    
    pinMode(stick_lr, INPUT);
    pinMode(stick_ud, INPUT);
    pinMode(slider_l, INPUT);
    pinMode(slider_r, INPUT);
    pinMode(volume, INPUT);
    pinMode(switch_1, INPUT_PULLUP);
    pinMode(switch_2, INPUT_PULLUP);

    Serial.println(WiFi.macAddress()); // ãã®ã¢ãã¬ã¹ãéä¿¡å´ã¸ç»é²ãã¾ã

    
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    if (esp_now_init() == ESP_OK) {
        Serial.println("ESP-Now Init Success");
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
    
    esp_now_register_send_cb(OnDataSent);
    esp_now_register_recv_cb(onReceive);
    
}

void loop() {
  
  int left_LR = map(analogRead(stick_lr),0,4096,0,255);
  int left_UD = map(analogRead(stick_ud),0,4096,0,180);
  int sli_L = map(analogRead(slider_l),0,4096,0,255);
  int sli_R = map(analogRead(slider_r),0,4096,0,255);
  int vol = map(analogRead(volume),0,4096,0,255);
  int btn_L = digitalRead(switch_1);
  int btn_R = digitalRead(switch_2);

  if ((millis() - lastTime) > timerDelay) {

    
    if(sli_L>240){
      sli_L = 255;
    }
    if(sli_R>240){
      sli_R = 255;
    }

    if(left_LR<152 && left_LR>102){
      left_LR = 127;
    }
    if(left_UD<105 && left_UD>75){
      left_UD = 90;
    }

    uint8_t data[4];
    data[0] = sli_L;
    data[1] = sli_R;
    data[2] = left_UD;
    data[3] = left_UD;
    //data[2] = 511-right_LR;
    //data[3] = 511-right_UD;
    //data[4] = sli;

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

    delay(10);

    // Send message via ESP-NOW
    esp_now_send(castAddress, (uint8_t *) &data, sizeof(data));
    //esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
    lastTime = millis();
  }
}
