#include "WiFly_v3_ide.h"		// Additional Header

/* Sub-GHz */
uint8_t tx_data[256];
uint8_t rx_data[256];
SUBGHZ_STATUS rx;
SUBGHZ_MAC_PARAM mac;

#define WAIT_TIME_FOR_EMG_STOP 15000
#define SUBGHZ_CH	28	//36
#define SUBGHZ_PANID	0x0809 // for group cast
#define SUBGHZ_MYADDR	0x0003 // add when not use broadcast
#define SUBGHZ_RXADDR	0x0002 // 
#define SUBGHZ_RATE		100
#define SUBGHZ_PWR		20

#define DATA_FRAME_UNTIL 10

/* Sensor */
bool kxg03_irq = false;

static void kxg03_isr(void){
	kxg03_irq = true;
}

/* Motors */
#define MOTOR_PS	17
#define MOTOR_PWM	2

/* LED */
#define BLUE_LED	26
#define RED_LED     20
#define YELLO_LED   25


int current = 0;
int old = 0;


/* posture parameter */
typedef struct{
	float CurrentPosture;
	float TargetPosture;
} Posture;

Posture pitch;
Posture slope;


/* control parameter */
typedef struct{
	float ControlValue;
	float ControlMode;
} Control;

Control level1;
Control level2;
Control servo;
Control yaw;
Control mode;


/* flight parameter */
typedef struct{
	long current_time;	
	long last_recv_time;
	int length;
	int signal_check;
	bool flight_permission;
} FlyParam;

static FlyParam fly_param;




void Emargency_Stop(){
	Serial.println("Emargency Stop!");
	hhb.write(3,0L);
	hhb.write(2,0L);
	hsv.write(0,0);
	hsv.update();

	fly_param.flight_permission = false;
	digitalWrite(BLUE_LED, LOW);

	return;
}


int Time_Update(void){

	if(fly_param.length > 0){
		fly_param.current_time = millis();
		fly_param.last_recv_time = fly_param.current_time;
		digitalWrite(BLUE_LED, HIGH);
		return 1;
	} else {
		fly_param.current_time = millis();
		if(fly_param.current_time - fly_param.last_recv_time > WAIT_TIME_FOR_EMG_STOP){
			Emargency_Stop();
		}
		return 0;
	}

}


void Signal_Check(){
	fly_param.length = SubGHz.readData(rx_data, sizeof(rx_data));
	fly_param.signal_check = Time_Update();
	SubGHz.decMac(&mac,rx_data,fly_param.length);
	level1.ControlValue = mac.payload[4];	//11
}


void Update_Motor_Data(void){
	SubGHz.decMac(&mac,rx_data,fly_param.length);
	
	fly_param.length = SubGHz.readData(rx_data, sizeof(rx_data));

	level1.ControlValue = mac.payload[4];
	level2.ControlValue = mac.payload[0];
	servo.ControlValue = mac.payload[2];
	//yaw.ControlValue = mac.payload[8];

	mode.ControlMode = mac.payload[6];	//

	return;
}


void Update_Posture_Data_From_Sensor(){
	static float val[16];
	int i;
	SUBGHZ_MSG msg;
	wait_event(&kxg03_irq);
	kxg03.get_angle(val);
	
	old = current;
	current = millis();

	Print.init(tx_data,sizeof(tx_data));

    Print.p("STX");
/*    for (i = 0; i < DATA_FRAME_UNTIL; ++i) {
        Print.d((double)val[i], 2);
        Print.p(",");
    }
    /*
	 val[0] --> kalman pitch
	 val[1] --> kalman roll
	 val[2] --> acc deg
	 val[3] --> acc deg
	 val[4] --> gyro x
	 val[5] --> gyro y
	 val[6] --> gyro z
	 val[7] --> acc x
	 val[8] --> acc y
	 val[9] --> acc z
	*/

	Print.p(",");
	Print.d((double)val[0], 0);		// kalman pitch
	Print.p(",");
	Print.d((double)val[1], 0);		// kalman slope
	Print.p(",");
	Print.d((double)level1.ControlValue, 0);
	Print.p(",");
	Print.d((double)level2.ControlValue, 0);
	Print.p(",");
	Print.d((double)current-old, 0);
	Print.p(",");
	Print.p("ETX");
	//Print.d((double)servo.ControlValue, 2);
	//Print.d((double)yaw.ControlValue, 2);
	/*Print.p(",");
	//ここ謎
	Print.d((double)level1.ControlValue, 2);	
	Print.p(",");
	Print.d((double)servo.ControlValue, 2);
	Print.p(",");
	Print.d((double)yaw.ControlValue, 2);
	Print.p(",");

    Print.p("ETX");*/
    Print.ln();
    //sleep(100);
    Serial.print(tx_data);
	msg = SubGHz.send(SUBGHZ_PANID, SUBGHZ_RXADDR, tx_data, Print.len(), NULL);
	//Serial.print_long((long)msg, DEC);
    return;

}


void Motor_Sets(){

	hsv.write(3, map((long)level1.ControlValue,0L,255L,0L,125L));
	hsv.write(2, map((long)level2.ControlValue,0L,255L,0L,125L));
	hsv.write(1, map((long)yaw.ControlValue,0L,255L,900L,1923L));
	hsv.write(0, map((unsigned short)servo.ControlValue,0L,255L,900L,1923L));
	hsv.update();

	return;
}


void Flight_Preparation_Mode(){

	while(1){

		Signal_Check();

		if(fly_param.signal_check > 0){
			if(level1.ControlValue < 1){
				Serial.println("ready to flight...");
				fly_param.flight_permission = true;
				return;
			} else{
				Serial.println("level1 is not 0!");
			}
		} else {
			Serial.println("preparation error!");
		}
	
	}
}

void Flight_Mode(){
	while(fly_param.flight_permission == true){
		Update_Motor_Data();
		Motor_Sets();
		//delay(100);
		Update_Posture_Data_From_Sensor();
	}
}



void setup() {
  	byte rc;
	SUBGHZ_MSG msg;
	SUBGHZ_PARAM param;

	// initializing fly_param
	fly_param.length = 0;
	fly_param.current_time = 0;
	fly_param.last_recv_time = 0;
	fly_param.signal_check = 0;
	fly_param.flight_permission = false;


	Serial.begin(115200);

	// initializing LED
	pinMode(BLUE_LED, OUTPUT);
	digitalWrite(BLUE_LED, HIGH);

	// Motor LES Setting
	//digitalWrite(MOTOR_PWM, LOW);
	//digitalWrite(MOTOR_PS, HIGH);

	//pinMode(MOTOR_PWM, LOW);
	//pinMode(MOTOR_PS, HIGH);

	// Servo Motor API Initializings
	level1.ControlValue = 0;
	level2.ControlValue = 0;
	servo.ControlValue = 0;
	yaw.ControlValue = 0;

	hsv.init(2,24000);	//servo
	hsv.attach(0,6);
	hsv.attach(1,7);
	hsv.write(0,(unsigned short)map(0L,-512L,511L,900L,1900L));
	hsv.write(1,1);
	hsv.start(); 
	
	hsv.init(3,125);	//DCmotor1
	hsv.attach(3,3);
	hsv.write(3,0L);
	hsv.start(3);

	hsv.init(1,24000);	//servo2
	hsv.attach(1,5);
	hsv.write(0,(unsigned short)map(0L,-512L,511L,900L,1900L));
	hsv.write(1,0L);
	hsv.start(1);

	hsv.init(2,1023);	//DCmotor2
	hsv.attach(2,8);
	hsv.write(2,0L);
	hsv.start(2);

	// Initializing sensor
	Wire.begin();
	rc = kxg03.sync_init(KXG03_DEVICE_ADDRESS_4E, KXG03_ODR_25HZ,kxg03_isr);
	//rc = bm1422.init(0); //磁気センサ
	//rc = bm1383.init(0); //気圧センサ

	kxg03.angle_init(KXG03_MODE_PR | KXG03_MODE_KALMAN ,3,2,1,2,-3,-1);
	kxg03.set_acc_out(true);
	kxg03.set_gyro_out(true);
	kxg03.set_kalman_out(true);
	kxg03.set_deg_out(true);


	// Initializing Sub-GHz
	msg = SubGHz.init();
	if(msg != SUBGHZ_OK){
		SubGHz.msgOut(msg);
		while(1){}
	}

	
	SubGHz.setMyAddress(SUBGHZ_MYADDR);
	SubGHz.setBroadcastEnb(false);
 	SubGHz.setAckReq(false);
	

	msg = SubGHz.begin(SUBGHZ_CH, SUBGHZ_PANID, SUBGHZ_100KBPS, SUBGHZ_PWR_20MW);
	if(msg != SUBGHZ_OK){
		SubGHz.msgOut(msg);
		while(1){}
	}

	// Change SubGHz mode to non-ack(AddrMode = 4)
	SubGHz.getSendMode(&param);
	param.addrType = 4;
	SubGHz.setSendMode(&param);

	// Enabling RX
	msg = SubGHz.rxEnable(NULL);
	if(msg != SUBGHZ_OK){
		SubGHz.msgOut(msg);
		while(1){}
	}

	// SubGHz initialisation end

	return;
}

	
void loop() {
	Flight_Preparation_Mode();
	Flight_Mode();
}
