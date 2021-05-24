/*MAIN.CPP 

Voronoi Diagrams - C++
IE724 Laboratory of programming and microcomputers, EIE, University of Costa Rica
Esquivel M. Brandon, Morera Emmanuel, Fonseca Dualock
brandon.esquivel@ucr.ac.cr, emmanuel.morera@ucr.ac.cr, djfonsecamo@gmail.com*/



/*INCLUDES*/
#include "../include/drawtxt.h"
#include "../include/voronoi.h"
#include "../include/leerArchivo.h"

/*DEFINES*/
#define W 640
#define H 480
#define NO_ERROR 1
#define ERROR -1 

/*NAMESPACE*/
using namespace std;

/*GLOBAL VAR*/
vector<int> xy;								// store the x and y values.
vector<int> x;								// store X values
vector<int> y;								// store Y values
vector<string> par_ordenado;						// store coordinate as text to plot on image
bool error_flag = false;						// boolean flag for error tracking




 /*Main*/
int main(int nargs, char *args[]){				

	int N_SITES;							// Number of sites = number of points
	if(nargs != 2 ){						// error handle for arguments
		cout<<"Ingrese el parametro por consola: ../data/Ruta_archivo.txt\n"<<endl;
		error_flag = true;
		return ERROR;
	}
	else{
		N_SITES = leerArchivo(args[1], x, y, xy, par_ordenado);					// using file address argument (1)		
		if (N_SITES==ERROR)
		{
			std::cerr << "\nError en la lectura del archivo fuente: leerArchivo.h retorna error\n";
			return ERROR;
		}
		
		error_flag = gen_map(N_SITES, W, H, x, y);				    // gen voronoi diagram
		
		if (error_flag)
		{
			std::cerr << "\nError en la generacion del diagrama: gen_map retorna error\n";
			return ERROR;
		}

		error_flag = drawtxt( xy, par_ordenado, "prueba.pnm", 6);	// draw coordinates as text over the diagram.
		

		if (error_flag)
		{
			return ERROR;
		}
		else {
			return NO_ERROR;
		}	
	}
}
// end main

