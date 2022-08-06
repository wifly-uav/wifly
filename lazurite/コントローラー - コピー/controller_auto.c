#include "controller_auto_ide.h"		// Additional Header


/*--------------------------------------------------------
 * 自動制御を加えたコントローラ用プログラム//旧バージョン
 * 機械学習用コントローラーコード
 --------------------------------------------------------*/

#define LED	26
#define ORANGE_LED	25
#define SUBGHZ_CH	28
#define SUBGHZ_PANID	0x0809 // for group cast
#define SUBGHZ_MYADDR	0x0003
#define SUBGHZ_RXADDR	0x0002


#define FLAPPING_POWER_HORIZONTAL	115
#define ADJUSTABE_RANGE_FLAPPING_POWER_SLIDE 100
#define ADJUSTABE_RANGE_FLAPPING_POWER_STICK 50
#define SERVO_ANGLE_HORIZONTAL 215
#define SERVO_ANGLE_MANUAL 230

#define PIN_AUTO_HORIZONTAL 5
#define PIN_AUTO_HOVERING 6




SUBGHZ_STATUS rx;
uint32_t last_rx=0;

void setup() {
	SUBGHZ_PARAM param;
	SUBGHZ_MSG msg;

	pinMode(7,INPUT_PULLUP);
	pinMode(2,INPUT);
	pinMode(3,INPUT);
	pinMode(4,INPUT_PULLUP);
	pinMode(5,INPUT);
	pinMode(6,INPUT);
	//pinMode(8, INPUT_PULLUP)
    pinMode(LED, OUTPUT);
    pinMode(ORANGE_LED, OUTPUT);

	Serial.begin(57600);
	//Serial.print("Serial started");

    //initializing Sub_GHz 以降のコードについては公式リファレンスを見たらわかる。
    //Serial.print("init start");
	msg = SubGHz.init();
	if(msg != SUBGHZ_OK)
	{
		SubGHz.msgOut(msg);
		while(1){
			Serial.print("init not ok");
			}
	}

    SubGHz.setMyAddress(SUBGHZ_MYADDR);
    SubGHz.setBroadcastEnb(false);
    SubGHz.setAckReq(false);

	SubGHz.getSendMode(&param);
	param.addrType = 4;				//送信するときのアドレスモード
	SubGHz.setSendMode(&param);
	msg = SubGHz.begin(SUBGHZ_CH, SUBGHZ_PANID,  SUBGHZ_100KBPS, SUBGHZ_PWR_20MW);
	if(msg != SUBGHZ_OK)
	{
		SubGHz.msgOut(msg);
		while(1){
		Serial.print("begin not ok");
		}
	}
	msg = SubGHz.rxEnable(NULL);
	if(msg != SUBGHZ_OK)
	{
		SubGHz.msgOut(msg);
		while(1){
		Serial.print("rxEnable not ok");
		}
	}
	//Serial.print("Setup end");
}


short get_stick_Xaxis(){//ジョイスティックの横の値を返す関数　左-->0 真ん中-->128 右-->255

	if(255 - analogRead(A0)/4 < 148 && 255 - analogRead(A0)/4 > 108){//ある程度遊びをもたせてある。真ん中にあるときでも128にならないため。
		return 128;
	}
	else{
		return 255 - analogRead(A0)/4;
	}
}

short get_stick_Yaxis(){//ジョイスティックの縦の値を返す関数　下-->0 真ん中-->128 上-->255
	return 255 - analogRead(A1)/4;
}

short get_flapping_power_left(){//slide volumeの値を返す関数　下-->0 真ん中-->128 上-->255
	return 255 - analogRead(A2)/4;
}

short get_flapping_power_right(){//slide volumeの値を返す関数　下-->0 真ん中-->128 上-->255
	return 255 - analogRead(A2)/4;
}

short get_control_mode(){//トグルスイッチの値を返す関数　奥-->0(ON) 真ん中・下-->1(OFF)
	return digitalRead(4);
}

short get_mode(){
	return digitalRead(7);
}

void reform_packet(short *data_packet){
	int i;
    for(i=0;i<4;i++){
        if(data_packet[i] > 255){
            data_packet[i] = 255;
        } else if(data_packet[i] < 0){
            data_packet[i] = 0;
        }
    }
}

//受信データバイト数が>0のときに受信データを格納
int read_data_from_fly(){
    short rx_len;
    uint8_t rx_data[256];
    SUBGHZ_MAC_PARAM mac;
    rx_len = SubGHz.readData(rx_data, sizeof(rx_data));//受信データバイト数. >0のとき受信データあり
    //Serial.println_long((long)rx_len, DEC);
    if(rx_len>0)
    {
        digitalWrite(LED, LOW);
        SubGHz.getStatus(NULL,&rx);				// get status of rx
        SubGHz.decMac(&mac,rx_data,rx_len);		// 受信したrawデータを各種パラメータに分解し､構造体macに格納する
        Serial.write(mac.payload, mac.payload_len);
        digitalWrite(LED, HIGH);
       return 1;
    }
    else {

    	return 0;
    }
}

void print_mode(short *data_packet){
    Serial.print("O,");
    Serial.print_long((long)get_mode(), DEC);
    /*
    Serial.print(",");
    Serial.print_long((long)data_packet[0], DEC);
    Serial.print(",");
    Serial.print_long((long)data_packet[1], DEC);
    Serial.print(",");
    Serial.print_long((long)data_packet[2], DEC);
    Serial.print(",");
    Serial.print_long((long)data_packet[3], DEC);
    */
    Serial.print(",N");
    Serial.println("");
}

void print_current_input(short *data_packet){
    Serial.print("Y:");
    Serial.print_long((long)data_packet[0], DEC);
    Serial.print(" ,S:");
    Serial.print_long((long)data_packet[1], DEC);
    Serial.print(" ,Pr:");
    Serial.print_long((long)data_packet[2], DEC);
    Serial.print(" ,M:");
    Serial.print_long((long)data_packet[3], DEC);
    Serial.println("");
}

void recieve_value_from_PC(short *data_packet){
	int i = 0;
	int data;
	int err_count = 0;
	int err_count2 = 0;
	while(1){
		if(err_count > 1000){
			return;
		}
		//Serial.read()の仕様
		//受信したシリアルデータの最初の1バイト．データが利用可能でない場合はint型の -1 を返す
		//data_packet[0]:header
		data = Serial.read();
		if(data == 255){
			for(i = 0; i <4; i++){
				while(1){
					//data_packet[1~3]:
					data = Serial.read();
					err_count ++;
					if(data >= 0){break;}
					if(err_count2 > 1000){
						data = 0;
						break;
					}
				}
				data_packet[i] = (short)data;
			}
			Serial.flush();
			return;
		}
		else {
			Serial.flush();
			return;
			}

		err_count ++;
		}
}

void loop() {
	short data_packet[4];

	//uint32_t now;
	unsigned long last_rx;

	//millis():プログラムの実行を開始した時から現在までの時間をミリ秒単位で返します
	last_rx = millis();

	while (1) {
		//now = millis();
		if (read_data_from_fly() == 1) {
			//data_packetに値代入
			//手動操作？
			if (get_control_mode() == 1) {
				data_packet[0] = get_flapping_power_right()+((get_stick_Xaxis()-128)*2);    //slidevolume + joystick 横 右翼
				data_packet[1] = SERVO_ANGLE_MANUAL + (128 - get_stick_Yaxis()) ;//elevator 
				data_packet[2] = get_flapping_power_left()-((get_stick_Xaxis()-128)*2);    //slidevolume + joystick 横 左翼
				data_packet[3] = get_control_mode(); //get value from mode switch
				reform_packet(&data_packet); //data_packet[i] の中身が255 以上--> 255 ,0以下--> 0
			}
			//自動制御？
			else if(get_control_mode() == 0){
				//Python側からの値受け取り
				recieve_value_from_PC(&data_packet);
				
				data_packet[1] = SERVO_ANGLE_MANUAL + (128 - get_stick_Yaxis()) ;//elevator 
				//羽ばたきの強さを学習[0][2]
				//control_modeを意味する[3]は0にする
				//data_packet[0] = get_flapping_power_right()+((get_stick_Xaxis()-128)/4);    //slidevolume + joystick 横 右翼
				//data_packet[1] = SERVO_ANGLE_MANUAL + (128 - get_stick_Yaxis()) ;//elevator 
				//data_packet[2] = get_flapping_power_left()-((get_stick_Xaxis()-128)/4);    //slidevolume + joystick 横 左翼
				//data_packet[3] = 0; //control_mode
				reform_packet(&data_packet); //data_packet[i] の中身が255 以上--> 255 ,0以下--> 0
			}

			//制御量の送信
			//data_packet[2] = get_flapping_power();
			SubGHz.send(SUBGHZ_PANID, SUBGHZ_RXADDR, (unsigned char *) &data_packet, sizeof(data_packet),NULL);        // send data
			 //制御量のSerial.print
			//print_mode(&data_packet);
			//print_current_input(data_packet);
			last_rx = millis();

		}

		//通信が5000ms途絶えたとき？　必要なさそうなのでコメントアウト
		//消したら動かなかった！
		
		if (millis() - last_rx > 200) {
			if (get_control_mode() == 1) {
				data_packet[0] = get_flapping_power_right()+((get_stick_Xaxis()-128)*2);   //joystick 横
				data_packet[1] = SERVO_ANGLE_MANUAL + (128 - get_stick_Yaxis()) ;//joystick
				data_packet[2] = get_flapping_power_left()-((get_stick_Xaxis()-128)*2);     //slidevolume
				data_packet[3] = get_control_mode(); //get value from mode switch
				//reform_packet(&data_packet); //data_packet[i] の中身が255 以上--> 255 ,0以下--> 0
			}
			else if(get_control_mode() == 0){
				recieve_value_from_PC(&data_packet);
				//data_packet[3] = get_control_mode();
			}
			
/*
			data_packet[0] = get_stick_Xaxis();    //joystick 横
			data_packet[1] = SERVO_ANGLE_MANUAL + (128 - get_stick_Yaxis()) / 5;//joystick
			data_packet[2] = 0;    //slidevolume
			data_packet[3] = get_control_mode(); //get value from mode switch
*/
			reform_packet(&data_packet); //data_packet[i] の中身が255 以上--> 255 ,0以下--> 0
			
			
		SubGHz.send(SUBGHZ_PANID, SUBGHZ_RXADDR, (unsigned char *) &data_packet, sizeof(data_packet),NULL);        // send data
		//Serial.print("NSF");
		//Serial.println("");
		//print_current_input(data_packet);
		last_rx = millis();		
		}
	}
}
