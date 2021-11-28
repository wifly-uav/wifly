using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;


public class master : MonoBehaviour
{  
    Com communicate = new Com();
    public GameObject obj;
    private GameObject[] agent;
    private wifly[] num;
    int obj_count = 1;
    int[] flg = new int[5];
    

    public string data;
    public float pow,pow_up;
    public float ang,len;
    public float x,yaw;
    public int reset;
    public Quaternion quaternion;
    public float nowTime;
    public float p_gain=0.2f;
    public float err;

    // Start is called before the first frame update
    void Start()
    {            
        agent = new GameObject[obj_count];
        num = new wifly[obj_count];
        for(int i=0; i<obj_count; i++){
            flg[i] = 0;
        }
    }

    // Update is called once per frame
    void Update()
    {
        for(int i=0; i<obj_count; i++){
            
            //Debug.Log(flg[i]);
            if(flg[i]==0){
                agent[i] = Instantiate(obj, new Vector3(0,10,-15*i), Quaternion.identity);
                agent[i].SetActive(true);
                num[i] = agent[i].GetComponent<wifly>();
                num[i].hedder = i;
                num[i].Cube = agent[i].transform.GetChild(3).gameObject;
                num[i].Car = agent[i].transform.GetChild(2).gameObject;
                num[i].rb_Car =  num[i].Car.GetComponent<Rigidbody>();
            }
            flg[i] = 1;

            x = num[i].Car.transform.position.x;
            quaternion = num[i].Cube.transform.rotation;
            yaw = quaternion.eulerAngles.z;
            len = (float)x;
            ang = (float)yaw;
            err = 180-ang;
            nowTime += Time.deltaTime;
            //Debug.Log(Time.deltaTime);
            reset = 0;
            if(len>17.0f || len<-17.0f){
                reset = 1;
            }else{
                reset = 0;
            }
            if(err>90 || err<-90){
                reset = 1;
            }

            data = len.ToString("F2") + "," + err.ToString("F2") + "," + Time.deltaTime.ToString("F3") + "," + reset.ToString();// +","+num[i].hedder.ToString();
            communicate.send(data);
            //Debug.Log(data);

            var rec = communicate.recv();
            string[] action = rec.Split(',');
            Debug.Log(rec);
            //Debug.Log(nowTime);
            //Debug.Log(action[1].GetType());
            pow = float.Parse(action[1]);
            //Debug.Log(pow);
            //if(int.Parse(action[1])==1)
            if (reset == 1){ 
                //Debug.Log("Destroy");
                Destroy (agent[i].gameObject);
                flg[i] = 0;
                //SceneManager.LoadScene ("wifly");
            }else if(int.Parse(action[4])==1){
                UnityEditor.EditorApplication.isPlaying = false;
            }else{
                //num[i].rb_Car.AddForce(num[i].Car.transform.right * pow, ForceMode.Impulse);
                num[i].rb_Car.AddForce(num[i].rb_Car.transform.right * pow, ForceMode.Force);
                //pos = num[i].Car.transform.position;
                //pos.x = pos.x + pow*0.1f;
                //num[i].Car.transform.position =  pos;
                flg[i] = 1;
            }

        }        
    }
}
