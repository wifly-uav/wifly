import numpy as np
from PIL import Image, ImageDraw, ImageFont
import os

class visual_nn:
    def __init__(self, flag=False, folder='log', max=[255,255,180,9], frame=4, norm=False, mode=None):
        self.flag = flag
        self.folder = folder
        self.max = max
        self.frame = frame
        self.norm = norm
        self.mode = mode

    def visualize(self):
        circle_size = 60
        nn_layer = 4
        weight_bias = 1
        b_bias = 1
        max_line = 30
        max_ell = 10
        rnd_norm = [1,50,1]
        con_norm = 10

        th_max = 10000
        th_min = 0

        if self.mode == "RND":
            W_rnd = np.loadtxt(self.folder + '/debug_W_fc_add.csv', delimiter=',')
            rnd_layer = W_rnd.shape[0]
        elif self.mode == "CON":
            W_con = np.loadtxt(self.folder + '/debug_W_fc_con.csv', delimiter=',')
            con_layer = 1

        W_fc1 = np.loadtxt(self.folder + '/debug_W_fc1.csv', delimiter=',')
        W_fc2 = np.loadtxt(self.folder + '/debug_W_fc2.csv', delimiter=',')
        W_out = np.loadtxt(self.folder + '/debug_W_out.csv', delimiter=',')
        input_layer = W_fc1.shape[0]
        middle_layer_1 = W_fc1.shape[1]
        middle_layer_2 = W_fc2.shape[1]
        output_layer = W_out.shape[1]
        state_val = int(input_layer/self.frame)
        #print("state_val:"+str(state_val))

        max_w = max(W_fc1.max(),W_fc2.max(),W_out.max())
        weight_bias = max_line/max_w

        b_fc1 = np.loadtxt(self.folder + '/debug_b_fc1.csv', delimiter=',')
        b_fc2 = np.loadtxt(self.folder + '/debug_b_fc2.csv', delimiter=',')
        #b_out = np.loadtxt(os.path.join(path,'debug/debug_b_out.csv'), delimiter=',')

        max_b = max(b_fc1.max(),b_fc2.max())
        try:
            b_bias = max_ell/max_b
        except:
            b_bias = 1

        #position
        input = np.zeros((input_layer,2))
        middle_1 = np.zeros((middle_layer_1,2))
        middle_2 = np.zeros((middle_layer_1,2))
        output = np.zeros((output_layer,2))
        if self.mode == "RND":
            rnd_input = np.zeros((rnd_layer,2))
        if self.mode == "CON":
            con_input = np.zeros((con_layer,2))

        im = Image.new("RGB", (10240,5400), (128,128,128))
        draw = ImageDraw.Draw(im)

        width_x = im.width/nn_layer
        start_x = width_x/2-circle_size/2

        #input_layer
        if self.mode == "RND":
            height = im.height/(input_layer+rnd_layer)
        elif self.mode == "CON":
            height = im.height/(input_layer+con_layer)
        else:
            height = im.height/input_layer
        width = start_x
        for i in range (input_layer):
            input[i][0] = width+circle_size/2
            if self.mode == "RND":
                input[i][1] = (height+rnd_layer)*(i+0.5)+circle_size/2-circle_size/2
            elif self.mode == "CON":
                input[i][1] = (height+con_layer)*(i+0.5)+circle_size/2-circle_size/2
            else:
                input[i][1] = height*(i+0.5)+circle_size/2-circle_size/2
        if self.mode == "RND":
            for i in range (rnd_layer):
                rnd_input[i][0] = width+circle_size/2
                rnd_input[i][1] = height*(i+0.5)+circle_size/2-circle_size/2
        if self.mode == "CON":
            for i in range (con_layer):
                con_input[i][0] = width+circle_size/2
                con_input[i][1] = height*(i+0.5)+circle_size/2-circle_size/2
        #print(input)
        #print(input[0][0])

        #middle_layer_1
        height = im.height/middle_layer_1
        width = start_x+width_x*1
        for i in range (middle_layer_1):
            circle_size_1 = circle_size + b_fc1[i]*b_bias
            middle_1[i][0] = width+circle_size_1/2
            middle_1[i][1] = height*(i+0.5)+circle_size_1/2-circle_size_1/2

        #middle_layer_2
        height = im.height/middle_layer_2
        width = start_x+width_x*2
        for i in range (middle_layer_2):
            circle_size_2 = circle_size + b_fc2[i]*b_bias
            middle_2[i][0] = width+circle_size_2/2
            middle_2[i][1] = height*(i+0.5)+circle_size_2/2-circle_size_2/2

        #output_layer
        height = im.height/output_layer
        width = start_x+width_x*3
        for i in range (output_layer):
            circle_size_output = circle_size# + b_out[i]*b_bias
            output[i][0] = width+circle_size_output/2
            output[i][1] = height*(i+0.5)+circle_size_output/2-circle_size_output/2
        
        #line_input_to_middle_1
        if self.norm:
            for i in range (input_layer):
                weight_bias_ = abs(self.max[i%state_val])
                for j in range (middle_layer_1):
                    W_fc1[i][j] = W_fc1[i][j]*weight_bias_
            if self.mode == "RND":
                for i in range (rnd_layer):
                    weight_bias_ = abs(rnd_norm[i])
                    for j in range (middle_layer_1):
                        W_rnd[i][j] = W_rnd[i][j]*weight_bias_
            elif self.mode == "CON":
                for i in range (con_layer):
                    weight_bias_ = abs(con_norm)
                    for j in range (middle_layer_1):
                        W_con[j] = W_con[j]*weight_bias_

            if self.mode == "RND":
                max_w1 = max(W_fc1.max(),W_rnd.max())
            elif self.mode == "CON":
                max_w1 = max(W_fc1.max(),W_con.max())
            else:
                max_w1 = W_fc1.max()
            weight_bias1 = max_line/max_w1
        else:
            weight_bias1 = weight_bias
        for i in range (input_layer):
            for j in range (middle_layer_1):
                if W_fc1[i][j] > 0.0:
                    draw.line((input[i][0], input[i][1], middle_1[j][0], middle_1[j][1]), fill=(255, 0, 0), width=int(W_fc1[i][j]*weight_bias1))
                else:
                    draw.line((input[i][0], input[i][1], middle_1[j][0], middle_1[j][1]), fill=(0, 0, 255), width=-int(W_fc1[i][j]*weight_bias1))
        
        if self.mode == "RND":
            for i in range (rnd_layer):
                for j in range (middle_layer_1):
                    if W_rnd[i][j] > 0.0:
                        draw.line((rnd_input[i][0], rnd_input[i][1], middle_1[j][0], middle_1[j][1]), fill=(255, 0, 0), width=int(W_fc1[i][j]*weight_bias1))
                    else:
                        draw.line((rnd_input[i][0], rnd_input[i][1], middle_1[j][0], middle_1[j][1]), fill=(0, 0, 255), width=-int(W_fc1[i][j]*weight_bias1))
        elif self.mode == "CON":
            for i in range (con_layer):
                for j in range (middle_layer_1):
                    if W_con[j] > 0.0:
                        draw.line((con_input[i][0], con_input[i][1], middle_1[j][0], middle_1[j][1]), fill=(255, 0, 0), width=int(W_fc1[i][j]*weight_bias1))
                    else:
                        draw.line((con_input[i][0], con_input[i][1], middle_1[j][0], middle_1[j][1]), fill=(0, 0, 255), width=-int(W_fc1[i][j]*weight_bias1))

        #line_middl1_1_to_middle_2
        for i in range (middle_layer_1):
            for j in range (middle_layer_2):
                if abs(int(W_fc2[i][j]*weight_bias)) < th_max:
                    if abs(int(W_fc2[i][j]*weight_bias)) > th_min:
                        if W_fc2[i][j] > 0.0:
                            draw.line((middle_1[i][0], middle_1[i][1], middle_2[j][0], middle_2[j][1]), fill=(255, 0, 0), width=int(W_fc2[i][j]*weight_bias))
                        else:
                            draw.line((middle_1[i][0], middle_1[i][1], middle_2[j][0], middle_2[j][1]), fill=(0, 0, 255), width=-int(W_fc2[i][j]*weight_bias))

        #line_middle_2_to_output
        for i in range (middle_layer_2):
            for j in range (output_layer):
                if abs(int(W_out[i][j]*weight_bias)) < th_max:
                    if abs(int(W_out[i][j]*weight_bias)) > th_min:
                        if W_out[i][j] > 0.0:
                            draw.line((middle_2[i][0], middle_2[i][1], output[j][0], output[j][1]), fill=(255, 0, 0), width=int(W_out[i][j]*weight_bias))
                        else:
                            draw.line((middle_2[i][0], middle_2[i][1], output[j][0], output[j][1]), fill=(0, 0, 255), width=-int(W_out[i][j]*weight_bias))



        #input_layer
        if self.mode == "RND":
            height = im.height/(input_layer+rnd_layer)
        elif self.mode == "CON":
            height = im.height/(input_layer+con_layer)
        else:
            height = im.height/input_layer
        width = start_x
        for i in range (input_layer):
            color = (int)(i/state_val)
            if self.mode == "RND":
                draw.ellipse((width, height*(i+rnd_layer+0.5)-circle_size/2, width+circle_size, height*(i+rnd_layer+0.5)+circle_size-circle_size/2), fill=(int(color*240/self.frame), int((self.frame-color)*240/self.frame), 100))
            elif self.mode == "CON":
                draw.ellipse((width, height*(i+con_layer+0.5)-circle_size/2, width+circle_size, height*(i+con_layer+0.5)+circle_size-circle_size/2), fill=(int(color*240/self.frame), int((self.frame-color)*240/self.frame), 100))
            else:
                draw.ellipse((width, height*(i+0.5)-circle_size/2, width+circle_size, height*(i+0.5)+circle_size-circle_size/2), fill=(int(color*240/self.frame), int((self.frame-color)*240/self.frame), 100))
        if self.mode == "RND":
            for i in range (rnd_layer):
                draw.ellipse((width, height*(i+0.5)-circle_size/2, width+circle_size, height*(i+0.5)+circle_size-circle_size/2), fill=(0, 0, 100))
        if self.mode == "CON":
            for i in range (con_layer):
                draw.ellipse((width, height*(i+0.5)-circle_size/2, width+circle_size, height*(i+0.5)+circle_size-circle_size/2), fill=(0, 0, 100))


        #middle_layer_1
        height = im.height/middle_layer_1
        width = start_x+width_x*1
        for i in range (middle_layer_1):
            circle_size_1 = circle_size + b_fc1[i]*b_bias
            #print(b_fc1[i])
            draw.ellipse((width, height*(i+0.5)-circle_size_1/2, width+circle_size_1, height*(i+0.5)+circle_size_1-circle_size_1/2), fill=(0, 255, 0, 128))


        #middle_layer_2
        height = im.height/middle_layer_2
        width = start_x+width_x*2
        for i in range (middle_layer_2):
            circle_size_2 = circle_size + b_fc2[i]*b_bias
            #print(b_fc2[i])
            draw.ellipse((width, height*(i+0.5)-circle_size_2/2, width+circle_size_2, height*(i+0.5)+circle_size_2-circle_size_2/2), fill=(0, 255, 0))


        #output_layer
        height = im.height/output_layer
        width = start_x+width_x*3
        for i in range (output_layer):
            circle_size_output = circle_size# + b_out[i]*b_bias
            #print(b_out[i])
            draw.ellipse((width, height*(i+0.5)-circle_size_output/2, width+circle_size_output, height*(i+0.5)+circle_size_output-circle_size_output/2), fill=(0, 255, 255))

        if self.flag:
            im.show()
        im.save(self.folder + '/nn.jpg', quality=10)


if __name__ == "__main__":    
    path = os.path.dirname(__file__)
    print('folder name:')
    save_folder = input()
    save_file = os.path.join(path, 'result/syuron/', save_folder)
    print('mode?')
    mode = input()

    vi = visual_nn(flag=True,folder=save_file, norm=True,frame=4,max=[255,255,90,1,50],mode=mode)
    vi.visualize()