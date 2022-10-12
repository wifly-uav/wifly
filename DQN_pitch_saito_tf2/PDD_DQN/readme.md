# Communication.py
## Description
ラズライトとの通信用
## API
* init(self)

通信ポートの指定
* start_laz(self, data_to_send)

キャッシュを削除

data_to_sendをラズライトに送信
* create_log(self, persed_data,  time)

不要？
* save_communicate_log(self)

不要？
* recieve_from_laz(self, mode=False, byt=7)


* send_to_laz(self, data_to_send)

data_to_sendをラズライトに送信
* termination_switch(self, deta_to_send)

キー入力　tで1　yで0を返す

動作しない
* serial_close(self)

通信ポートの解除