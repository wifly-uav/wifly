import numpy as np
from PIL import Image, ImageDraw, ImageFont

circle_size = 60
nn_layer = 4
weight_bias = 25
b_bias = 30

th_max = 1000
th_min = 0

W_fc1 = np.loadtxt('debug_W_fc1.csv', delimiter=',')
W_fc2 = np.loadtxt('debug_W_fc2.csv', delimiter=',')
W_out = np.loadtxt('debug_W_out.csv', delimiter=',')
input_layer = W_fc1.shape[0]
middle_layer_1 = W_fc1.shape[1]
middle_layer_2 = W_fc2.shape[1]
output_layer = W_out.shape[1]

b_fc1 = np.loadtxt('debug_b_fc1.csv', delimiter=',')
b_fc2 = np.loadtxt('debug_b_fc2.csv', delimiter=',')
b_out = np.loadtxt('debug_b_out.csv', delimiter=',')

#position
input = np.zeros((input_layer,2))
middle_1 = np.zeros((middle_layer_1,2))
middle_2 = np.zeros((middle_layer_1,2))
output = np.zeros((output_layer,2))

im = Image.new("RGB", (5120,2700), (128,128,128))
draw = ImageDraw.Draw(im)

width_x = im.width/nn_layer
start_x = width_x/2-circle_size/2



#input_layer
height = im.height/input_layer
width = start_x
for i in range (input_layer):
    draw.ellipse((width, height*(i+0.5)-circle_size/2, width+circle_size, height*(i+0.5)+circle_size-circle_size/2), fill=(0, 255, 0))
    input[i][0] = width+circle_size/2
    input[i][1] = height*(i+0.5)+circle_size/2-circle_size/2
#print(input)
#print(input[0][0])

#middle_layer_1
height = im.height/middle_layer_1
width = start_x+width_x*1
for i in range (middle_layer_1):
    circle_size_1 = circle_size + b_fc1[i]*b_bias
    #print(b_fc1[i])
    draw.ellipse((width, height*(i+0.5)-circle_size_1/2, width+circle_size_1, height*(i+0.5)+circle_size_1-circle_size_1/2), fill=(0, 255, 0))
    middle_1[i][0] = width+circle_size_1/2
    middle_1[i][1] = height*(i+0.5)+circle_size_1/2-circle_size_1/2

#middle_layer_2
height = im.height/middle_layer_2
width = start_x+width_x*2
for i in range (middle_layer_2):
    circle_size_2 = circle_size + b_fc2[i]*b_bias
    #print(b_fc2[i])
    draw.ellipse((width, height*(i+0.5)-circle_size_2/2, width+circle_size_2, height*(i+0.5)+circle_size_2-circle_size_2/2), fill=(0, 255, 0))
    middle_2[i][0] = width+circle_size_2/2
    middle_2[i][1] = height*(i+0.5)+circle_size_2/2-circle_size_2/2

#output_layer
height = im.height/output_layer
width = start_x+width_x*3
for i in range (output_layer):
    circle_size_output = circle_size + b_out[i]*b_bias
    #print(b_out[i])
    draw.ellipse((width, height*(i+0.5)-circle_size_output/2, width+circle_size_output, height*(i+0.5)+circle_size_output-circle_size_output/2), fill=(0, 255, 0))
    output[i][0] = width+circle_size_output/2
    output[i][1] = height*(i+0.5)+circle_size_output/2-circle_size_output/2



#line_input_to_middle_1
for i in range (input_layer):
    for j in range (middle_layer_1):
        if abs(int(W_fc1[i][j]*weight_bias)) < th_max:
            if abs(int(W_fc1[i][j]*weight_bias)) > th_min:
                if W_fc1[i][j] > 0.0:
                    draw.line((input[i][0], input[i][1], middle_1[j][0], middle_1[j][1]), fill=(255, 0, 0), width=int(W_fc1[i][j]*weight_bias))
                else:
                    draw.line((input[i][0], input[i][1], middle_1[j][0], middle_1[j][1]), fill=(0, 0, 255), width=-int(W_fc1[i][j]*weight_bias))


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
height = im.height/input_layer
width = start_x
for i in range (input_layer):
    draw.ellipse((width, height*(i+0.5)-circle_size/2, width+circle_size, height*(i+0.5)+circle_size-circle_size/2), fill=(0, 255, 0))
    input[i][0] = width+circle_size/2
    input[i][1] = height*(i+0.5)+circle_size/2-circle_size/2
#print(input)
#print(input[0][0])

#middle_layer_1
height = im.height/middle_layer_1
width = start_x+width_x*1
for i in range (middle_layer_1):
    circle_size_1 = circle_size + b_fc1[i]*b_bias
    #print(b_fc1[i])
    draw.ellipse((width, height*(i+0.5)-circle_size_1/2, width+circle_size_1, height*(i+0.5)+circle_size_1-circle_size_1/2), fill=(0, 255, 0))
    middle_1[i][0] = width+circle_size_1/2
    middle_1[i][1] = height*(i+0.5)+circle_size_1/2-circle_size_1/2

#middle_layer_2
height = im.height/middle_layer_2
width = start_x+width_x*2
for i in range (middle_layer_2):
    circle_size_2 = circle_size + b_fc2[i]*b_bias
    #print(b_fc2[i])
    draw.ellipse((width, height*(i+0.5)-circle_size_2/2, width+circle_size_2, height*(i+0.5)+circle_size_2-circle_size_2/2), fill=(0, 255, 0))
    middle_2[i][0] = width+circle_size_2/2
    middle_2[i][1] = height*(i+0.5)+circle_size_2/2-circle_size_2/2

#output_layer
height = im.height/output_layer
width = start_x+width_x*3
for i in range (output_layer):
    circle_size_output = circle_size + b_out[i]*b_bias
    #print(b_out[i])
    draw.ellipse((width, height*(i+0.5)-circle_size_output/2, width+circle_size_output, height*(i+0.5)+circle_size_output-circle_size_output/2), fill=(0, 255, 0))
    output[i][0] = width+circle_size_output/2
    output[i][1] = height*(i+0.5)+circle_size_output/2-circle_size_output/2

im.show()
im.save('nn.jpg', quality=100)