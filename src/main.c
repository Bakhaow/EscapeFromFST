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

void fixAngle(Player* p) {
    if(p->angle < 0) {
        p->angle += 2 * M_PI;
    } else if(p->angle > 2 * M_PI) {
        p->angle -= 2 * M_PI;
    }
    p->dx = cos(p->angle);
    p->dy = sin(p->angle);
}



// event handler
int handle_events(SDL_Event *e, Player *p, SDL_Window *win, Map* m) {
	Uint8 *keystates = calloc(1, sizeof(keystates));
    while (SDL_PollEvent(e))
    {
        if (e->type == SDL_KEYDOWN)
        {
            switch (e->key.keysym.sym)
            {
            case SDLK_ESCAPE:
                SDL_Quit();
                return 1;
            case SDLK_q:
                p->angle += M_PI / 2;
                fixAngle(p);
                p->x -= p->dx * 0.2;
                p->y -= p->dy * 0.2;
                p->angle -= M_PI / 2;
                fixAngle(p);
                break;
            case SDLK_d:
                p->angle += M_PI / 2;
                fixAngle(p);
                p->x += p->dx * 0.2;
                p->y += p->dy * 0.2;
                p->angle -= M_PI / 2;
                fixAngle(p);
                break;
            case SDLK_z:
                p->x += p->dx * 0.2;
                p->y += p->dy * 0.2;
                break;
            case SDLK_s:
                p->x -= p->dx * 0.2;
                p->y -= p->dy * 0.2;
                break;
            }
        }
        if(e->type == SDL_MOUSEMOTION) {
			float xOff;
			if(e->motion.x > SCREEN_WIDTH / 2) {
				xOff = 0.01;
			} else if(e->motion.x < SCREEN_WIDTH / 2) {
				xOff = -0.01;
			} else {
				xOff = 0;
			}
            p->angle += xOff;
            fixAngle(p);
			SDL_WarpMouseInWindow(SDL_GetWindowFromID(e->motion.windowID), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
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
	SDL_Cursor * cursor;

	SDL_FreeCursor(SDL_GetCursor());
	cursor = init_system_cursor(arrow);
	SDL_SetCursor(cursor);
	SDL_ShowCursor(SDL_ENABLE);
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