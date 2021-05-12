/*Tomado de https://decodigo.com/c-plus-plus-leer-archivo-de-texto */
#include <ifstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leerArchivo(){
  string cadena;
  ifstream datos("/data/Archivo_de_entrada_1.txt",ios::in);
    if(datos.fail()){
      cout<<"Texto entrada Estructura.txt no existe"<<endl;
    }else{
      while(!datos.eof()){
        getline(datos,cadena); //con esta funcion tomas la linea(limitada por \n)
        cout<<cadena<<endl;
    }
  }
}
