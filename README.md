# Voronoi Diagrams - C++
## IE724 Laboratory of programming and microcomputers, EIE, University of Costa Rica
## Esquivel M. Brandon, Morera Emmanuel, Fonseca Dualock
## brandon.esquivel@ucr.ac.cr, emmanuel.morera@ucr.ac.cr, djfonsecamo@gmail.com

# Description
Generacion de un diagrama de Voronoi a partir de un archivo de puntos x,y utilizando las librerias graficas -libgraph, SDL, SDL2 SDL_image y SDL_ttf
Se deben instalar todas sus dependencias para correrlo sin problemas.

# Dependencies
cmake
build-essential
libgraph
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


# Guía rápida para instalar Libgraph y graphics.h 
 `cd ~/`
	
`wget http://download.savannah.gnu.org/releases/libgraph/libgraph-1.0.2.tar.gz`
	
`tar -xvzf libgraph-1.0.2.tar.gz`
	
`cd libgraph-1.0.2`
	
`./configure`

`CPPFLAGS="$CPPFLAGS $(pkg-config --cflags-only-I guile-2.0)" \ CFLAGS="$CFLAGS $(pkg-config --cflags-only-other guile-2.0)" \ LDFLAGS="$LDFLAGS $(pkg-config --libs guile-2.0)"`
  
`sudo make`
	
`sudo make install`
	
`sudo cp /usr/local/lib/libpng.* /usr/lib`
	
  
***Al compilar con libgraph debe agregar la bandera -lgraph.***
  
# How to run
ejemplo de prueba:
luego de instalar las dependencias, clone el reposiorio.

`mkdir build`

`cd build`

`g++ ../src/main.cpp -o voronoi -lgraph -DNO_FREETYPE ``sdl2-config --cflags --libs`` -lSDL2 -lSDL2_image -lSDL2_ttf -DN_SIDES_5`

**quite un par de comillas a las banderas `sdl2-config --cflags --libs` , que solo mantenga un par.**

`./voronoi > prueba.pnm`

# Sobre la compilacion
Toda la linea de compilacion se mantiene a excepcion del parametro -DN_SIDES_x, este varia segun la cantidad de puntos a leer, algo que se supone que el usuario conoce de antemano. X es la cantidad de puntos del archivo de texto, X e [1,2,3,4...,99,100]. El maximo numero de puntos posibles a analizar es de 100 es decir, con la bandera -DN_SIDES_100.
Si desea analizar un nuevo archivo de puntos, agreguelo a la carpeta data bajo el nombre entrada1.txt, si desea cambiar este nombre, puede cambiarlo directamente en la ruta de lectura en [main.cpp](src/main.cpp), líneas 22 y 28.

