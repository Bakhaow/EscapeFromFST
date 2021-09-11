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


int main(int argc, char* argv[]) {
	debugging("start");
	init_sdl();

	SDL_Window* Window = createWindow();

	SDL_Renderer* Renderer = createRenderer(Window);

	//Drawing!
	draw(Renderer);

	//Adding a delay.
	SDL_Delay(2000);

	debugging("end");
	SDL_Quit();
	return 0;
}