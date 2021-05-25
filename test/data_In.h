/*Archivo de pruebas con gtest para la funcion leerArchivo.h. Busca validar que se leen correctamente los datos de entrada*/

#include "gtest/gtest.h"
#include "../include/leerArchivo.h"


TEST(leerArchivo,lectura){

    /*Variables*/
    int status = 0;
    int  Num_puntos = 4;
    vector<int> xy;								// store the x and y values.
    vector<int> x;								// store X values
    vector<int> y;								// store Y values
    vector<string> par_ordenado;				// store coordinate as text to plot on image
    
    
    status = leerArchivo("../test/test.txt", x, y, xy, par_ordenado);
    EXPECT_EQ(status,Num_puntos);

}

TEST(leerArchivo,valores){
      /*Variables*/
    int status = 0;
    int  Num_puntos = 4;
    vector<int> xy;								// store the x and y values.
    vector<int> x;								// store X values
    vector<int> y;								// store Y values
    vector<string> par_ordenado;				// store coordinate as text to plot on image
    string archivo = "../test/test.txt";
    
    /*creating source vector to comparate*/
    vector<int> source;
    source.push_back(0);
    source.push_back(50);
    source.push_back(50);
    source.push_back(0);
    source.push_back(-50);
    source.push_back(0);
    source.push_back(0);
    source.push_back(-50);
    /*creating source vector to comparate*/
    vector<string> source_pairs;
    source_pairs.push_back("0,50");
    source_pairs.push_back("50,0");
    source_pairs.push_back("-50,0");
    source_pairs.push_back("0,-50");
    
    status = leerArchivo(archivo, x, y, xy, par_ordenado);

    for (int i = 0; i < Num_puntos; i++)
    {
        EXPECT_EQ(source_pairs[i],par_ordenado[i]);
    }
     
}