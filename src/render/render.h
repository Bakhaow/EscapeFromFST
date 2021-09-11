#ifndef _RENDER_H_
#define _RENDER_H_

//SCREEN DIMENSION CONSTANTS
#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720

int init_sdl();

SDL_Window* createWindow();
SDL_Renderer* createRenderer(SDL_Window* Window);

void drawHollowedTri(SDL_Renderer* Renderer, int x[], int y[], int z[], int color[], int alpha);
void drawTri(SDL_Renderer* Renderer, int x[], int y[], int z[], int color[], int alpha);

void draw(SDL_Renderer* Renderer);


#endif