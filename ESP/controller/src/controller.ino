#include <esp_now.h>
#include <WiFi.h>

#include <SPI.h>
//#define DEBUG

unsigned long lastTime = 0;  
unsigned long timerDelay = 60;  // send readings timer
size_t data_pc_;                //size_t:オブジェクトのバイト数を表現できる程度に十分に大きい符号なし整数型
uint8_t data_pc[5] = {0};
int re_data[5] = {0};
double re_data_angle[4] = {0};

// REPLACE WITH RECEIVER MAC Address

//機体側のマイコンの番号にあったアドレスのみコメントアウトを外す。
//uint8_t castAddress[] = {0x8C, 0xCE, 0x4E, 0xEA, 0xB1, 0xC9}; //0
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0x60}; //旧1
uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0x81, 0x0A};   //新1
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0x3D}; //2
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0x95, 0xE4}; //3
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0xAC}; //4
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0x95, 0x98}; //5
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0x80, 0xA6}; //6　修正済み
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA3, 0x2D}; //7
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0x81, 0x89}; //9 李さん作

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
    //noInterrupts();
    //taskDISABLE_INTERRUPTS();
    char macStr[18];
    //データの送信元のmacアドレスを整形し（%02X:等を付け）て、macStr配列に書き込む。
    //%02Xは2桁以上の16進数(Xは16進数)で表示することを指定（桁が足りない場合、上位の桁が0埋めされる。）
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
          //残り(受信間隔とservo2つ)はそのままre_dataに格納
          re_data[i] = data[i];
        }
    }
    
    //カンマ区切りでre_dataの中身をシリアルポートに送信
    for (int i = 0; i < 5; i++) {
      Serial.print(re_data[i]); //確認用の出力
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
    //Serial.flush();     //データを送信しきるまで（送信バッファが空になるまで）待つ。
    delay(10);            //flushじゃだめかもしれない？10msなので注意
    //interrupts();
    //taskENABLE_INTERRUPTS();
    //delay(10);           //さらに待機
}

//送信時コールバック関数
//送信が成功したかどうかを表示する。
void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status) {
  #ifdef DEBUG
    Serial.println();
    Serial.printf("ESP32\n");
    Serial.print("Last Packet Send Status: ");
    if (status == 0){
      Serial.println("Delivery success");
    }
    else{
      Serial.println("Delivery fail");
    }
  #endif
}

//PCからの情報を受信する関数
void recieve_pc(){
  if(Serial.available()){                               //シリアルポートにデータが来ている場合(この関数は何バイトのデータがポートに到着したかを返す)
    if((int)Serial.read() == 255){                      //データの先頭が255である場合(シリアルデータを１バイト分読み込む関数)

      //5つのデータを読み取り、data_pcに格納する。
      //data_pc_にはデータ長が格納される
      data_pc_ = Serial.readBytesUntil('\n',data_pc,5); //size_t型のdeta_pc_とuint8_t型のdeta_pcがある
      delay(10);  //dataを読み切るための待機時間を追加 
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
    //Serial.begin(460800);   もとのボーレート
    //Serial.begin(115200);   一段階下げたもの
    //9600, 14400, 19200, 28800,38400
    //Serial.begin(57600);    もう一段階下げたもの（Lazurite時代と同じ）
    Serial.begin(38400); //通信の開始(通信速度)
    while(!Serial)//通信開始待機
    
    
    //ピンモードの設定
    pinMode(stick_lr, INPUT);
    pinMode(stick_ud, INPUT);
    pinMode(slider_l, INPUT);
    pinMode(slider_r, INPUT);
    pinMode(volume, INPUT);
    pinMode(switch_1, INPUT_PULLUP);  //トグルスイッチのプルアップ、ダウンはここで設定
    pinMode(switch_2, INPUT_PULLUP);

    Serial.println(WiFi.macAddress());  //おまじない？??
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    if (esp_now_init() == ESP_OK) { //通信の初期化が出来た時？
        //Serial.println("ESP-Now Init Success");
    }
      // Register peer
    memcpy(peerInfo.peer_addr, castAddress, 6); //peerinfoにcastaddの先頭６バイトをぶち込む
    peerInfo.channel = 0;  //ステーションもしくはソフトウェアがONになっている現在のチャンネルを利用する
    peerInfo.encrypt = false; //暗号化しない
    
    // Add peer        
    if (esp_now_add_peer(&peerInfo) != ESP_OK){   //peerのaddに失敗したらエラー吐いて終了
      Serial.println("Failed to add peer");
      return;
    }
    
    //esp_now_register_send_cb(OnDataSent);
    //受信時コールバック関数の[指定]
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
  int btn_L = digitalRead(switch_1);  //指定したデジタルピン(switch1)から1か0を読みとる  
  int btn_R = digitalRead(switch_2);  //1と0:HIGHとLOW btn:ボタン

  if ((millis() - lastTime) > timerDelay) { //受信間隔がtimerDelay以上であれば、(millisはプログラム開始から経過時間をカウント)
    uint8_t data[5]; //unit8_t型のdata[5]の宣言

    //PCモード(強化学習に利用するモード)
    if(btn_L == 1){
      recieve_pc();                         //PCからデータ受信(上に関数あり)
      //Serial.print("PC_mode");

      //PCから受け取った情報を機体側のマイコンに送信する準備
      for(int i=0;i<2;++i){
        data[i] = 254 - data_pc[i];         //受信データの先頭2つ（羽ばたき出力）は反転
      }
      for(int i=2;i<5;++i){       //受信データ後3つ(サーボの角度)はそのまま
        data[i] = data_pc[i];
      }
    
    //コントローラモード(コントローラーで動かすとき)
    }else{  
    
      switch(controller_num){   //1:白いやつ　2：配線見えてる方
        case 1:                
          left_LR = map(analogRead(stick_lr),0,4096,0,255);   //割り当てなし　スティックの左右方向の連続値(0~4096)を機体で扱えるよう0~255まで圧縮する関数
          left_UD = map(analogRead(stick_ud),0,4096,0,180);   //尾翼サーボ
          sli_L = map(analogRead(slider_l),0,4096,0,255);     //左の羽ばたき出力
          sli_R = map(analogRead(slider_r),0,4096,0,255);     //右の羽ばたき出力
          vol = map(analogRead(volume),0,4096,0,255);         //割り当てなし
          //btn_R = digitalRead(switch_2);
          //スティックが完全に垂直になっていることはないため、スティックに触っていない時(スティックが中央にあるとき)の補正をする。(デッドゾーン補正)
          if(left_LR<152 && left_LR>102){left_LR = 127;}      //左右のスティックを中央にしたときのずれを矯正する
          if(left_UD<105 && left_UD>75){left_UD = 90;}        //上下               //                       ただし中央の値が90をとることに注意

          data[0] = sli_L;         //deta配列にコントローラーの操作による値を代入していく
          data[1] = sli_R;
          data[2] = left_UD;
          data[3] = btn_R*120;     //重心移動機構を120°に傾ける
          data[4] = btn_R;
          break;
        
        case 2:
          left_LR = map(analogRead(stick_lr),0,4096,0,255); //揚力差　スティックの左右方向の連続値(0~4096)を機体で扱えるよう0~255まで圧縮する関数
          left_UD = map(analogRead(stick_ud),0,4096,0,255); //割り当てなし　スティックの上下
          sli_L = map(analogRead(slider_l),0,4096,0,180);   //尾翼サーボ　　スライドの左　
          sli_R = map(analogRead(slider_r),0,4096,0,255);   //羽ばたき出力　　スライドの右
          //btn_L = digitalRead(switch_1);
          //vol = map(analogRead(volume),0,4096,0,255);
          //btn_R = digitalRead(switch_2);

          //コントローラー１と同じようにスティックとスライダーの補正をする。
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
          int cog_angle = 40*btn_R;                 //重心移動機構の角度(多分120°だけど変え忘れてる)

          data[0] = left_pwm;          
          data[1] = right_pwm;
          data[2] = servo_angle;
          data[3] = cog_angle;

          break;
      }
    }
    
    //羽ばたき出力の矯正
    //大体Maxの値になっていたらMaxの出力にしてやる
    if(data[0]>240){data[0] = 255;}
    if(data[1]>240){data[1] = 255;}

    //コントローラモードの場合のみ
    if(btn_L != 1){
      //PC側にコントローラから指示された値を返してやる。
      //PC側にシリアル通信で送信することで、シリアルモニタに表示される。
      //PC_modeでこれをやったらダメ!receive_from_espがバグる。
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
    }

    //delay(10);

    // Send message via ESP-NOW
    esp_now_send(castAddress, (uint8_t *) &data, sizeof(data));
    delay(10);
    //esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
    lastTime = millis();
  }
}
