#ifndef _RENDER_H_
#define _RENDER_H_

#include "../mapping/map.h"

//SCREEN DIMENSION CONSTANTS
#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720

int initSDL();

SDL_Window* createWindow();
SDL_Renderer* createRenderer(SDL_Window* Window);

/*void drawHollowedTri(SDL_Renderer* Renderer, int x[], int y[], int z[], int color[], int alpha);
void drawTri(SDL_Renderer* Renderer, int x[], int y[], int z[], int color[], int alpha);

void draw2DMap(SDL_Renderer* renderer, int map[MAP_SIZE][MAP_SIZE][MAP_SIZE]);

void draw(SDL_Renderer* Renderer);*/

void drawMap2D(SDL_Renderer* renderer, int map[MAP_SIZE][MAP_SIZE][MAP_SIZE]);


#endif