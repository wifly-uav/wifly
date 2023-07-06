import time 
import random as rd # randomモジュールをas rdとして使用する

class calc_PID():       #クラスの宣言　クラス名の先頭は大文字でなくもよいの？←命名則だからこれは別に大文字にする必要はない　大文字にしないからと言ってエラーをはくわけではない
    def __init__(self, dic_params):     #コントラクタ（オブジェクトが扱うデータの初期化等を行う。定義名は__init__():で固定
        self.current_value = []         #self.変数　インスタンス変数と呼び、インスタンス（defのこと？）ごとに独立した変数
        self.__target = dic_params["target"]

        self.__param_P = dic_params["P"]
        self.__param_I = dic_params["I"]
        self.__param_D = dic_params["D"]

        self.__error_P = 0
        self.__error_I = 0
        self.__error_D = 0

        self.__error = 0
        self.__target = 0

        self.__delta_t = None
        self.__last_update = time.time()        #time.time() UTC（協定世界時）の1970年1月1日0時0分0秒からの経過秒数を返す。

        self.calculated_output = 0

    def update_params(self, dic_params):
        self.__target = dic_params["target"]
        self.__param_P = dic_params["P"]
        self.__param_I = dic_params["I"]
        self.__param_D = dic_params["D"]

    def update_elapsed_time_from_last_step(self):
        self.__delta_t = time.time() - self.__last_update       #最後に通信してからの経過時間
        self.__last_update = time.time()

    def __calcilate_errors(self, current_value):
        error = current_value - self.__target
        #error = (current_value + 30) - self.__target   #for pitch control
        self.__error_D = (error - self.__error_P)/ self.__delta_t
        self.__error_P = error
        self.__error_I = self.__error_I + error*self.__delta_t

    def calculate_output(self, params, current_value):
        self.update_params(params)
        self.update_elapsed_time_from_last_step()
        self.__calcilate_errors(current_value)
        #out = 108 + int(self.__param_P * self.__error_P + self.__param_I * self.__error_I + self.__param_D * self.__error_D)
        out = int(
            self.__param_P * self.__error_P + self.__param_I * self.__error_I + self.__param_D * self.__error_D)

        print("PID out = "+ str(out))

#        if out > 221:
#           return 221
#        elif out < 40:
#            return 40
#        else:
        return out

    def calculate_output_test(self, params, current_value):
        return rd.randint(0, 200)