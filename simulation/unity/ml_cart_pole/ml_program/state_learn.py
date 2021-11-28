#from Calc_Control import Calc_Control
import numpy as np
from NN import NN
from Logger import logger
import matplotlib.pyplot as plt
import time
import collections
import csv

MODEL_NAME_HEADER = "state_DQN"

if __name__ == "__main__":
    log = logger()
    nn = NN()
    '''
    print('Use saved model? y/n')
    ans_yn = input()
    if (ans_yn == 'y'):
        print('Type model no.')
        nn.load_model(model_path=MODEL_NAME_HEADER + input())
        print('Model load has been done')
    elif(ans_yn == 'n'):
        print('Progam starts without loading a model')
    else:
        print("Type y or n . Quit the program")
    '''
#-------train_data-----------------------------------------------------------
    memory = []
    memory_for_exchange = []
    replay_memory = []

    with open('train/debug_memory.csv') as f:
        reader = csv.reader(f)
        for row in reader:
            memory.append(row)

    for i in range(len(memory)):
        memory_exchange_0 = str(memory[i]).replace("[","")
        memory_exchange_1 = memory_exchange_0.replace("]","")
        memory_exchange_2 = memory_exchange_1.strip("'")
        memory_exchange_3 = memory_exchange_2.split("', '")
        memory_exchange_4 = memory_exchange_3[0].split(",")
        memory_exchange_5 = memory_exchange_3[3].split(",")
        memory_for_exchange.append(list(map(float,memory_exchange_4)))
        memory_for_exchange.append(float(memory_exchange_3[1]))
        memory_for_exchange.append(float(memory_exchange_3[2]))
        memory_for_exchange.append(list(map(float,memory_exchange_5)))
        memory_for_exchange.append(float(memory_exchange_3[5]))

        replay_memory.append(memory_for_exchange)
        memory_for_exchange = []

#-------test_data--------------------------------------------------------------
    memory_ = []
    memory_for_exchange_ = []
    test_memory = []

    with open('test/debug_memory.csv') as f:
        reader = csv.reader(f)
        for row in reader:
            memory_.append(row)

    for i in range(len(memory_)):
        memory_exchange_0 = str(memory_[i]).replace("[","")
        memory_exchange_1 = memory_exchange_0.replace("]","")
        memory_exchange_2 = memory_exchange_1.strip("'")
        memory_exchange_3 = memory_exchange_2.split("', '")
        memory_exchange_4 = memory_exchange_3[0].split(",")
        memory_exchange_5 = memory_exchange_3[3].split(",")
        memory_for_exchange_.append(list(map(float,memory_exchange_4)))
        memory_for_exchange_.append(float(memory_exchange_3[1]))
        memory_for_exchange_.append(float(memory_exchange_3[2]))
        memory_for_exchange_.append(list(map(float,memory_exchange_5)))
        memory_for_exchange_.append(float(memory_exchange_3[5]))

        test_memory.append(memory_for_exchange_)
        memory_for_exchange_ = []

#---------------extraction_data------------------------------------------------
    minibatch_size = 1000

    extraction_data = []
    minibatch_indexes = np.random.randint(0, len(test_memory), minibatch_size)
    # create minibatch dataset
    for j in minibatch_indexes:
        extraction_data.append(test_memory[j])

#--------------train-----------------------------------------------------------
    #print(replay_memory[0])
    times = 1000
    loop = 9
    nn.test_nn(replay_memory=extraction_data)

    for j in range(loop):
        for i in range(times):
            nn.experience_replay(replay_memory=replay_memory, minibatch=8)
        nn.test_nn(replay_memory=extraction_data)

    '''
    for i in range(len(state)):
        a = state[i].replace("[","")
        b = a.replace("]","")
        st = b.split(",")
        state_val.append(list(map(float,st)))
    #state_val[何番目のmemoryか][length, angle]
    '''
    nn.save_model()
#------------log---------------------------------------------------------------
    nn.debug_nn()
    nn.debug_loss()
    nn.debug_loss_total()