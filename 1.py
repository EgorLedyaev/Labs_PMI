import numpy as np
import pandas as pd


class OurNeuralNetwork:
    '''
    - 2 входа
    - 4 нейрона на скрытых слоях
    - выходной слой с 1 нейроном
    - используя relu
    '''
    
    def __init__(self):
        # веса
        self.weights1 = np.random.rand(2, 4)
        self.weights2 = np.random.rand(4, 1)
        
        # смещения
        self.bias1 = np.zeros((1, 4))
        self.bias2 = np.zeros((1, 1))
        
    def feedforward(self, x):
        # x - входные данные
        # x - (n, 2)
        self.layer1 = np.maximum(0, np.dot(x, self.weights1) + self.bias1)
        self.layer2 = np.maximum(0, np.dot(self.layer1, self.weights2) + self.bias2)
        return self.layer2
    
    def backprop(self, x, y_true, y_pred):
        # x - входные данные
        # y_true - правильные ответы
        # y_pred - предсказания
        
        # вычисляем производную функции потерь
        loss_derivative = 2 * (y_pred - y_true)
        
        # вычисляем производную функции активации
        dlayer2 = np.where(self.layer2 > 0, 1, 0)
        
        # вычисляем производную весов и смещений
        dweights2 = np.dot(self.layer1.T, loss_derivative * dlayer2)
        dbias2 = np.sum(loss_derivative * dlayer2, axis=0, keepdims=True)
        dlayer1 = np.dot(loss_derivative * dlayer2, self.weights2.T)
        dweights1 = np.dot(x.T, dlayer1)
        dbias1 = np.sum(dlayer1, axis=0, keepdims=True)
        
        # обновляем веса и смещения
        self.weights1 -= dweights1
        self.bias1 -= dbias1
        self.weights2 -= dweights2
        self.bias2 -= dbias2
        
    def train(self, x, y_true):
        # x - входные данные
        # y_true - правильные ответы
        
        # получаем предсказания
        y_pred = self.feedforward(x)
        
        # обновляем веса и смещения
        self.backprop(x, y_true, y_pred)
        
    def predict(self, x):
        # x - входные данные
        y_pred = self.feedforward(x)
        return y_pred
    
    
if __name__ == '__main__':
    data = [
    [-4, 1, 32],
    [7, -1, 17],
    [4, 14, 21],
    [-8, -18, 17]
    ]
    all_y_trues = [
    0,
    1,
    1,
    0]
    
    network = OurNeuralNetwork()
    
    for epoch in range(1000):
        for x, y_true in zip(data, all_y_trues):
            network.train(np.array(x), y_true)
            
    print('Веса после обучения:')
    print(network.weights1)
    print(network.weights2)
    print('Смещения после обучения:')
    print(network.bias1)
    print(network.bias2)
    
    print('Предсказания после обучения:')
    for x, y_true in zip(data, all_y_trues):
        y_pred = network.predict(np.array(x))
        print('Правильный ответ: {}, Предсказание: {}'.format(y_true, y_pred))   
