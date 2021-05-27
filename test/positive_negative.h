#include "gtest/gtest.h"
#include "../include/leerArchivo.h"
#include "../include/voronoi_test.h"

//Test negative, unexistent file
TEST(leerArchivo, negative){
  int status = 0;
  int  Num_puntos = 4;
  vector<int> xy;								// store the x and y values.
  vector<int> x;								// store X values
  vector<int> y;								// store Y values
  vector<string> par_ordenado;				// store coordinate as text to plot on image
  status = leerArchivo("../test/text.txt", x, y, xy, par_ordenado);
  EXPECT_EQ(status,-1);
}
// Test negative invalid input file
TEST(leerArchivo, negative_2){
  int status = 0;
  int  Num_puntos = 4;
  vector<int> xy;								// store the x and y values.
  vector<int> x;								// store X values
  vector<int> y;								// store Y values
  vector<string> par_ordenado;				// store coordinate as text to plot on image
  status = leerArchivo("../test/test2.txt", x, y, xy, par_ordenado);
  EXPECT_EQ(status,-1);
}
TEST(Voronoi, positive){
  int status = 0;
  int n_sites = 4;
  int m = 640;
  int h = 480;
  vector<int> x;								// store X values
  vector<int> y;								// store Y values

//fill the arrays to generate a correct img
  x.push_back(0);
  x.push_back(50);
  x.push_back(-50);
  x.push_back(0);

  y.push_back(50);
  y.push_back(0);
  y.push_back(0);
  y.push_back(-50);

  status = gen_map(n_sites, m, h, x, y);
  EXPECT_EQ(status, 0);
}
TEST(Voronoi, negative){
  int status = 0;
  int n_sites = 4;
  int m = 640;
  int h = 480;
  vector<int> x;								// store X values
  vector<int> y;								// store Y values

//fill the arrays to fail at generating the img
// 4 x values
  x.push_back(0);
  x.push_back(50);
  x.push_back(-50);
  x.push_back(0);
// 3 y values
  y.push_back(0);
  y.push_back(0);
  y.push_back(-50);

  status = gen_map(n_sites, m, h, x, y);
  EXPECT_EQ(status, -1);
}
