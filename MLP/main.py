import sys
from Net.MLP import MLP
import numpy as np

def main(argv):
    mlp = MLP('./Input/inputHaarv01.txt', 8, 3)
    mlp.train(100000)
    print(mlp.predict(np.array([530.002, 492, 1802.63, 46.5])))
    print(mlp.predict(np.array([511.785, 472.25, 1667.75, 30.125])))

if __name__ == "__main__":
    main(sys.argv) 
