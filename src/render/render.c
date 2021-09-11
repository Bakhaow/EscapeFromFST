/* Window drawing management */

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
	SDL_Window* Window = NULL;

	// window creation
	Window = SDL_CreateWindow("EFST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);

	return Window;
}

SDL_Renderer* createRenderer(SDL_Window* win)
{
	//Declaring the variable for the Renderer context.
	SDL_Renderer* Renderer = NULL;

	//Create the Renderer with the window.
	Renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);

	//Return the Renderer.
	return Renderer;
}