#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/voronoi.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/drawtxt.h"


#define frand(x) (rand() / (1. + RAND_MAX) * x)

using namespace std;
int NP = 0;
vector<int> xy;
vector<int> x;
vector<int> y;
vector<string> par_ordenado;
void leerArchivo()
{
	ifstream file("../data/Archivo_de_entrada_2.txt");
	string str, str1;
	while (getline(file, str)) {
		par_ordenado.push_back(str);		
	}
	file.close();
	ifstream file1("../data/Archivo_de_entrada_2.txt");
	while (getline(file1, str1, '\n')) {
		stringstream ss(str1);
		while (getline(ss, str, ',')) {
			xy.push_back(stoi(str));
		}			
	}


	for(int i = 0; i < xy.size(); i++){
		if(i%2==0){
			x.push_back(xy[i]);
		}
		else{
			y.push_back(xy[i]);	
		}	
	}
	NP = par_ordenado.size();
}


int main()
{
	leerArchivo();
	int k;
	for (k = 0; k < NP; k++) {
		site[k][0] = x[k]+size_x/2;
		site[k][1] = y[k] +size_y/2;
		rgb [k][0] = frand(256);
		rgb [k][1] = frand(256);
		rgb [k][2] = frand(256);
	}

	gen_map();
	
	drawtxt( xy, par_ordenado, "../build/prueba.pnm", 12);
	
	return 0;
}
