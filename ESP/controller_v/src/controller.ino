#include <esp_now.h>
#include <WiFi.h>

#include <SPI.h>

#include "CalPID.h"

//#define DEBUG


int flag = 0;
int flag_yaw = 0;

typedef struct param_{
  double kp = 0;
  double ki = 0;
  double kd = 0;
  double Target;
  double Error;
  double State;
  double Output;
  double max;
  double min = 0;
  float dt = 40;
}param;

param servo;
param motor; //nomi

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
int stick_lr,stick_ud,slider_l,slider_r,switch_1,switch_2,volume;

// REPLACE WITH RECEIVER MAC Address
//機体側のマイコンの番号にあったアドレスのみコメントアウトを外す。
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0x60}; //1
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0x3D}; //2
uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA2, 0x22}; //3
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA1, 0xAC}; //4
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0x95, 0x98}; //5
//uint8_t castAddress[] = {0xB4, 0xE6, 0x2D, 0x2F, 0xA2, 0xBF};   //6

esp_now_peer_info_t peerInfo;

const int controller_num = 2; //1:A 2:B
const float servo_sensitivity = 1.0; //0.0(min)~1.0(max)

void qu2eu(int eular[3], double quotanion[4]);
void onReceive(const uint8_t* mac_addr, const uint8_t* data, int data_len);
void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status);
void recieve_pc();

CalPID pitch_pid(0,0,0,40,0);
CalPID yaw_pid(0,0,0,40,0); //nomi

void forward(){
  pitch_pid.resetIntegral();
  servo.kp = 2.2;
  servo.ki = 0.000;
  servo.kd = 0.0002;
  servo.Target = 30; 
  pitch_pid.setParameter(servo.kp,servo.ki,servo.kd);
}

void normal(){
  pitch_pid.resetIntegral();
  servo.kp = 0.8;
  servo.ki = 0.0001;
  servo.kd = 0.0000;
  servo.Target = 0;
  pitch_pid.setParameter(servo.kp,servo.ki,servo.kd);
}

void back(){
  pitch_pid.resetIntegral();
  servo.kp = 1.5;
  servo.ki = 0.000;
  servo.kd = 0.0007;
  servo.Target = -20;
  pitch_pid.setParameter(servo.kp,servo.ki,servo.kd);
}

//↓ここから左右のYAW制御
void left(){
  yaw_pid.resetIntegral();
  motor.kp = 3.0;
  motor.ki = 0.0005;
  motor.kd = 0.000;
  motor.Target = 20; 
  yaw_pid.setParameter(motor.kp,motor.ki,motor.kd);
}

void normal_yaw(){
  yaw_pid.resetIntegral();
  motor.kp = 1.7;
  motor.ki = 0.001;
  motor.kd = 0.000;
  motor.Target = 0; 
  yaw_pid.setParameter(motor.kp,motor.ki,motor.kd);
}

void right(){
  yaw_pid.resetIntegral();
  motor.kp = 3.0;
  motor.ki = 0.0005;
  motor.kd = 0.0000;
  motor.Target = -20; 
  yaw_pid.setParameter(motor.kp,motor.ki,motor.kd);
}

//↑ここまでが左右のYqw制御

void setup() {
 //垂直飛行のみ
  /*servo.kp = 0.8;
  servo.ki = 0.0002;
  servo.kd = 0.000;*/
  servo.max = 90;
  servo.dt = 40;
  servo.Target = 0;
  
 /*↓書き足した
  servo_hover.kp = 1;
  servo_hover.ki = 0.000;
  servo_hover.kd = 0.0;
  servo_forward.kp = 1;
  servo_forward.ki = 0.000;
  servo_forward.kd = 0.0;
  servo_back.kp = 1;
  servo_back.ki = 0.000;
  servo_back.kd = 0.0;
  servo.max = 90;
  servo.dt = 40;
  servo.Target = 0;
  ここまで*/


//nomi
  /*motor.kp = 0.5;
  motor.ki = 0.0001;
  motor.kd = 0.000;*/
  motor.max = 255;
  motor.dt = 40;
  motor.Target = 0;
//nomi
  pitch_pid.setParameter(servo.kp,servo.ki,servo.kd);
  pitch_pid.setDELTA_T(servo.dt);
  pitch_pid.setMaxValue(servo.max);

//nomi
  yaw_pid.setParameter(motor.kp,motor.ki,motor.kd);
  yaw_pid.setDELTA_T(motor.dt);
  yaw_pid.setMaxValue(motor.max);
//nomi

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
    esp_now_register_recv_cb(onReceive);
    
}

//各アナログスイッチ入力値格納用
int left_LR;
int left_UD;
int sli_L;
int sli_R;
int vol;
int mode_flag = 0;
int mode_flag_yaw = 0;

void loop() {
  //トグルスイッチの入力値読み取り
  int btn_L = digitalRead(switch_1);
  int btn_R = digitalRead(switch_2);

  if ((millis() - lastTime) > timerDelay) { //受信間隔がtimerDelay以内であれば、
    uint8_t data[5];


          /*motor.Target = 0;
          motor.State = re_data[6];
          motor.Error = motor.Target-motor.State;
          motor.Output = yaw_pid.calPID(motor.Error);
          */
//nomi

    //PIDモード
    if(btn_L == 1){
          flag = 1;
          flag_yaw = 1;
          left_LR = map(analogRead(stick_lr),0,4096,0,255); //揚力差
          left_UD = map(analogRead(stick_ud),0,4096,0,255); //割り当てなし
          //sli_L = map(analogRead(slider_l),0,4096,90.0*(1.0-servo_sensitivity),90.0+90.0*servo_sensitivity);   //尾翼サーボ
          sli_L = map(analogRead(slider_l),0,4096,-10,10);
          sli_R = map(analogRead(slider_r),0,4096,0,255);   //羽ばたき出力
//↓垂直飛行のみ
          /*
          if(abs(sli_L)<3){sli_L = 0;}
          servo.Target = sli_L;
          servo.Target = 0;
          servo.State = re_data[5];
          servo.Error = servo.Target-servo.State;
          servo.Output = pitch_pid.calPID(servo.Error);
          */
//↑垂直飛行のみ
//nomi
            //スライドボリューム右（羽ばたき出力）最小
          if(sli_R>240){sli_R = 255;}
          //ジョイスティック左右中央
          if(left_LR<152 && left_LR>102){left_LR = 127;}
          //ジョイスティック上下中央
          if(left_UD<152 && left_UD>102){left_UD = 127;}
          

          if(left_UD<127 && mode_flag!=1){
            forward();
            mode_flag = 1;
          }else if(left_UD==127 && mode_flag!=2){
            normal();
            mode_flag = 2;
          }else if(left_UD>127 && mode_flag!=3){
            back();
            mode_flag = 3;
          }
        

          servo.State = re_data[5];
          servo.Error = servo.Target-servo.State;
          servo.Output = pitch_pid.calPID(servo.Error);

         //↓左右のYaw制御
         if(left_LR<127 && mode_flag_yaw!=1){
           left();
           mode_flag_yaw = 1;
         }else if(left_LR==127 && mode_flag_yaw!=2){
           normal_yaw();
           mode_flag_yaw = 2;
         }else if(left_LR>127 && mode_flag_yaw!=3){
           right();
           mode_flag_yaw = 3;
         }

         
         motor.State = re_data[6];
         motor.Error = motor.Target-motor.State;
         motor.Output = yaw_pid.calPID(motor.Error);

         //↑左右のYaw制御

          int yaw_pid = abs((int)motor.Output);
          int left_pwm,rigit_pwm = 255;
          if(motor.Error > 0 ){
            left_pwm = max(0,sli_R);  //左（要確認）
            right_pwm = max(0,sli_R - yaw_pid); //右（要確認）
          }else{
            left_pwm = max(0,sli_R - yaw_pid);  //左（要確認）
            right_pwm = max(0,sli_R); //右（要確認）
          }
          
        

          
          data[0] = left_pwm;          
          data[1] = right_pwm;
          data[2] = -1*servo.Output+90;
          data[3] = servo.Output+90;
          
    
    //コントローラモード
    }else{  
      flag = 0;
      switch(controller_num){
        case 1:
          left_LR = map(analogRead(stick_lr),0,4096,0,255);
          left_UD = map(analogRead(stick_ud),0,4096,90.0*(1.0-servo_sensitivity),90.0+90.0*servo_sensitivity);
          sli_L = map(analogRead(slider_l),0,4096,0,255);
          sli_R = map(analogRead(slider_r),0,4096,0,255);
          vol = map(analogRead(volume),0,4096,0,255);
          //btn_R = digitalRead(switch_2);

          if(left_LR<152 && left_LR>102){left_LR = 127;}
          if(left_UD<105 && left_UD>75){left_UD = 90;}

          data[0] = sli_L;    //左羽ばたき出力
          data[1] = sli_R;    //右羽ばたき出力
          data[2] = left_UD;  //サーボ1角（元は尾翼）
          data[3] = 180 - left_UD;  //サーボ2角（元はcog）
          //data[4] = btn_R;
          if(btn_R == 1){
            data[2] = 0;
            data[3] = 0;
          }
          break;
        
        case 2:
          left_LR = map(analogRead(stick_lr),0,4096,0,255); //揚力差
          left_UD = map(analogRead(stick_ud),0,4096,0,255); //割り当てなし
          sli_L = map(analogRead(slider_l),0,4096,90.0*(1.0-servo_sensitivity),90.0+90.0*servo_sensitivity);   //尾翼サーボ
          sli_R = map(analogRead(slider_r),0,4096,0,255);   //羽ばたき出力
          //btn_L = digitalRead(switch_1);
          //vol = map(analogRead(volume),0,4096,0,255);
          btn_R = digitalRead(switch_2);

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
          int cog_angle = 180 - sli_L;                 //重心移動機構の角度

          data[0] = left_pwm;          
          data[1] = right_pwm;
          data[2] = servo_angle;
          data[3] = cog_angle;
          
          if(btn_R == 1){
            data[2] = 0;
            data[3] = 0;
          }

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
      re_data[5] = -1*data[5];
    }else{
      re_data[5] = data[6];
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
   if(flag == 1){
    sprintf(send_pc, "%d,%d,%d,%d,%d,%d,%d,%d,%f,%f,%f,",re_data[0],re_data[1],re_data[2],re_data[3],re_data[4],-1*re_data[5],re_data[6],re_data[7],servo.Output,motor.Output,motor.Target);
    Serial.println(send_pc);
    Serial.flush();
   }
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
      data_pc_ = Serial.readBytesUntil('\n',data_pc,5); //5つのデータを読み取り、data_pc_に格納
    }
  }
}