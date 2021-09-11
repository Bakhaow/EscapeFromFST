#include <stdio.h>
#include <SDL.h>

#include "render/render.h"

/*
 *
 *	EFST Main program
 *
 */

// debug purpose only
void debugging(char msg[]) {
	printf("[EFST-DEBUG] %s\n", msg);
}

// Main
int main(int argc, char* argv[]) {

	debugging("start");
	init_sdl();

	debugging("sdl init end");
	SDL_Window* win = createWindow();

	SDL_Renderer* Renderer = createRenderer(win);

	draw(Renderer);

	debugging("window creation end");
	SDL_Delay(2000);

	debugging("end");

	SDL_Quit();
	return 0;
}