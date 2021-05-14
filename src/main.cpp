/*MAIN.CPP 

Voronoi Diagrams - C++
IE724 Laboratory of programming and microcomputers, EIE, University of Costa Rica
Esquivel M. Brandon, Morera Emmanuel, Fonseca Dualock
brandon.esquivel@ucr.ac.cr, emmanuel.morera@ucr.ac.cr, djfonsecamo@gmail.com*/



/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/drawtxt.h"
#include "../include/voronoi.h"

/*DEFINES*/
#define W 640
#define H 480 

/*NAMESPACE*/
using namespace std;

/*GLOBAL VAR*/
vector<int> xy;								// store the x and y values.
vector<int> x;								// store X values
vector<int> y;								// store Y values
vector<string> par_ordenado;				// store coordinate as text to plot on image


/*Function read file line by line */
int leerArchivo( string archivo)
{	int NP;									// number of points
	ifstream file(archivo);					// ifstream objetc init
	string str, str1;						// temporal string
	while (getline(file, str)) {			// reading file line by line, store entire coordinate as string
		par_ordenado.push_back(str);		
	}
	file.close();							// close					
	ifstream file1(archivo);				// ifstream objetc init						
	while (getline(file1, str1, '\n')) {	// reading x and then, y					
		stringstream ss(str1);			
		while (getline(ss, str, ',')) {						
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


 /*Main*/
int main(int nargs, char *args[]){				

	int N_SITES;							// Number of sites = number of points
	if(nargs != 2 ){						// error handle for arguments
		cout<<"tIngrese el parametro por consola: ../data/Ruta_archivo.txt\n"<<endl;
		return 0;
	}
	else{
		N_SITES = leerArchivo(args[1]);					// using file address argument (1)
		//size_x = atoi(args[2]);						// cast char to int, second and third arguments (resolution w h)
		//size_y = atoi(args[3]);			
		gen_map(N_SITES, W, H, x, y);			// gen voronoi diagram
		drawtxt( xy, par_ordenado, "prueba.pnm", 6);	// draw coordinates as text over the diagram.
		return 0;
	}
}
// end program
