#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Servo.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#include <SPI.h>

//#define DEBUG         // シリアルモニタで各スイッチの出力を確認できる。
#define sensor        // 操縦時はコメントアウト

//int kitai_number = 4;   
//1~5:Pch 6:Nch

//コントローラごとにここを切り替える!!!!----------------------------------

char controller = 'A';  //大きいコントローラ：A 小さいコントローラ：B

//---------------------------------------------------------------------

#define PWM_FREQ 1000 // FREQ(周波数)1000 PWM出力とはオンとオフの繰り返しスイッチングを行い、出力される電力を制御する 周波数が大きすぎると何がおきる？？(調べる、理由は保留)
#define PWM_RANGE 255 // PWM値の制限をかけている、最大が大きすぎないようにする

#ifdef sensor
  Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);  // センサーの初期化????
#endif

//各種ピン番号設定
const int pwm1 = 12;
const int pwm2 = 13;
const int pwmch = 0;
const int cog_pin = 16;
const int ladder_pin = 14;
const int led = 15;

//Servoクラスの作成
Servo cog;  // 重心移動機構のServoクラスの作成
Servo ladder; // 尾翼のServoクラスの作成

int command[8] = {0}; // 配列0~7を初期化するために、すべて0埋め
uint8_t data[9];  // 符号なし8bit整数型の配列、配列の中身は0~8の番号

unsigned long lastTime = 0;     // 最新の受信時刻 符号なし長整数型 バイト長4
unsigned long recvTime = 0;     // 受信時刻(未使用)
unsigned long Ti = 0;
unsigned long loopTi = 0;       // 受信間隔
unsigned long timerDelay = 20;  // send readings timer
unsigned long watchdogtime = 100;  // timer

double w,x,y,z = 0; // double型は実数を扱うことができる

int i = 0;

// Callback when data is sent
// DEBUG時には送信が成功したかどうかを表示する。
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {  // メッセージが送信されるときに実行されるコールバック関数、この関数はメッセージが正常に受信されたかどうかを単純に出力する。 esp_now_sendが走ったらOndatasent実行　sendStatusはesp_now_sendが成功したかどうか0or1で判断 Macaddrは引数として必要で、値としては呼び出されるときに送信先のmacaddrが入る。 今回なら送信先のmacaddrはbroadcastaddressであり、そのアドレスが入る。結局はbraodcastadressの値となる。
  #ifdef DEBUG_SENT
    Serial.println(); // 改行
    Serial.print("Last Packet Send Status: ");  // "Last Packet Send Status: " 空白にはif文の中printlnの文字が続く
  if (sendStatus == 0){
    Serial.println("Delivery success");
  }
  else{
    Serial.println("Delivery fail");
  }
  #endif
}

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac_addr, uint8_t *data, uint8_t len) { // データが受信されたときに実行されるコールバック関数　lenというのはdata_lenであってるコントローラーから送られてくるデータの長さによって異なる(lenの値)
  digitalWrite(led, HIGH);  // LED点灯 HIGHを引数で呼ぶことでLEDは暗く光る ledは37行目のconst led int = 15というもの これを入れることでそのピン番号に接続されているLEDが光るということ
  //char macStr[18]; macStrという文字列の配列の定義であり、その文字列サイズが18である。
  //snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X",
  //    mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]); mac_addr[]の値を"%02X:%02X:%02X:%02X:%02X:%02X"の16進数の文字列に変換してmacStrという文字配列に書き込む、書き込む文字数はmacStrのサイズの文字数となっている(今回は18である) %02xは整数を16進数で出力する
  #ifdef DEBUG
    Serial.println(); //  改行
    // Serial.printf("Last Packet Recv from: %s\n", macStr);  // %s\nは文字列を出力、今回はmacStrという文字列を出力
    Serial.printf("Last Packet Recv Data(%d): ", len);  // %dは符号あり整数を表示、ここで矛盾があるのだが、lenは符号なしの8bit型の整数なのに出力は可能なのか？？
  #endif

  //データ受信
  for (i = 0; i < len; ++i) {
    command[i] = data[i]; // 43行目で定義されている配列0~7に44行目の配列の値を代入　dataの値ってどこに入ってる？？、もう一つの疑問としてはintの配列にuint8_tは代入できるの？？
    #ifdef DEBUG
      Serial.print(data[i]);  // data[i]を出力して下の行でスペース出力
      Serial.print(" ");
    #endif
  }
  digitalWrite(led, LOW); // LED消灯（受信を繰り返すことでLEDが高速点滅）
  recvTime = millis();  // ここまでのプログラムの実行時間をrecvTimeに代入、それが受信時刻となる　1行目からプログラムが走ってここまでの時間であってる？？
}

uint8_t broadcastAddress[6];  // 符号なし8bit整数型の配列、配列の中身は0~5となっている。
void setup() {
  Serial.begin(115200);               // シリアル通信開始（速度指定）
  Serial.println();                   // 改行出力

  pinMode(pwm1, OUTPUT);              // 羽ばたきモータ出力1に対応するピンを出力モードにする。
  pinMode(pwm2, OUTPUT);              // 羽ばたきモータ出力2に対応するピンを出力モードにする。
  pinMode(led, OUTPUT);               // LEDに対応するピンを出力モードにする。
  analogWriteFreq(PWM_FREQ);          // アナログ出力の周波数を指定 PWM_FREQ24行目で定義
  analogWriteRange(PWM_RANGE);        // アナログ出力の範囲を指定 PWM_RANGE25行目で定義

  digitalWrite(led, HIGH);            // LED点灯
  analogWrite(pwm1, PWM_RANGE);       // 羽ばたきを止める
  analogWrite(pwm2, PWM_RANGE);       // 羽ばたきを止める
  
  cog.attach(cog_pin,900,1900);       // 重心移動機構サーボ出力の上限下限を設定
  ladder.attach(ladder_pin,900,1900); // 尾翼サーボ出力の上限下限を設定
  
  cog.write(0);                       // サーボの角度をリセット（0°）重心移動機構の角度
  ladder.write(0);                    // 尾翼サーボの角度をリセット

  // REPLACE WITH RECEIVER MAC Address
  // 各コントローラのMACアドレス
  if(controller == 'A'){
    broadcastAddress[0] = 0x8C;
    broadcastAddress[1] = 0x4B;
    broadcastAddress[2] = 0x14;
    broadcastAddress[3] = 0x16;
    broadcastAddress[4] = 0x63;
    broadcastAddress[5] = 0x0C;
  }else if(controller == 'B'){
    broadcastAddress[0] = 0xC8;
    broadcastAddress[1] = 0x2B;
    broadcastAddress[2] = 0x96;
    broadcastAddress[3] = 0xB9;
    broadcastAddress[4] = 0x69;
    broadcastAddress[5] = 0x54;
  }
  
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

  //受信コールバック関数の指定
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

  //通信の初期設定に成功したら、LED(オレンジ?)を消す。
  digitalWrite(led, LOW);
}

//float型用のmap関数を自作
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
    //imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
    imu::Quaternion quaternion = bno.getQuat();
  #endif

  Ti = millis();              //現在時刻
  loopTi = Ti - lastTime;     //前回受信からの時間差
  if (loopTi > timerDelay) {
    // Set values to send
    //送信データを準備
    data[0] = command[0];     //羽ばたき出力1     
    data[1] = command[1];     //羽ばたき出力2
    data[2] = command[2];     //尾翼サーボ角度
    data[3] = command[3];     //受信移動機構角度
    #ifdef sensor
      data[5] = (quaternion.w()+1)*100;
      data[6] = (quaternion.x()+1)*100;
      data[7] = (quaternion.y()+1)*100;
      data[8] = (quaternion.z()+1)*100;
    #else
      data[5] = 0;
      data[6] = 0;
      data[7] = 0;
      data[8] = 0;
    #endif
    data[4] = loopTi;         //受信間隔
    #ifdef DEBUG
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
      Serial.println();
      */
    #endif

    //機体の状態をコントローラに送信
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
  //受信データに基づき各出力を変更
  analogWrite(pwm1, command[0]);
  analogWrite(pwm2, command[1]);
  ladder.write(command[2]);
  cog.write(command[3]);
  
  //delay(50);
}