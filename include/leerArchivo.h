/* Function read file line by line, using a file name aund global vectors defined in main */

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
    string str, str1;						// temporal string


	ifstream file(archivo);	    			// ifstream objetc init
    /*if (file.failbit)                       // Checking NULLS
    {
        cout << "\nNO se pudo abrir el archivo de puntos. Verifique\n";
        return -1;
    }*/
    while (getline(file, str))
    {	                            		// reading file line by line, store entire coordinate as string
	    par_ordenado.push_back(str);		
	}
	file.close();							// close					
	
    ifstream file1(archivo);				// ifstream objetc init						
	/*if (file1.failbit)                      // Checking NULLS
    {
        cout << "\nNO se pudo abrir el archivo de puntos. Verifique\n";
        return -1;
    }*/

    while (getline(file1, str1, '\n')) {	// reading x and then, y					
		stringstream ss(str1);			
		while (getline(ss, str, ',')) {						
			/*if ( str[0]!='-' && !isdigit(str[0]) )
            {
                cout << "\nFormato de entrada incorrecto, verifique el archivo de entrada.\n";
                return -1;
            }*/
            xy.push_back(stoi(str));						
		}			
	}
	file1.close();
	for(int i = 0; i < xy.size(); i++){		// store values of x (even index) and y (odd index)
		if(i%2==0){
			x.push_back(xy[i]);
		}
		else{
			y.push_back(xy[i]);	
		}	
	}
	NP = par_ordenado.size();				// number of points 
	return NP;								// return
}
