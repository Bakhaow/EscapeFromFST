#include <stdio.h>
#include <SDL.h>

#include "render/render.h"
#include "player/player.h"
#include "mapping/map.h"

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

	//Map* map = create_map();

	//Player* p = create_player(5, 5, 5, 0, 0);

	//add_player(map, p->xCoord, p->yCoord, p->zCoord);

	draw(Renderer);

	debugging("window creation end");
	SDL_Delay(20000);

	debugging("end");

	SDL_Quit();
	return 0;
}