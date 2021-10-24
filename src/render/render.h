#ifndef _RENDER_H_
#define _RENDER_H_

#include "../mapping/map.h"
#include "../player/player.h"

//SCREEN DIMENSION CONSTANTS
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 512
#define WH 512 / MAP_SIZE

int initSDL();

SDL_Window* createWindow();
SDL_Renderer* createRenderer(SDL_Window* Window);

void drawRect(SDL_Renderer* renderer, int x, int y, int w, int h);
void drawFilledRect(SDL_Renderer* renderer, int x, int y, int w, int h);
void drawTri(SDL_Renderer* renderer, int x, int x1, int y, int y1, int z, int z1);
void drawFilledTri(SDL_Renderer* renderer, int x, int x1, int y, int y1, int z, int z1);
void drawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);
void drawMap2D(SDL_Renderer* renderer, int map[MAP_SIZE][MAP_SIZE]);
void draw(SDL_Renderer* renderer, Map * m, Player * p);


#endif