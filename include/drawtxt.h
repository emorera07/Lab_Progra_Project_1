/*  Brandon Esquivel Molina
    Universidad de COsta Rica
    Escuela de Ingenieria Electrica
    github: @brandonEsquivel
    brandon.esquivel@ucr.ac.cr

    @brief BETA >>>> lib code to render text over a image usinf SDL2, SDF_tff
    THIS IS A FIRST TEST IMPLEMENTATION OF THE ORIGINAL file (on dev)

    How to run: (only for testing version) 
    g++ drawTEXT.cpp -o executable -lgraph -DNO_FREETYPE `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -lSDL2_ttf
    ./executable
*/
#include <SDL2/SDL.h> // include SDL header form SDL2 lib
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int drawtxt( vector<int> xy, vector<string> coordenadas, string archivo, int fontsize )
{   /*for the tap window screen*/
    SDL_Surface *screen;    // surface to convert to window object and plot (like a canva) 
    SDL_Window  *window;    // window struct to plot
    SDL_Surface *image;     // surface to charge readed image, image can bi .png or .pnm
    SDL_Rect dstrect;       // rectangle to draw over a surface or window
    
    /*For text*/
    TTF_Font* font;                     // init de font struct 
    //int fontsize = 8;                   // font size on screen.
    SDL_Surface* text;                  // surface to draw text fonts
    SDL_Color color = { 0, 0, 0 };      // Set color to black
    TTF_Init();                         // constructor INIT
    if ( TTF_Init() < 0 ) {             // checking for errors
	    cout << "Error initializing SDL_ttf: " << TTF_GetError() << endl;
    }
    font = TTF_OpenFont("../data/font.ttf", fontsize);          // opening font, must be in same folder
    if ( !font ) {                                      // getting nulls
	    cout << "Failed to load font: " << TTF_GetError() << endl;
    }
    
    /* Loading the image */
    SDL_Init(SDL_INIT_VIDEO);                   // init video mode to render surfaces
    image = IMG_Load( archivo.c_str() );       // loads image, just change de extension .png or .pnm
    int w = image->w;                           // getting image width
    int h = image->h;                           // getting image high
    dstrect.x = 0;                              // this four lines are to set a rectange (canva) to plot the image over,
    dstrect.y = 0;                              // x = 0 and y = 0 means the upper left corner, .w and .h set the final 
    dstrect.w = w;                              // point to cover, like a mouse pointer
    dstrect.h = h;                              // 

    window = SDL_CreateWindow("SDL2 Voronoi Diagram", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, 0);       // create a window, first layer
    screen = SDL_GetWindowSurface(window);                  // instead of creating a renderer, draw directly to the screen, second layer
    SDL_BlitSurface(image, NULL, screen, &dstrect);         // print the image using the rectangle dstrect (all the screen), third layer 
    
    
    /* TEXT */ //from file data read -> point x,y and NP number of points
    int NP = coordenadas.size();        // this is just a test, real values come from a file read. skip
    int maxX = 0;                       // variables for max-min points of X and Y
    int maxY = 0;                       // will be used to obtain the scaling kx and ky
    int minX = 0;                       //
    int minY = 0;                       // the following for loops are to obtain these values

    for (int i = 0; i < xy.size(); i = i+2)
    {
        (xy[i]>maxX) ? maxX=xy[i] : maxX=maxX;
    }
     for (int i = 0; i < xy.size(); i = i+2)
    {
        (xy[i]<minX) ? minX=xy[i] : minX=minX;
    }

    for (int i = 1; i < xy.size(); i = i+2)
    {
        (xy[i]>maxY) ? maxY=xy[i] : maxY=maxY;
    }
     for (int i = 1; i < xy.size(); i = i+2)
    {
        (xy[i]<minY) ? minY=xy[i] : minY=minY;
    }
    
    /* Scaling on image */ 
    // width and high are pixel values, that depends on original image resolution. The max and min point 
    int kx = w/(abs(maxX) + abs(minX));             // with this scale or aspect ratio the program can recalculate de correct coordinate
    int ky = h/(abs(minY) + abs(maxY));             // of the point on screen to plot the text, for any W,H or X,Y values           

    int j = 0;                                  
    for (int i = 0; i < NP; i++)                        // sweeping readed points. Probably is going to need modifications 
    {   
        const char * c = coordenadas[i].c_str();             // Cast string to const Char, needed for the Render Text process
        text = TTF_RenderText_Solid( font, c, color);   // Render text process call. using font file (font.tff), c string point and setted color
        if ( !text ) {
    	    cout << "Failed to render text: " << TTF_GetError() << endl;    // getting error on NULL
        }
        SDL_Rect dstrec;                                    // in each iteration, creating a new rectagle to plot, for a new point coordinate. fourth layer
        dstrec.x = w/2 + xy[j]*kx - xy[j];            // start point xy, applying scaling
        dstrec.y = h/2 - xy[j+1]*ky + xy[j+1];
        dstrec.w = 5;                                       // not too sure about what this values affects    
        dstrec.h = 5;                                       // not too sure about what this values affects
        j = j+2;                                            // double counter, 2by2, number of coordinates are twice of points number
        SDL_BlitSurface(text, NULL, screen, &dstrec);       // print 
    }
    
    
    SDL_SaveBMP(screen,"voronoi.bmp");			    // save image

    ////////////////////
    /* FREE STRUCTS */
    SDL_FreeSurface(image);
    SDL_FreeSurface(text);
    SDL_FreeSurface(screen);
    /*updating window*/
    SDL_UpdateWindowSurface(window);
    SDL_Delay(10000);  			// WAIT 10s to
    TTF_CloseFont( font );              // close eviroment
    TTF_Quit();                         // quit eviroment
    SDL_DestroyWindow(window);          // close eviroment
    SDL_Quit();                         // quit eviroment

    return 0;
}
