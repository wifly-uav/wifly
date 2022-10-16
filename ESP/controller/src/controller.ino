#include <esp_now.h>
#include <WiFi.h>

#include <SPI.h>
#define DEBUG

unsigned long lastTime = 0;  
unsigned long timerDelay = 60;  // send readings timer
size_t data_pc_;                //size_t:オブジェクトのバイト数を表現できる程度に十分に大きい符号なし整数型
uint8_t data_pc[5] = {0};
int re_data[5] = {0};
double re_data_angle[4] = {0};

// REPLACE WITH RECEIVER MAC Address
//機体側のマイコンの番号にあったアドレスのみコメントアウトを外す。
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0x60}; //1
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0x3D}; //2
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0x95, 0xE4}; //3
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0xAC}; //4
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0x95, 0x98}; //5
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA2, 0xBF};   //6
uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA3, 0x2D};   //7

esp_now_peer_info_t peerInfo;

const int controller_num = 1; //1:A 2:B

//pin
//各ボタンのピン番号
int stick_lr;
int stick_ud;
int slider_l;
int slider_r;
int switch_1;
int switch_2;
int volume;

double ysqr = 0;
double t0,t1,t2,t3,t4 = 0;
int eular[3] = {0};

//quotanion（四元数）をEuler角に変換する関数
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

  /*
  ysqr = y * y;

  // roll (x-axis rotation)
  t0 = +2.0 * (w * x + y * z);
  t1 = +1.0 - 2.0 * (x * x + ysqr);
  eular[0] = atan2(t0, t1)/PI*180;

  // pitch (y-axis rotation)
  t2 = +2.0 * (w * y - z * x);
  t2 = t2 > 1.0 ? 1.0 : t2;
  t2 = t2 < -1.0 ? -1.0 : t2;
  eular[1] = asin(t2)/PI*180;

  // yaw (z-axis rotation)
  t3 = +2.0 * (w * z + x * y);
  t4 = +1.0 - 2.0 * (ysqr + z * z);  
  eular[2] = atan2(t3, t4)/PI*180;
  */
}

//受信時コールバック関数（データを受信すると実行される）
//引数:送信元macアドレス情報,受信データ,受信データ長
void onReceive(const uint8_t* mac_addr, const uint8_t* data, int data_len) {
    char macStr[18];
    //データの送信元のmacアドレスを整形し（%02X:等を付け）て、macStr配列に書き込む。
    //%02Xは2桁以上の16進数で表示することを指定（桁が足りない場合、上位の桁が0埋めされる。）
    snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X",
        mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
    //Serial.println();
    //Serial.printf("ESP32\n");
    //Serial.printf("Last Packet Recv from: %s\n", macStr);
    //Serial.printf("Last Packet Recv Data(%d): ", data_len);
    //Serial.println();

    //受信データの整形
    //data_lenは9
    //[pwm1, pwm2, servo1, servo2, 受信間隔, quaternion1,quaternion2,quaternion3,quaternion4]
    for (int i = 0; i < data_len; i++) {
        if(i > 4){
          //受信データの5番目以降（quotanion）は、処理してre_data_angleに格納していく。
          re_data_angle[i-5] = data[i]*0.01-1;
        }else if(i < 2){
          //受信データの先頭2つ（羽ばたき出力）は、0~255を反転してre_dataに格納
          re_data[i] = 255 - data[i];
        }
        else{
          //残り(受信間隔とquaternion4つ)はそのままre_dataに格納
          re_data[i] = data[i];
        }
    }
    
    //カンマ区切りでre_dataの中身をシリアルポートに送信
    for (int i = 0; i < 5; i++) {
      Serial.print(re_data[i]);
      if(i != 4){
        Serial.print(",");
      }
    }

    //受信したquotarnionをEuler角に変換
    qu2eu(eular,re_data_angle);
    Serial.print(",");

    //Euler角（Pitch, Yaw, Roll）をシリアルポートに送信
    for (int i = 0; i < 3; i++) {
      Serial.print(eular[i]);
      if(i != 2){
        Serial.print(",");
      }
    }
    Serial.println();
    Serial.flush();     //データを送信しきるまで（送信バッファが空になるまで）待つ。
}

//送信時コールバック関数
//送信が成功したかどうかを表示する。
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

//PCからの情報を受信する関数
void recieve_pc(){
  if(Serial.available()){                               //シリアルポートにデータが来ている場合
    if((int)Serial.read() == 255){                      //データの先頭が255である場合

      //5つのデータを読み取り、data_pcに格納する。
      //data_pc_にはデータ長が格納される
      data_pc_ = Serial.readBytesUntil('\n',data_pc,5); 
    }
  }
}

void setup() {

  //各コントローラごとのピン番号
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

    //シリアル通信開始
    Serial.begin(460800);    
    
    //ピンモードの設定
    pinMode(stick_lr, INPUT);
    pinMode(stick_ud, INPUT);
    pinMode(slider_l, INPUT);
    pinMode(slider_r, INPUT);
    pinMode(volume, INPUT);
    pinMode(switch_1, INPUT_PULLUP);  //トグルスイッチのプルアップ、ダウンはここで設定
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
    //受信時コールバック関数の指定
    esp_now_register_recv_cb(onReceive);
    
}

//各アナログスイッチ入力値格納用
int left_LR;
int left_UD;
int sli_L;
int sli_R;
int vol;

void loop() {
  
  //トグルスイッチの入力値読み取り
  int btn_L = digitalRead(switch_1);
  int btn_R = digitalRead(switch_2);

  if ((millis() - lastTime) > timerDelay) { //受信間隔がtimerDelay以内であれば、
    uint8_t data[5];

    //PCモード
    if(btn_L == 1){
      recieve_pc();                         //PCからデータ受信
      //Serial.print("PC_mode");

      //PCから受け取った情報を機体側のマイコンに送信する準備
      for(int i=0;i<2;++i){
        data[i] = 254 - data_pc[i];         //受信データの先頭2つ（羽ばたき出力）は反転
      }
      for(int i=2;i<5;++i){
        data[i] = data_pc[i];
      }
    
    //コントローラモード
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
          data[3] = btn_R*40;
          data[4] = btn_R;
          break;
        
        case 2:
          left_LR = map(analogRead(stick_lr),0,4096,0,255); //揚力差
          left_UD = map(analogRead(stick_ud),0,4096,0,255); //割り当てなし
          sli_L = map(analogRead(slider_l),0,4096,0,180);   //尾翼サーボ
          sli_R = map(analogRead(slider_r),0,4096,0,255);   //羽ばたき出力
          //btn_L = digitalRead(switch_1);
          //vol = map(analogRead(volume),0,4096,0,255);
          //btn_R = digitalRead(switch_2);

          //スライドボリューム左（尾翼）最小
          if(sli_L>170){sli_L = 180;}
          //スライドボリューム右（羽ばたき出力）最小
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
          int cog_angle = 40*btn_R;                 //重心移動機構の角度

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
      /*
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
      */
      Serial.print(data[0]);
      Serial.print(data[1]);
      Serial.print(data[2]);
      Serial.print(data[3]);
      Serial.println();
      Serial.print(btn_R);
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
