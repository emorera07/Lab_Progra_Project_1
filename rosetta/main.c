#include <iostream>
#include <fstream>


using namespace std;

 

#define frand(x)(rand() / (1. + RAND_MAX) * x)
#define for_kk for (k = 0; k < N_SITES; k++)

int main()
{
    /*Cargar archivo--> puntos*/
    int numPuntos, N_SITES, size_x, size_y; 
    
    N_SITES  = numPuntos;
    double Site[N_SITES][2];
    unsigned char rgb[N_SITES][3];

    /*Se leen los puntos*/
    Site[k][0] = (size_x);
	Site[k][1] = (size_y);

	int k;
	for_kk {
		rgb [k][0] = frand(256);
		rgb [k][1] = frand(256);
		rgb [k][2] = frand(256);
	}
 
	gen_map( &Site);
	return 0;
}