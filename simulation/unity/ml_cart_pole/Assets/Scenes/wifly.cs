using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using UnityEditor;

// RollerAgent
public class wifly : MonoBehaviour
{ 
    Com communicate = new Com();
/*
    static System.Net.Sockets.NetworkStream ns;
    static System.Net.Sockets.TcpClient tcp;
*/
    public string data;
    public float pow,pow_up;
    public float ang,len;
    public float x,yaw;
    public GameObject Cube;
    public GameObject Car;
    public Rigidbody rb_Car;
    public int reset;
    public Quaternion quaternion;
    public float nowTime;
    public float p_gain=0.2f;
    public float pid_err;

    public int hedder=0;

    void Start(){
        // Make the game run as fast as possible
        //Application.targetFrameRate = 1;
        //rb_Car = Car.GetComponent<Rigidbody>();
        pow = 0.0f;
        reset = 0;
    }
/*/
    // エピソード開始時に呼ばれる
    public void OnEpisodeBegin(){
        targetPosition = 0.0f;
        if (Cube.transform.position.y < 0){
            SceneManager.LoadScene ("wifly");
        }
    }
*/

    void Update(){
/*
        //機体の姿勢
        x = rb_Car.transform.position.x;
        quaternion = Cube.transform.rotation;
        yaw = quaternion.eulerAngles.z;
        len = (float)x;
        ang = (float)yaw;
        pid_err = 180-ang;
        nowTime += Time.deltaTime;
        if(len>17.0f || len<-17.0f){
            reset = 1;
        }else{
            reset = 0;
        }
        if(pid_err>90 || pid_err<-90){
            reset = 1;
        }
        //Debug.Log(ang);
        // 送信データ   data={len,ang,time,reset}
        data = len.ToString("F2")+","+pid_err.ToString("F2")+","+Time.deltaTime.ToString("F3")+","+reset.ToString();
        //Debug.Log(pow);
        communicate.send(data);

        //受信
        var rec = communicate.recv();
        string[] action = rec.Split(',');
        //Debug.Log("right:" + action[1]);
        //Debug.Log(action[1].GetType());
        pow = float.Parse(action[0]);
        if(int.Parse(action[1])==1){
            //Destroy (this.gameObject);
            //SceneManager.LoadScene ("wifly");
        }else{
        //rb_Car.AddForce(Car.transform.right * pow, ForceMode.Impulse);
        rb_Car.AddForce(Car.transform.right * pow, ForceMode.Force);
        }
        
        if(int.Parse(action[2])==1){
            EditorApplication.isPlaying = false;
        }

        //Debug.Log(float.Parse(action[0]));
        
        //Debug.Log(ang);
*/
 /*       
        if(Input.GetKey(KeyCode.Q)){pow=0.0f;}
        if(Input.GetKey(KeyCode.A)){pow=pow+5.0f;}
        if(Input.GetKey(KeyCode.Z)){pow=pow-5.0f;}

		//　経過時間を表示
        if(nowTime<1.0){
            pow_up=5.0f;
            pow = pow_up;
        }else if(nowTime<3.0){
            pow_up=-5.0f;
            pow = pow_up;
        }else if(nowTime<4.75){
            pow_up=5.0f;
            pow = pow_up;
        }else if(nowTime<5.5){
            pow_up=-5.0f;
            pow = pow_up;
        }else if(nowTime<7.0){
            pow_up=0.0f;
            pow = pow_up;
        }else if(nowTime>7.0){
            pow_up=0.0f;
            //pow_up=p_gain*pid_err;
            pow = pow_up;
        }
*/
		//Debug.Log(nowTime);


    }
/*
    void Update(){



        if (Input.GetMouseButtonDown(0)){
            SceneManager.LoadScene ("wifly");
        }


        //スペース押すと閉じる
        if (Input.GetKey(KeyCode.Space))
        {
            SceneManager.LoadScene ("wifly");
        }
        

		if(Input.GetKey(KeyCode.UpArrow)){ang =  1.0f;}
        else if(Input.GetKey(KeyCode.DownArrow)){ang =  -1.0f;}
        else{ang = 0.0f;}
		// 上下キーの状態によって目的ポジションを変更
		targetPosition += ang * 2.0f;

    }
*/
}