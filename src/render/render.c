/* Window render management */

#include <stdio.h>
#include <SDL.h>

#include "render.h"

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
	win = SDL_CreateWindow("EFST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);

	return win;
}

SDL_Renderer* createRenderer(SDL_Window* win)
{
	SDL_Renderer* renderer = NULL;

	// renderer creation
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);

	return renderer;
}

void drawHollowedTri(SDL_Renderer* renderer, int x[], int y[], int z[], int color[], int alpha)
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

void draw(SDL_Renderer* renderer)
{
	SDL_RenderClear(renderer);

	unsigned int x[] = { 100, 100 };
	unsigned int y[] = { 300, 100 };
	unsigned int z[] = { 100, 300 };
	unsigned int color[] = { 255, 255, 255 };

	//draw a square from 2 tri-angles
	drawTri(renderer, x, y, z, color, 0xFF);
	x[0] = 300; x[1] = 300;
	drawTri(renderer, x, y, z, color, 0xFF);

	SDL_RenderPresent(renderer);
}