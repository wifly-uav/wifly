using UnityEngine;
using UnityEngine.SceneManagement;
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Collections;
using System.Collections.Generic;

public class Com{
    static System.Net.Sockets.NetworkStream ns;
    static System.Net.Sockets.TcpClient tcp;    
    public const int BufferSize = 1024;
    public byte[] Buffer { get; } = new byte[BufferSize];
    public void sta(){
        int LOCA_LPORT = 50007;
        //サーバーのIPアドレスとポート番号
        string ipOrHost = "localhost";
        //TcpClientを作成し、サーバーと接続
        tcp = new System.Net.Sockets.TcpClient(ipOrHost, LOCA_LPORT);
        Debug.Log("サーバー({0}:{1})と接続しました。" + 
            ((System.Net.IPEndPoint)tcp.Client.RemoteEndPoint).Address + "," + 
            ((System.Net.IPEndPoint)tcp.Client.RemoteEndPoint).Port + "," +
            ((System.Net.IPEndPoint)tcp.Client.LocalEndPoint).Address + "," +
            ((System.Net.IPEndPoint)tcp.Client.LocalEndPoint).Port);
        //NetworkStreamを取得
        ns = tcp.GetStream();
        //tcp.Client.BeginReceive(this.Buffer, 0, BufferSize, SocketFlags.None, new AsyncCallback(ReceiveCallback), null);
    }
    private void ReceiveCallback(IAsyncResult ar){
        //データ受信終了
        int len = tcp.Client.EndReceive(ar);
        //受信データ取り出し
        byte[] rcvBuff = (byte[])ar.AsyncState;
        System.IO.MemoryStream ms = new System.IO.MemoryStream();
        //受信したデータを蓄積
        ms.Write(rcvBuff, 0, len);
        //受信したデータを文字列に変換
        System.Text.Encoding enc = System.Text.Encoding.UTF8;
        string Msg = enc.GetString(ms.GetBuffer(), 0, (int)ms.Length);
        ms.Close();
        Debug.Log(Msg);
        tcp.Client.BeginReceive(this.Buffer, 0, BufferSize, SocketFlags.None, new AsyncCallback(ReceiveCallback), null);
    }
    public void send(string data){
        //タイムアウト設定
        ns.ReadTimeout = 5000;
        ns.WriteTimeout = 5000;

        //サーバーにデータを送信
        //文字列をByte型配列に変換
        System.Text.Encoding enc = System.Text.Encoding.UTF8;
        byte[] sendBytes = enc.GetBytes(data);
        //データを送信する
        ns.Write(sendBytes, 0, sendBytes.Length);
        //Debug.Log(data);
    }
    public string recv(){
        //タイムアウト設定
        ns.ReadTimeout = 10000;
        ns.WriteTimeout = 10000;
        //サーバーから送られたデータを受信する
        System.IO.MemoryStream ms = new System.IO.MemoryStream();
        byte[] resBytes = new byte[256];
        int resSize = 256;
        //データを受信
        resSize = ns.Read(resBytes, 0, resBytes.Length);
        //受信したデータを蓄積
        ms.Write(resBytes, 0, resSize);
        //受信したデータを文字列に変換
        System.Text.Encoding enc = System.Text.Encoding.UTF8;
        string resMsg = enc.GetString(ms.GetBuffer(), 0, (int)ms.Length);
        ms.Close();
        return resMsg;
    }
}
public class Communicate : MonoBehaviour{
    Com comm = new Com();
    // Start is called before the first frame update
    void Start()    {
        comm.sta();
    }

    // Update is called once per frame
    void Update()
    {
        SceneManager.LoadScene ("wifly");
    }
}
