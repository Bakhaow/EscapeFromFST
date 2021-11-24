#include <stdio.h>
#include <SDL2/SDL.h>

#include "render/render.h"
#include "player/player.h"
#include "mapping/map.h"

#define MOUSE_SENSITIVITY 1.1

/*
 *
 *	EFST Main program
 *
 */

// debug purpose only
void debugging(char msg[]) {
	printf("[EFST-DEBUG] %s\n", msg);
}

float calcOffset(float off) {
    float temp = (off + 180.0f) / 360.0f;
    return off - ((int)temp - (temp < 0.0f ? 1 : 0)) * 360.0f;
}

// event handler
int handle_events(SDL_Event *e, Player *p, SDL_Window *win, Map* m) {
	Uint8 *keystates = calloc(1, sizeof(keystates));
	while(SDL_PollEvent(e)) {
		if(e->type == SDL_MOUSEMOTION) {
			float xOff = (float) (e->motion.xrel) - ((SCREEN_WIDTH / 2) * 64);
			xOff = xOff / ((SCREEN_WIDTH / 2.) * 64);
			setPlayerOffset(p, xOff * MOUSE_SENSITIVITY, p->yOffset); //
			/*
			xOff = p->xOffset + (xOff / 200);
			printf("xOff %f\n", xOff);
			setPlayerOffset(p, xOff, p->yOffset);
			SDL_WarpMouseInWindow(win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
			*/
		}
		if(e->type == SDL_KEYDOWN){
			switch(e->key.keysym.sym) {
				case SDLK_ESCAPE :
					SDL_Quit();
					debugging("end");
					return 1;
				case SDLK_z:
					movePlayerTo(m, p, p->xCoord - 1, p->yCoord, p->zCoord);
					break;
				case SDLK_s:
					movePlayerTo(m, p, p->xCoord + 1, p->yCoord, p->zCoord);
					break;
				case SDLK_q:
					movePlayerTo(m, p, p->xCoord, p->yCoord - 1, p->zCoord);
					break;
				case SDLK_d:
					movePlayerTo(m, p, p->xCoord, p->yCoord + 1, p->zCoord);
					break;
				case SDLK_c:
					setPlayerOffset(p, p->xOffset * (-1), p->yOffset);
					break;
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
	Player* p = createPlayer(4, 4, 0, 0, 0);

	SDL_Event* event = calloc(1, sizeof(SDL_Event));
	int gameState = 0;

	SDL_SetRelativeMouseMode(SDL_TRUE);

	while(gameState == 0) {
		renderBackground(renderer);
		gameState = handle_events(event, p, win, map);
		draw(renderer, map, p);
		SDL_RenderPresent(renderer);
		//p->xOffset += 0.05;
		//printf("off %f\n", p->xOffset);
	}

	SDL_Delay(3000);
	SDL_Quit();
	return 0;
}