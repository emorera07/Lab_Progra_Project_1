/* Funcion Voronoi.h realiza el diagrama de voronoi con los datos de entrada leido en vectores, en una ventana de 640x480p */
/* Adaptacion del codigo en C de la pagina Rosetta Voronoi examples. */

/*DEFINES*/
#ifndef VORONOI_H
#define VORONOI_H
#define frand(x) (rand() / (1. + RAND_MAX) * x)
#define AA_RES 32 /* average over 4x4 supersampling grid */

/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>


/*NAMESPACE*/
using namespace std;

/*GLOBAL VAR*/
int N_SITES, size_y, size_x;

/*Obtiene la distancia en linea recta (raiz cuadrada, pitagorica) entre dos puntos x y, respecto a origen */
static inline double sq2(double x, double y)
{
	return x * x + y * y;
}

/*calcula las distancias entre las caras/puntos y determina las distancias menores o mas cercanas entre si*/
int nearest_site(double x, double y, double site[][2])
{
	int k, ret = 0;
	double d, dist = 0;
	for (k = 0; k < N_SITES; k++) {
		d = sq2(x - site[k][0], y - site[k][1]);
		if (!k || d < dist) {
			dist = d, ret = k;
		}
	}
	return ret;
}


/* determina si un píxel es diferente de los vecinos */
int at_edge(int *color, int y, int x)
{
	int i, j, c = color[y * size_x + x];
	for (i = y - 1; i <= y + 1; i++) {
		if (i < 0 || i >= size_y) continue;

		for (j = x - 1; j <= x + 1; j++) {
			if (j < 0 || j >= size_x) continue;
			if (color[i * size_x + j] != c) return 1;
		}
	}
	return 0;
}


/*determina los colores de los pixeles por cara del diagrama, dada una resolucion de pixel AA_RES y un vector RGB*/
void aa_color(unsigned char *pix, int y, int x, double site[][2], unsigned char rgb[][3])
{
	int i, j, n;
	double r = 0, g = 0, b = 0, xx, yy;
	for (i = 0; i < AA_RES; i++) {
		yy = y + 1. / AA_RES * i + .5;
		for (j = 0; j < AA_RES; j++) {
			xx = x + 1. / AA_RES * j + .5;
			n = nearest_site(xx, yy, site);
			r += rgb[n][0];
			g += rgb[n][1];
			b += rgb[n][2];
		}
	}
	pix[0] = r / (AA_RES * AA_RES);
	pix[1] = g / (AA_RES * AA_RES);
	pix[2] = b / (AA_RES * AA_RES);
}


/*Generacion del mapa diagrama de voronoi*/
int gen_map(int N_SITES0, int size_x0, int size_y0, vector<int> x, vector<int> y )
{	
	int i, j, k;
	N_SITES = N_SITES0;
	size_x = size_x0;
	size_y = size_y0;
	double site[N_SITES][2];
	unsigned char rgb[N_SITES][3];

	try
	{
		for (k = 0; k < N_SITES; k++) {
		site[k][0] = x[k] + size_x/2;
		site[k][1] = y[k] + size_y/2;
		rgb [k][0] = frand(256);
		rgb [k][1] = frand(256);
		rgb [k][2] = frand(256);
	}
	}
	catch(const std::exception& e)
	{
		std::cerr << "\nError en la generacion de vector de coordenadas, en gen_map().\n Error: " << e.what() << '\n';
		return 1; 						// activa la bandera error en main
	}
	
	
	int *nearest = (int*)malloc(sizeof(int) * size_y * size_x);
	unsigned char *ptr, *buf, color;
	ptr = buf = (unsigned char*)(int*)malloc(3 * size_x * size_y);
	for (i = 0; i < size_y; i++) for (j = 0; j < size_x; j++) nearest[i * size_x + j] = nearest_site(j, i, site);

	for (i = 0; i < size_y; i++) for (j = 0; j < size_x; j++) {
		if (!at_edge(nearest, i, j))
			memcpy(ptr, rgb[nearest[i * size_x + j]], 3);
		else	/* at edge, do anti-alias rastering */
			aa_color(ptr, i, j, site, rgb);
		ptr += 3;
	}

	/* draw sites */
	for (k = 0; k < N_SITES; k++) {
		color = (rgb[k][0]*.25 + rgb[k][1]*.6 + rgb[k][2]*.15 > 80) ? 0 : 255;

		for (i = site[k][1] - 1; i <= site[k][1] + 1; i++) {
			if (i < 0 || i >= size_y) continue;

			for (j = site[k][0] - 1; j <= site[k][0] + 1; j++) {
				if (j < 0 || j >= size_x) continue;
				ptr = buf + 3 * (i * size_x + j);
				ptr[0] = ptr[1] = ptr[2] = color;
				}
			}
		}
	printf("P6\n%d %d\n255\n", size_x, size_y);
	fflush(stdout);
	fwrite(buf, size_y * size_x * 3, 1, stdout);
	return 0;
	}
#endif