#!/bin/bash
echo "Instalando dependencias"
#sudo apt-get update;
#sudo apt-get install -y libsdl2*;
#sudo apt-get install -y guile-2.0;
#sudo apt-get install -y freetype2-demos;
#sudo apt-get install -y fonts-dejavu;
#sudo apt-get install -y fonts-freefont-ttf;
#sudo apt-get install -y ttf-bitstream-vera;
#sudo apt-get install -y fonts-fre;
echo "Instalación de dependencias completada"
mkdir build;
cd build;
cmake ..;
echo "Creando ejecutable de programa principal"
g++ ../src/main.cpp -o voronoi `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -lSDL2_ttf;
echo "Creando ejecutable para pruebas Gtest"
g++ -I../include/ ../test/main.cpp -lgtest -lpthread -o tests
echo "Compilación completada"
