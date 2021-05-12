#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "voronoi.h"




#define for_k for (k = 0; k < N_SITES; k++)
#define frand(x) (rand() / (1. + RAND_MAX) * x)
int main()
{
	int k;
	for_k {
		site[k][0] = frand(size_x);
		site[k][1] = frand(size_y);
		rgb [k][0] = frand(256);
		rgb [k][1] = frand(256);
		rgb [k][2] = frand(256);
	}

	gen_map();
	return 0;
}
