#ifndef _RENDER_H_
#define _RENDER_H_

//SCREEN DIMENSION CONSTANTS
#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720

int init_sdl();

SDL_Window* createWindow();
SDL_Renderer* createRenderer(SDL_Window* Window);

void draw(SDL_Renderer* Renderer);


#endif*/