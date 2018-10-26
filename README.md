# MLP
Red Neuronal MLP (desde cero), clasificación de rostros usando Wavelets

## 1. Instalar dependencias:
- Numpy: pip install numpy --user
- Pandas: pip install pandas --user
- sudo apt-get install libjpeg-dev

## 2. Generar archivo de caracteristicas extraidas por la transformada Haar Wavelets
- ir al directorio: MLP/Wavelets
- Compilar: g++ generateFeatures.cpp -o generateFeatures -std=c++11 -O2 -L/usr/X11R6/lib -lm -lpthread -lX11 -ljpeg
- Ejecutar: ./generateFeatures > "../MLP/Input/inputTrain.txt"
- Ejecutar: ./generateFeatures 1 > "../MLP/Input/inputTest.txt"
