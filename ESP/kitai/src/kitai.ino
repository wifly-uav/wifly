#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Servo.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#include <SPI.h>

//#define DEBUG         // シリアルモニタで各スイッチの出力を確認できる。
//#define sensor        // 操縦時はコメントアウト←これをワンチャンコメントアウトしてみる

//int kitai_number = 4;   
//1~5:Pch 6:Nch

//コントローラごとにここを切り替える!!!!----------------------------------

char controller = 'A';  //大きいコントローラ：A 小さいコントローラ：B

//---------------------------------------------------------------------

#define PWM_FREQ 1000 // FREQ(周波数)1000 PWM出力とはオンとオフの繰り返しスイッチングを行い、出力される電力を制御する 周波数が大きすぎると何がおきる？？(調べる、理由は保留) 周波数が高くなりすぎるとデューティ比の0近くと1023近くで挙動がおかしくなる Source:https://www.ei.tohoku.ac.jp/xkozima/lab/espTutorial0.html
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
unsigned long watchdogtime = 100;  // timer マイコンのプログラムが停止・暴走をしていないかを確認するためのタイマ

double w,x,y,z = 0; // double型は実数を扱うことができる

int i = 0;

// Callback when data is sent
// DEBUG時には送信が成功したかどうかを表示する。
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {  // メッセージが送信されるときに実行されるコールバック関数、この関数はメッセージが正常に受信されたかどうかを単純に出力する。 esp_now_sendが走ったらOndatasent実行　sendStatusはesp_now_sendが成功したかどうか0or1で判断 Macaddrは引数として必要で、値としては呼び出されるときに送信先のmacaddrが入る。 今回なら送信先のmacaddrはbroadcastaddressであり、そのアドレスが入る。結局はbraodcastadressの値となる。macAddrとしてもbroadcastAddrでも問題はない、関数内で使われる名前はそこで使われる名前なので送信する関数の名前と変わっても大丈夫。例えば数字a,b,c...を引き渡すとして関数内の引数をいちいちa,b,c...とか書いてられないからそこをnumとするとかがよい例である。ここでMacaddrをbroadcastaddrとしてもよい、それでも変わらない。ただし型を変えるのはだめ。
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
    Serial.printf("Last Packet Recv Data(%d): ", len);  // %dは符号あり整数を表示、ここで矛盾があるのだが、lenは符号なしの8bit型の整数なのに出力は可能なのか？？→lenが正の値なので代入しても大丈夫
  #endif

  //データ受信
  for (i = 0; i < len; ++i) {
    command[i] = data[i]; // 43行目で定義されている配列0~7に44行目の配列の値を代入　dataの値ってどこに入ってる？？→これはOnDataRecvの*dataのことであり、これはポインタなので43行目のdata配列に格納される、もう一つの疑問としてはintの配列にuint8_tは代入できるの？？→intは大枠なのでuint8_tを代入することは可能
    #ifdef DEBUG
      Serial.print(data[i]);  // data[i]を出力して下の行でスペース出力
      Serial.print(" ");
    #endif
  }
  digitalWrite(led, LOW); // LED消灯（受信を繰り返すことでLEDが高速点滅）
  recvTime = millis();  // ここまでのプログラムの実行時間をrecvTimeに代入、それが受信時刻となる　1行目からプログラムが走ってここまでの時間であってる？？→それで大丈夫
}

uint8_t broadcastAddress[6];  // 符号なし8bit整数型の配列、配列の中身は0~5となっている。
void setup() {
  Serial.begin(115200);               // シリアル通信開始（速度指定）
  Serial.println();                   // 改行出力

  pinMode(pwm1, OUTPUT);              // 羽ばたきモータ出力1に対応するピンを出力モードにする。ピン番号は32行目で12と設定されている
  pinMode(pwm2, OUTPUT);              // 羽ばたきモータ出力2に対応するピンを出力モードにする。ピン番号は33行目で13と設定されている
  pinMode(led, OUTPUT);               // LEDに対応するピンを出力モードにする。
  analogWriteFreq(PWM_FREQ);          // アナログ出力の周波数を指定 PWM_FREQ24行目で定義
  analogWriteRange(PWM_RANGE);        // アナログ出力の範囲を指定 PWM_RANGE25行目で定義

  digitalWrite(led, HIGH);            // LED点灯
  analogWrite(pwm1, PWM_RANGE);       // 羽ばたきを止める　pinMode関数を呼び出して出力に設定する必要はなし　analogWrite(pin, value)　pin出力したいピン番号、デューティ比0(常にオフ)~255(常にオン)　ここで使用可能なデータ型はintのみ　結局ピン番号とその上限値をしていしているのみ
  analogWrite(pwm2, PWM_RANGE);       // 羽ばたきを止める
  
  cog.attach(cog_pin,900,1900);       // 重心移動機構サーボ出力の上限下限を設定　cog_pinは重心移動機構のあるピンの番号
  ladder.attach(ladder_pin,900,1900); // 尾翼サーボ出力の上限下限を設定
  
  cog.write(0);                       // サーボの角度をリセット（0°）重心移動機構の角度 setupだから値を初期値の0に持っていきたい115行目も同様
  ladder.write(0);                    // 尾翼サーボの角度をリセット

  // REPLACE WITH RECEIVER MAC Address
  // 各コントローラのMACアドレス
  if(controller == 'A'){
    broadcastAddress[0] = 0x8C; // 8Cの計算 Cは12であるこれ間違えないように!! 8C=8*16^1+(C=12)=140
    broadcastAddress[1] = 0x4B;
    broadcastAddress[2] = 0x14; // 0x14の計算 0X14=1*16+4*16^0=20
    broadcastAddress[3] = 0x16;
    broadcastAddress[4] = 0x63;
    broadcastAddress[5] = 0x0C; // 表記的な疑問　0xが16進数という意味になるなら0を入れるのはなぜ？？ 0xの後ろには二桁必要なの？？→書式として必要
  }else if(controller == 'B'){
    broadcastAddress[0] = 0xC8; // 0xC8=(C=12)*16^1+8=200
    broadcastAddress[1] = 0x2B;
    broadcastAddress[2] = 0x96;
    broadcastAddress[3] = 0xB9;
    broadcastAddress[4] = 0x69;
    broadcastAddress[5] = 0x54;
  }
  
  #ifdef DEBUG
    Serial.println("-");
    Serial.println("start");

    Serial.print("ESP8266 Board MAC Address:  "); // MAC Adddressの後には次の行が入る
    Serial.println(WiFi.macAddress());  // この上の行のスペースに入るWiFi.macAddress()は何？？この値は→引数は()に何も入らない、けど書式として必要、ないと変数か関数かがわからないのでエラーがはかれる。
  #endif
 
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);  // STA(ステーションモード)で動作、アクセスポイントに接続し、クラウドへデータを送信するのが一般的 wifi機能をステーションモードで起動 ステーションモードとはWi-Fi機器の動作モードの一つで、端末（無線LAN子機）としてWi-Fiアクセスポイント（AP）に接続するモード アクセスポイントとは無線でスマートフォン、ノートパソコン、ゲーム機といった複数の無線LAN（Wi-Fi）機能付きの端末を、家庭内LANに接続するための機械 

  // Init ESP-NOW
  if (esp_now_init() != 0) {  // esp_now_init()はincludeでESP8266WiFi.hをやっているのでそこに含まれているから定義しなくても使用可能　そもそもesp_now_intit()はwifi機能を使用　もしesp_now_init()は0でないなら下のエラー文を出力
    #ifdef DEBUG
      Serial.println("Error initializing ESP-NOW");
    #endif
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER); // set self roleってことは役割を決めてる？？その役割とは？？　上のCBとは何を示しているの？←これ不明保留
  //esp_now_register_send_cb(OnDataSent); Esp-nowコールバック登録のsendの方　コメントアウトしている理由は？←これはOnDataSent関数がコメントの出力しかしないのでコメントアウトしている。また163行目の受信のほうはLEDの点滅として使用するのでこちらはコメントアウトせず
  
  // Register peer peerとはネットワーク通信において接続している相手のコンピューターや通信機器のこと。なのでこれを登録するということ
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0); // 引数何を取っている?? 保留

  // 受信コールバック関数の指定
  esp_now_register_recv_cb(OnDataRecv); // 引数には受信のコールバック関数を用いる

  #ifdef sensor
    if(!bno.begin()){ // センサを!bno.begin()でセンサの初期化を行う　ただ#define sensorをコメントアウトするとセンサが使えなくなってしまう
      /* There was a problem detecting the BNO055 ... check your connections */ //BNO055とは角度センサのこと
      #ifdef DEBUG
        Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
      #endif
      digitalWrite(led, HIGH);  // この下にwhile(1)があるのでこのライトは光り続ける、なぜならwhile(1)でコードが終わることはないから
      while(1); //ここで無限ループする意味とは？？→これは失敗したら待機するようなもの、失敗しているのでコードを続けたくない、つまりコードをそこのままでとどめておきたいということ。
    }
  #endif

  // 通信の初期設定に成功したら、LED(オレンジ?)を消す。
  digitalWrite(led, LOW);
}

//float型用のmap関数を自作
float mapfloat(float x, long in_min, long in_max, long out_min, long out_max) // 型名をfloatで宣言、関数名がmapfloat floatとは実数を扱うことのできるデータ型　ここでの実数は整数型と比べて値の桁数が多く少数も扱えるような数値となっている　引数mapfloat(変換したい数値、現在の範囲の下限、現在の範囲の上限、変換後の範囲の下限、変換後の範囲の上限) float型なのにその数値の現在の範囲の下限と上限がlong型とは？？　floatが少数も扱える変数型なのでlongで定義してもよいということ？？　保留して後で出てきた場合に確認 floatは4byte=16bitでありlong int(long)型も4byte=16bitであるのでもし今回の範囲が負になることはないから大枠というfloatの中にlong intがあるので変換したい変数がfloatでその範囲がlong intとなることは可能である。 http://www.isc.meiji.ac.jp/~mcelab/www_jyo_en2/jyo_jissu_2_cast.htm
{
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}
 
void loop() {

  #ifdef sensor
    // Possible vector values can be:
    // - VECTOR_ACCELEROMETER - m/s^2
    // - VECTOR_MAGNETOMETER  - uT (マイクロテスラ)　1μTとは5Aの電流が流れている電線から1m離れた場所での磁界の大きさを表している　Magnetometer:磁力計
    // - VECTOR_GYROSCOPE     - rad/s ジャイロスコープ
    // - VECTOR_EULER         - degrees
    // - VECTOR_LINEARACCEL   - m/s^2
    // - VECTOR_GRAVITY       - m/s^2
    //imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);　センサーフュージョンによる方向推定値の取得
    imu::Quaternion quaternion = bno.getQuat(); // センサフュージョンの方向推定値のクオータニオン クオータニオンとは四元数と呼ばれ、二次元平面の回転を表現する複数の拡張として、3次元の回転を表現可能
  #endif

  Ti = millis();              // 現在時刻
  loopTi = Ti - lastTime;     // 前回受信からの時間差 // 239行目でlastTime更新、最初はlastTime=0となっている
  if (loopTi > timerDelay) {  // timerDelay=20よりも大きければif文が走る
    // Set values to send
    // 送信データを準備
    data[0] = command[0];     // 羽ばたき出力1     43行目でcommandの配列が定義されている、dataを送信するため86行目において43行目でポインタによりdata配列に格納されたcommandの値を各データに代入
    data[1] = command[1];     // 羽ばたき出力2
    data[2] = command[2];     // 尾翼サーボ角度
    data[3] = command[3];     // 重心移動機構角度
    #ifdef sensor
      data[5] = (quaternion.w()+1)*100;
      data[6] = (quaternion.x()+1)*100;
      data[7] = (quaternion.y()+1)*100;
      data[8] = (quaternion.z()+1)*100;
    #else
      data[5] = 0; // 86行目でデータを受信する際にdata[]はcommand[]に代入したのでいまはdata[5~8]には値がないため、これに0を代入
      data[6] = 0;
      data[7] = 0;
      data[8] = 0;
    #endif
    data[4] = loopTi;         // 受信間隔 201行目でloopTi=Ti-lastTimeとなっている loop文の中でloopTiとTiとlastTimeが代入されていくので結局受信間隔は変わらない
    #ifdef DEBUG
      //Serial.print("y:");　センサを初めから使用すると考えていないのかもしれないなのでEuler角のxが存在しない？？
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

    //　機体の状態をコントローラに送信
    esp_now_send(broadcastAddress, (uint8_t *) &data, sizeof(data));  // OnDataRecv関数に送信され、OnDataRecv関数が受信したらその関数が走る、また送信の成功によってOnDatasent関数も走る
    lastTime = millis();  // 今までのコードが走った時間をlastTimeに書きこむ
  }
  /*
  if ((Ti - recvTime) > watchdogtime){　Ti(現在時刻)からrecvTime(受信時刻)を引いたものがタイマよりも大きいと暴走している可能性があるので
    digitalWrite(led, HIGH);　LEDを光らせる
    analogWrite(pwm1, 0);　羽ばたき出力モータ1を0にする
    analogWrite(pwm2, 0);　羽ばたき出力モータ2を0にする
  }
  */
  //受信データに基づき各出力を変更
  analogWrite(pwm1, command[0]);  // 205~208でcommand[0~3]はdata[0~3]に代入しているが、それによってcommandの値は消えないから大丈夫!!、入れ替えの場合は上書きとなってしまう。
  analogWrite(pwm2, command[1]);
  ladder.write(command[2]); // 尾翼サーボ角度
  cog.write(command[3]);  // 重心移動機構角度
  
  //delay(50); wait for a second
}