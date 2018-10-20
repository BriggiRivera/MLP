import numpy as np
import pandas as pd
from random import randint

def generateRandomMatrix(width, height):
    return np.random.uniform(size=(width, height))

def sigmoid (x):
    return 1/(1 + np.exp(-x))

def derivative_sigmoid(x):
    return x * (1 - x)

class MLP:
    def __init__(self, file, hiddenNeurons, outputNeurons):
        table = pd.read_csv(file, sep=',', header=None).values
        self.objects = len(table)
        self.num_features = len(table[0]) - 1
        
        self.X = np.array(table[:self.objects, 1:])
        self.Y = self.generateY(np.matrix(table[:self.objects, :1]), outputNeurons)
        
        self.X = self.X / np.linalg.norm(self.X, axis=-1)[:, np.newaxis]

        self.Wih = generateRandomMatrix(self.num_features, hiddenNeurons)
        self.bih = generateRandomMatrix(1, hiddenNeurons)
        self.Who = generateRandomMatrix(hiddenNeurons, outputNeurons)
        self.bho = generateRandomMatrix(1, outputNeurons)

        self.alpha = 0.07
    
    def calculateError(self, O, Y):
        return 0.5 * np.sum(np.power(O - Y, 2))
        
    def generateY(self, vector, outputNeurons):
        Y = np.zeros((self.objects, outputNeurons))
        for index in range(len(Y)):
            Y[index][int(vector[index])-1] = 1
        return Y

    def forward(self):
        Oih = sigmoid(np.dot(self.X, self.Wih) + self.bih)
        Oho = sigmoid(np.dot(Oih, self.Who) + self.bho)
        return (Oih, Oho)
        
    def backward(self, Oih, Oho):
        deltaOutput = (self.Y - Oho) * derivative_sigmoid(Oho)
        deltaHidden = deltaOutput.dot(self.Who.T) * derivative_sigmoid(Oih)
        return (deltaOutput, deltaHidden)
        
    def fit(self, Oih, deltaOutput, deltaHidden):
        self.Who += self.alpha * Oih.T.dot(deltaOutput)
        self.bho += self.alpha * np.sum(deltaOutput, axis=0, keepdims=True)
        self.Wih += self.alpha * self.X.T.dot(deltaHidden)
        self.bih += self.alpha * np.sum(deltaHidden, axis=0, keepdims=True)

    def train(self, epochs):
        for cont in range(epochs):
            (Oih, Oho) = self.forward()
            (deltaOutput, deltaHidden) = self.backward(Oih, Oho)
            self.fit(Oih, deltaOutput, deltaHidden)
        
    def predict(self, V):
        V = V / np.linalg.norm(V)
        Oih = sigmoid(np.dot(V, self.Wih) + self.bih)
        Oho = sigmoid(np.dot(Oih, self.Who) + self.bho)
        output = [1 if x >= 0.5 else 0 for x in np.ndarray.tolist(Oho[0])]
        return output