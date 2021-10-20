/* Window render management */

#include <stdio.h>
#include <SDL2/SDL.h>

#include "render.h"
#include "../mapping/map.h"

int init_sdl()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("SDL ERROR(Init): %s\n", SDL_GetError());
		return -1;
	}
	return 0;
}

SDL_Window* createWindow()
{
	SDL_Window* win = NULL;

	// window creation
	win = SDL_CreateWindow("Escape From FST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1440, 960, SDL_WINDOW_OPENGL);

	return win;
}

SDL_Renderer* createRenderer(SDL_Window* win)
{
	SDL_Renderer* renderer = NULL;

	// renderer creation
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);

	return renderer;
}

/*void drawHollowedTri(SDL_Renderer* renderer, int x[], int y[], int z[], int color[], int alpha)
{
	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], alpha);
	SDL_RenderDrawLine(renderer, x[0], x[1], y[0], y[1]);
	SDL_RenderDrawLine(renderer, y[0], y[1], z[0], z[1]);
	SDL_RenderDrawLine(renderer, z[0], z[1], x[0], x[1]);
	SDL_SetRenderDrawColor(renderer, 50, 255, 50, alpha);
	for (int i = x[0]; i < x[1]; i++) {
		SDL_RenderDrawLine(renderer, x[0] + i, x[1] + i, z[0], z[1]);
	}
}

void drawTri(SDL_Renderer* renderer, int x[], int y[], int z[], int color[], int alpha)
{
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, alpha);
	if (x[1] == z[1]) {
		int a = x[0];
		int b = z[0];
		if (x[0] > z[0]) {
			a = z[0];
			b = x[0];
		}
		for (int i = a; i < b; i++) {
			SDL_RenderDrawLine(renderer, i, x[1], y[0], y[1]);
		}
	}
	else {
		int a = x[1];
		int b = z[1];
		if (x[1] > z[1]) {
			a = z[1];
			b = x[1];
		}
		for (int i = a; i < b; i++) {
			SDL_RenderDrawLine(renderer, x[0], i, y[0], y[1]);
		}
	}
}

void drawRect(SDL_Renderer* renderer, int x[], int y[], int z[], int a[], int color[], int alpha) {
	drawTri(renderer, x, y, z, color, 0xFF);
	drawTri(renderer, a, y, z, color, 0xFF);
}

void drawHollowedRect(SDL_Renderer* renderer, int x[], int y[], int z[], int a[], int color[], int alpha) {
	drawHollowedTri(renderer, x, y, z, color, 0xFF);
	drawHollowedTri(renderer, a, y, z, color, 0xFF);
}

void drawCube(SDL_Renderer* renderer, int x[], int y[], int z[], int a[], int color[], int alpha) {
	int changement[] = { 50, -50 };
	drawHollowedRect(renderer, x, y, z, a, color, 0xFF);
	int x1[] = { y[0], y[1] };
	int y1[] = { y[0] + changement[0], y[1] + changement[1] };
	int z1[] = { a[0], a[1] };
	int a1[] = { a[0] + changement[0], a[1] + changement[1] };
	drawHollowedRect(renderer, x1, y1, z1, a1, color, 0xFF);

	z1[0] = x[0]; z1[1] = x[1];
	x1[0] = x[0] + changement[0]; x1[1] = x[1] + changement[1];
	a1[0] = y[0]; a1[1] = y[1];
	y1[0] = y[0] + changement[0]; y1[1] = y[1] + changement[1];

	drawHollowedRect(renderer, x1, y1, z1, a1, color, 0xFF);
}

void draw2DMap(SDL_Renderer* renderer, int map[MAP_SIZE][MAP_SIZE][MAP_SIZE]){

		SDL_RenderClear(renderer);
	unsigned int from = 100;
	unsigned int to = 400;
	unsigned int x[] = { from, from };
	unsigned int y[] = { to, from };
	unsigned int z[] = { from, to };
	unsigned int a[] = { to, to };
	unsigned int color[] = { 255, 255, 255 };
	//drawRect(renderer, x, y, z, a, color, 0xFF);
	int toAdd = (to - from) / 9;
	color[0] = 255;
	color[1] = 255;
	color[2] = 255;
	for(unsigned int i = 0; i < MAP_SIZE; i++) {
		for(unsigned int j = 0; j < MAP_SIZE; j++) {
			x[0] = from + i * toAdd + 2; x[1] = from + j * toAdd + 2;
			y[0] = x[0] + toAdd; y[1] = x[1];
			z[0] = x[0]; z[1] = x[1] + toAdd;
			a[0] = x[0] + toAdd; a[1] = x[1] + toAdd;
			if(map[i][j][4] == 1) {
				for(unsigned int c = 0; c < 3; c++){
					color[c] = 255;
				}
			} else {
				for(unsigned int c = 0; c < 3; c++){
					color[c] = 0;
				}
			}
			drawHollowedRect(renderer, x, y, z, a, color, 0xFF);
		}
	}

	SDL_RenderPresent(renderer);
}

void draw(SDL_Renderer* renderer)
{
	SDL_RenderClear(renderer);

	unsigned int x[] = { 100, 100 };
	unsigned int y[] = { 300, 100 };
	unsigned int z[] = { 100, 300 };
	unsigned int a[] = { 300, 300 };
	unsigned int color[] = { 255, 255, 255 };

	drawCube(renderer, x, y, z, a, color, 0xFF);


	SDL_RenderPresent(renderer);
}*/

void drawRect(SDL_Renderer* renderer, int x, int y, int w, int h) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SDL_RenderDrawRect(renderer, &rect);
}

void drawFilledRect(SDL_Renderer* renderer, int x, int y, int w, int h) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SDL_RenderFillRect(renderer, &rect);
}

void drawMap2D(SDL_Renderer* renderer, int map[MAP_SIZE][MAP_SIZE][MAP_SIZE]) {
	SDL_RenderClear(renderer);


	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0xFF);

	int x = 50;
	int y = 50;
	int wh = 50;
	for(unsigned int i = 0; i < MAP_SIZE; i++) {
		for(unsigned int j = 0; j < MAP_SIZE; j++) {
			if(map[i][j][4] == PLAYER_SLOT) {
				SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0xFF);
			} else {
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0xFF);
			}
			drawFilledRect(renderer, x + (wh * i), y + (wh * j), wh ,wh);
		}
	}

	SDL_RenderPresent(renderer);
}