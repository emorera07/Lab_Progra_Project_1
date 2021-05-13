/*archivo  cabecera para definir el valor del numero de caras/puntos del diagrama de voronoi a construir, necesario para obtener una buena optimizacion de imagen. Se debe correr como una bandera -D a la hora de compilar, eligiendo el valor predefinido de N_SIDES

por ejemplo, suponga que se desea compilar el archivo Voronoi.c que usa N_SITES y este header.
Para ello se corre: 
	gcc ./voronoi.c -o voronoi -DN_SITES_x
	donde el caracter final x se cambia por el valor de N_SITES deseado [2,3,4,5,6,7,8,9,10,20,25,30,35,40,50,100]		*/
	
#ifdef N_SITES_10
	#define N_SITES 10
	#endif

#ifdef N_SITES_20
	#define N_SITES 20
	#endif
	
#ifdef N_SITES_25
	#define N_SITES 25
	#endif

#ifdef N_SITES_30
	#define N_SITES 30
	#endif
	
#ifdef N_SITES_35
	#define N_SITES 35
	#endif

#ifdef N_SITES_40
	#define N_SITES 40
	#endif
	
#ifdef N_SITES_50
	#define N_SITES 50
	#endif
	
#ifdef N_SITES_100
	#define N_SITES 100
	#endif

#ifdef N_SITES_9
	#define N_SITES 9
	#endif

#ifdef N_SITES_8
	#define N_SITES 8
	#endif

#ifdef N_SITES_7
	#define N_SITES 7
	#endif
	
#ifdef N_SITES_6
	#define N_SITES 6
	#endif
	
#ifdef N_SITES_5
	#define N_SITES 5
	#endif
#ifdef N_SITES_4
	#define N_SITES 4
	#endif
	
#ifdef N_SITES_3
	#define N_SITES 3
	#endif
	
#ifdef N_SITES_2
	#define N_SITES 2
	#endif
