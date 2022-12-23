import time
import random as rd
import math

class calc_PID():
    """
    PIDの計算をするクラス
    """
    def __init__(self, saturations):
        """
        初期化

        Args:
            saturations (list): [出力の下限値 , 出力の上限値]
        """
        self.__lower_saturation = saturations[0]    #出力下限
        self.__upper_saturation = saturations[1]    #出力上限
        
        #各種初期化
        self.__error_P = 0                          
        self.__error_I = 0
        self.I = 0
        self.__error_D = 0
        self.__error = 0
        self.__target = 0
        self.__old_out = 0
        self.__last_update = time.time()

        self.__dyaw_lim = 0
        self.__dyaw_ = 0

    def updata_trajectory(self, param):
        self.__dyaw_lim = param[0]
        self.__dyaw_ = param[1]

    def update_params(self, param):
        """
        PIDパラメータを更新する関数

        Args:
            param (list): [P , I , D , target]
        """
        self.__param_P = param[0]
        self.__param_I = param[1]
        self.__param_D = param[2]
        self.__target = param[3]

    def get_i(self):
        return int(self.__param_I * self.__error_I)

    def trajectory(self, yaw, dyaw, dt):
        #TODO 
        over = -1*yaw*dyaw
        dt_ = dt*0.001
        yaw_ = abs(yaw)
        dyaw_ = abs(dyaw)
        if over<0:
            t_ = dyaw_/self.__dyaw_lim
            t__ = self.__dyaw_/self.__dyaw_lim
            t = (yaw_+dyaw_*t_/2-self.__dyaw_*(t__)/2-self.__dyaw_**2/(2*self.__dyaw_lim))/self.__dyaw_
        else:
            t = (yaw_-(self.__dyaw_**2-dyaw_**2)/(2*self.__dyaw_lim)-self.__dyaw_**2/(2*self.__dyaw_lim))/self.__dyaw_
        if t>0:
            mode = 0
            t2 = 0
        else:
            t3 = dyaw_/self.__dyaw_lim
            if over<0:
                mode = 1
            else:
                if yaw_-dyaw_**2/(2*self.__dyaw_lim)<0:
                    mode = 2
                else:
                    t2=math.sqrt((yaw_-dyaw_**2/(2*self.__dyaw_lim))/self.__dyaw_lim)
                    mode = 1
        #print(str(yaw_)+","+str(dyaw_)+","+ str((self.__dyaw_**2-dyaw_**2)/(2*self.__dyaw_lim))+ ","+ str(self.__dyaw_*t)+ ","+str(self.__dyaw_**2/(2*self.__dyaw_lim))+","+str((self.__dyaw_-dyaw_)/self.__dyaw_lim)+","+str(t)+","+str(t2)+","+str(self.__dyaw_/self.__dyaw_lim)+","+str(mode))
        if mode == 0:
            if dyaw_>self.__dyaw_:
                omega = min(self.__dyaw_,dyaw_-self.__dyaw_lim*dt_)
                mode_ = 0
            else:
                omega = min(self.__dyaw_,dyaw_+self.__dyaw_lim*dt_)
                mode_ = 1
        elif mode == 1:
            if over<0:
                t2=math.sqrt((yaw_+dyaw_*t_/2)/self.__dyaw_lim)
                if dt_<t2:
                    omega = -dyaw_+self.__dyaw_lim*dt_
                    mode_ = 2
                elif dt_<t_+2*t2:
                    omega = -dyaw_+self.__dyaw_lim*(t_+t2)-self.__dyaw_lim*(dt_-t_-t2)
                    mode_ = 3
                else:
                    omega = 0
                    mode_ = 4
            else:
                if dt_<t2-dyaw_/self.__dyaw_lim:
                    omega = dyaw_+self.__dyaw_lim*dt_
                    mode_ = 5
                elif dt_<2*t2-dyaw_/self.__dyaw_lim:
                    omega = dyaw_+self.__dyaw_lim*(t2-dyaw_/self.__dyaw_lim)-self.__dyaw_lim*(dt_-t2+dyaw_/self.__dyaw_lim)
                    mode_ = 6
                else:
                    omega = 0
                    mode_ = 7
        elif mode == 2:
            if dt_>t3:
                omega = 0
                mode_ = 8
            else:
                omega = dyaw_-self.__dyaw_lim*dt_
                mode_ = 9
        if over>=0:
            if dyaw>0:
                omega = omega
            else:
                omega = -1*omega
        else:
            if self.__dyaw_lim*dt_-dyaw<0:
                if dyaw>0:
                    omega = -1*omega
                else:
                    omega = omega
            else:
                if dyaw>0:
                    omega = omega
                else:
                    omega = -1*omega

        #print(str(self.__dyaw_)+","+str(yaw)+","+str(dyaw_)+","+str(dyaw+self.__dyaw_lim*dt_)+","+str(dyaw-self.__dyaw_lim*dt_)+","+str(mode)+","+str(mode_)+","+str(omega))
        return omega


    def calculate_output(self, current_value, delta_time, mode ,d=0):
        """
        PIDの計算をする関数
        位置型PID

        Args:
            current_value (float): 制御したい対象の現在の値
            delta_time ([type]): dt
            mode (bool): Trueの場合、サチュレーションブロックを通します

        Returns:
            int: 出力
        """
        if delta_time < 0 or delta_time > 100:
            delta_time = 50
        error = self.__target - current_value                   #偏差
        self.__error_D = d
        #self.__error_D = (self.__error_P - error)/ delta_time  #D制御はしない（振動が大きすぎて上手く効かないため）
        self.__error_P = error                                  #偏差（__は関数の内部でのみ呼び出されることを意味する。）
        self.__error_I = self.__error_I + error*delta_time      #偏差の蓄積（偏差の積分を長方形の面積を使って近似）
        self.I = self.__error_I                                 #進捗表示の際に、Igainによる操作量を計算するために使う変数
        out = (int)(self.__param_P * self.__error_P + self.__param_I * self.__error_I + self.__param_D * self.__error_D)
        if mode == True:
            out = self.saturation_block(out)
        #print(out)
        #print(str(self.__param_P)+","+str(self.__error)+","+str(self.__param_I)+","+str(self.__error_I)+","+str(self.__target))
        return out

    def calculate_output2(self, current_value, delta_time, mode):
        """
        PIDの計算をする関数
        速度型PID
        出力が長い間、上限値に達している場合に有効なPIDです

        Args:
            current_value (float): 制御したい対象の現在の値
            delta_time ([type]): dt
            mode (bool): Trueの場合、サチュレーションブロックを通します

        Returns:
            int: 出力
        """
        out = self.__old_out + (self.__old_out - self.calculate_output(current_value, delta_time, False))/delta_time
        self.__old_out = out
        if mode == True:
            out = self.saturation_block(out)
        print(out)
        return out

    def calculate_output3(self, current_value, delta_time, mode):
        """
        PIDの計算をする関数
        自動整合、逆解析、Conditioned PI Controller
        出力が長い間、上限値に達している場合に有効なPIDです
        速度型よりも性能がいいっぽいです

        Args:
            current_value (float): 制御したい対象の現在の値
            delta_time ([type]): dt
            mode (bool): Trueの場合、サチュレーションブロックを通します

        Returns:
            int: 出力
        """
        u = self.calculate_output(current_value, delta_time, False)
        du = u - self.saturation_block(u)
        error = current_value - self.__target
        self.__error_D = (current_value - self.__error_P)/ delta_time
        self.__error_P = error
        self.__error_I = self.__error_I + (error-du/(self.__param_P+self.__param_D))*delta_time
        out = int(self.__param_P * self.__error_P + self.__param_I * self.__error_I + self.__param_D * self.__error_D)
        if mode == True:
            out = self.saturation_block(out)
        print(out)
        return out

    def calculate_output4(self, current_value, delta_time, mode):
        """
        PIDの計算をする関数
        微分先行型
        targetを変更した時にDの項が大きくなるキックを防ぐためのPIDです

        Args:
            current_value (float): 制御したい対象の現在の値
            delta_time ([type]): dt
            mode (bool): Trueの場合、サチュレーションブロックを通します

        Returns:
            int: 出力
        """
        error = current_value - self.__target
        self.__error_D = (self.__error_P - error)/ delta_time
        self.__error_P = error
        self.__error_I = self.__error_I + error*delta_time
        out = int(self.__param_P * self.__error_P + self.__param_I * self.__error_I + self.__param_D * self.__error_D)
        if mode == True:
            out = self.saturation_block(out)
        print(out)
        return out


    def saturation_block(self, value):
        """
        出力の上限、下限の設定をする関数

        Args:
            value (int): 出力
        """
        if abs(value) > self.__upper_saturation:
            if value > 0:
                out = self.__upper_saturation
            else:
                out = -1*self.__upper_saturation
        elif abs(value) < self.__lower_saturation:
            if value > 0:
                out = self.__lower_saturation
            else:
                out = -1*self.__lower_saturation
        else:
            out = value
        return out

    def reset_error_I(self):
        """
        Iの偏差をリセットする関数
        """
        self.__error_I = 0

    def anti_windup_error_I(self , upper):
        """
        Iの偏差をアンチワインドアップする関数
        Iの偏差が無駄に蓄積するのを防ぎます
        dtと__Param_Iの値を見ながらupperを決めてください

        Args:
            upper (int): 蓄積の上限
        """
        if self.__error_I > upper:
            self.__error_I = upper