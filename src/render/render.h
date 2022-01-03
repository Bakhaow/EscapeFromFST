#ifndef _RENDER_H_
#define _RENDER_H_

#include "../mapping/map.h"
#include "../player/player.h"

//SCREEN DIMENSION CONSTANTS
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 512
#define WH 512 / MAP_SIZE

int initSDL();

typedef struct {
	SDL_Surface* wall;
    SDL_Texture* walltext;
} Texture;


SDL_Window* createWindow();
SDL_Renderer* createRenderer(SDL_Window* Window);

void drawFilledRect(SDL_Renderer* renderer, int x, int y, int w, int h);
void drawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);
void drawMap2D(SDL_Renderer* renderer, int map[MAP_SIZE][MAP_SIZE]);
void drawPlayer2D(SDL_Renderer* renderer, Player * p);
void draw(SDL_Renderer* renderer, Map * m, Player * p);
void renderBackground(SDL_Renderer* renderer);


#endif