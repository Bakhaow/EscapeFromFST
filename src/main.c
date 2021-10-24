#include <stdio.h>
#include <SDL2/SDL.h>

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

// event handler
int handle_events(SDL_Event *e, Player *p) {
	Uint8 *keystates = calloc(1, sizeof(keystates));
	while(SDL_PollEvent(e)) {
		if(e->type == SDL_MOUSEMOTION) {
			int xOff = (e->motion.xrel) - ((SCREEN_WIDTH / 2) * 64);
			if(xOff > 0) {
				p->xOffset += 0.05;
			} else {
				p->xOffset -= 0.05;
			}
		}
		if(e->type == SDL_KEYDOWN){
			switch(e->key.keysym.sym) {
				case SDLK_ESCAPE :
					SDL_Quit();
					debugging("end");
					return 1;
				case SDLK_z:
					p->xCoord += 1;
				case SDLK_s:
					p->xCoord -= 1;
				case SDLK_q:
					p->yCoord -= 1;
				case SDLK_d:
					p->yCoord += 1;
			}
		}
	}
	return 0;
}

// Main
int main(int argc, char* argv[]) {

	debugging("start");
	initSDL();

	SDL_Window* win = createWindow();
	SDL_Renderer* renderer = createRenderer(win);

	Map* map = defaultMap();
	Player* p = createPlayer(4, 4, 0, 1, 0);

	SDL_Event* event = calloc(1, sizeof(SDL_Event));
	int gameState = 0;

	SDL_SetRelativeMouseMode(SDL_TRUE);

	while(gameState == 0) {
		renderBackground(renderer);
		gameState = handle_events(event, p);
		draw(renderer, map, p);
		SDL_RenderPresent(renderer);
	}

	SDL_Delay(3000);
	SDL_Quit();
	return 0;
}