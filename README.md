# Voronoi Diagrams - C++
## IE724 Laboratory of programming and microcomputers, EIE, University of Costa Rica
## Esquivel M. Brandon, Morera Emmanuel, Fonseca Dualock
## brandon.esquivel@ucr.ac.cr, emmanuel.morera@ucr.ac.cr, djfonsecamo@gmail.com

# Description
Generacion de un diagrama de Voronoi a partir de un archivo de puntos x,y utilizando las librerias graficas SDL, SDL2 SDL_image y SDL_ttf
Se deben instalar todas sus dependencias para correrlo sin problemas.

# Dependencies
cmake
build-essential
sdl2
para instalar las bibliotecas necesarias ejecute (probado en ubuntu 20.04 LTS), si algun paquete no se encuentra eliminelo de la lista y compruebe que se encontraron los otros, ignore los que ya se han instalado.

`sudo apt install -y mercurial cmake g++`

`sudo apt install -y qtbase5-dev qtbase5-private-dev qttools5-dev-tools qttools5-dev qt5-style-plugins libsdl-ttf2.0-dev libsdl2-dev libsdl2-net-dev`

`sudo apt install -y libsdl2-dev libglm-dev libglew-dev libsdl2-image-dev libsdl2-ttf-dev`

`sudo apt install -y liblua5.1-dev fpc libphysfs-dev fonts-dejavu-core ttf-wqy-zenhei`

`sudo apt install -y libsdl-image1.2 libsdl-image1.2-dev guile-3.0 libart-2.0-dev libaudiofile-dev libdirectfb-dev libdirectfb-extra`

`sudo apt install -y libfreetype6-dev libxext-dev x11proto-xext-dev libfreetype6 libaa1 libaa1-dev libslang2-dev libasound2 libasound2-dev`

`sudo apt install -y libjpeg-dev libwebp-dev libtiff5-dev libsdl2-image-dev libsdl2-image-2.0-0`

`sudo apt install -y guile-2.0 guile-2.0-dev libsdl1.2debian libart-2.0-dev libaudiofile-dev libdirectfb-dev`

`sudo apt install -y libdirectfb-extra libfreetype6-dev libxext-dev x11proto-xext-dev libfreetype6 libaa1 libaa1-dev libslang2-dev libasound2 libasound2-dev`

  
# How to run
ejemplo de prueba:
luego de instalar las dependencias, clone el reposiorio.

`mkdir build`

`cd build`

`g++ ../src/main.cpp -o voronoi ``sdl2-config --cflags --libs`` -lSDL2 -lSDL2_image -lSDL2_ttf`

**quite un par de comillas a las banderas `sdl2-config --cflags --libs` , que solo mantenga un par.**

`./voronoi ../data/nombre_archivo.txt > prueba.pnm`

# Sobre la compilacion
Al ejecutar verifique que la ruta del archivo de texto a leer es correcta, se generará en pantalla en resultado obtenido y se guardarán en /build las imagenes generadas, una .pnm sin texto y una .bmp con las coordenadas incluidas.

