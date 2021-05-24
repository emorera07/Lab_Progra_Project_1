/* Function read file line by line, using a file name aund global vectors defined in main.
Implements exception handling for a given format, ignore letters after a first given number in the point file, for example:
The correct format is:
x,y
x,y
x,y

Incorrect formats are:
x,_
_,Y
non-numeric, non-numeric - in any order
x
Y
any other combination of these or empty lines

An exception to the format is:
XXno-numeric, YYno-numeric
in the latter case the non-numeric values are ignored and XX, YY are taken as their value, but they will be labeled including them. */

/*DEFINES*/
#ifndef LEERARCHIVO_H
#define LEERARCHIVO_H

/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

/*NAMESPACE*/
using namespace std;

int leerArchivo( string archivo, vector<int> &x, vector<int> &y, vector<int> &xy, vector<string> &par_ordenado )
{	
    /*Variables*/
    int NP;									// number of points
    string str;						// temporal string

    ifstream file1(archivo);				// ifstream objetc init						
    if (!file1.is_open())
    {
        std::cerr << "\nError al abrir el archivo fuente. Verifique la ruta y el nombre\n " << '\n';
        return -1;
    }
    try
    {
        while (getline(file1, str, '\n')) {	// reading x and then, y					
		stringstream ss(str);			
		while (getline(ss, str, ',')) {
            if (str.empty())
            {
                std::cerr << "Formato de entrada invalido, por favor verifique el archivo de puntos de entrada\nError: Campo nulo " << '\n';
                file1.close();
                return -1;
            }						
            xy.push_back(stoi(str));						
		    }			
	    }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Formato de entrada invalido, por favor verifique el archivo de puntos de entrada\nError en: " << e.what() << '\n';
        file1.close();
        return -1;
    }
    file1.close();                          // restoring file pointers
	
    ifstream file(archivo);	    			// ifstream objetc init again, restored, the null check was done above
    while (getline(file, str))
    {	                            		// reading file line by line, store entire coordinate as string
	    if (str.empty())
        {
            std::cerr << "\nWarning: Formato de entrada invalido, Es posible que hayan lineas vacias. Verifique por favor.\nSe intentara crear el diagrama pero no se podran etiquetar los puntos correctamente.\n'";
        }       
        par_ordenado.push_back(str);		
	}
	file.close();							// close					
	

	try
    {
        for(int i = 0; i < xy.size(); i++){		// store values of x (even index) and y (odd index)
		if(i%2==0){
			x.push_back(xy[i]);
		}
		else{
			y.push_back(xy[i]);	
		}	
	}
	NP = par_ordenado.size();				// number of points 
	return NP;	                            // return, END with no errors.
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error en la obtencion de los puntos de entrada, es posible que no sean suficientes y sean incorrectos.\n Error en: " << e.what() << '\n';
        return -1;
    }							
}
#endif
