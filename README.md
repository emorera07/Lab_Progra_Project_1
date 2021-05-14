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
Se dispone de instalación automática ejecutando config.sh
sudo apt-get install -y libsdl2*;
sudo apt-get install -y guile-2.0;
sudo apt-get install -y freetype2-demos;
sudo apt-get install -y fonts-dejavu;
sudo apt-get install -y fonts-freefont-ttf;
sudo apt-get install -y ttf-bitstream-vera;
sudo apt-get install -y fonts-fre;

# How to run
Entrar a la carpeta Lab_Progra_Project_1
Dar permisos de ejecucion al archivo config.sh conn el siguiente comando
`sudo chmod +x config.sh`

Instalar las dependencias y correr el cmake con el comando
Para ello se ejecuta el archivo config.sh

La ejecucion del config.sh lo llevara al directorio build, una vez ahi ejecutar el siguiente comando
`./voronoi ../data/nombre_archivo.txt > prueba.pnm`
Recordar que el archivo.txt debe estar en la carpeta data

# Sobre la compilacion
Al ejecutar verifique que la ruta del archivo de texto a leer es correcta, se generará en pantalla en resultado obtenido y se guardarán en /build las imagenes generadas, una .pnm sin texto y una .bmp con las coordenadas incluidas.

