/* Window render management */

#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>

#include "render.h"
#include "../mapping/map.h"
#include "../player/player.h"
#include "../maths.h"

int initSDL()
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
	win = SDL_CreateWindow("Escape From FST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

	return win;
}

SDL_Renderer* createRenderer(SDL_Window* win)
{
	SDL_Renderer* renderer = NULL;

	// renderer creation
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);

	return renderer;
}

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

void drawTri(SDL_Renderer* renderer, int x, int x1, int y, int y1, int z, int z1) {
	SDL_Point p[4] = {
		{x, x1},
		{y, y1},
		{z, z1},
		{x, x1}
	};
	SDL_RenderDrawLines(renderer, p, 4);
}

void drawFilledTri(SDL_Renderer* renderer, int x, int x1, int y, int y1, int z, int z1)
{
	// Méthode du barycentre
	int maxX = max(x, max(y, z));
	int minX = min(x, min(y, z));
	int maxY = max(x1, max(y1, z1));
	int minY = min(x1, min(y1, z1));

	int v1[] = {y - x, y1 - x1};
	int v2[] = {z - x, z1 - x1};

	for (int i = minX; i <= maxX; i++) {
		for (int j = minY; j <= maxY; j++) {
			int q[] = {i - x, j - x1};

			float s = crossProduct(q, v2) / crossProduct(v1, v2);
			float t = crossProduct(v1, q) / crossProduct(v1, v2);

			if ( (s >= 0) && (t >= 0) && (s + t <= 1)) {
				SDL_RenderDrawPoint(renderer, i, j);
			}
		}
	}
}

void drawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
   const int32_t diameter = (radius * 2);

   int32_t x = (radius - 1);
   int32_t y = 0;
   int32_t tx = 1;
   int32_t ty = 1;
   int32_t error = (tx - diameter);

   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
}

/*void drawFilledCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
	//WIP
	const int32_t diameter = (radius * 2);

   	int32_t x = (radius - 1);
   	int32_t y = 0;
   	int32_t tx = 1;
   	int32_t ty = 1;
   	int32_t error = (tx - diameter);

	while (x >= y)
	{
		//  Each of the following renders an octant of the circle
		SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
		SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
		SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
		SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
			SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
		SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
		SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
		SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

		if (error <= 0)
		{
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}*/

void drawMap2D(SDL_Renderer* renderer, int map[MAP_SIZE][MAP_SIZE]) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0xFF);
	for(unsigned int i = 0; i < MAP_SIZE; i++) {
		for(unsigned int j = 0; j < MAP_SIZE; j++) {
			if(map[i][j] == FILLED_SLOT) {
				SDL_SetRenderDrawColor(renderer, 255/2, 255/2, 255/2, 0xFF);
			} else {
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0xFF);
			}
			drawFilledRect(renderer, (WH * i), (WH * j), WH ,WH);
		}
	}
}

void drawPlayer2D(SDL_Renderer* renderer, Player * p) {
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0xFF);
	drawCircle(renderer, WH * p->xCoord + WH / 2, WH * p->yCoord + WH / 2, WH / 4);
}

void drawRay(SDL_Renderer* renderer, Map* m, Player* p) {

	const float fov = M_PI / 3;

	for(size_t i = 0; i < SCREEN_WIDTH; i++) {
		float angle = p->xOffset - fov / 2 + fov * i / (float) SCREEN_WIDTH;
		SDL_SetRenderDrawColor(renderer, 50, 50, 50, 0xFF);
		float c = 0;
		float x, y;
		for (; c<20; c+=.05) {
			x = p->xCoord + c*cos(angle);
			y = p->yCoord + c*sin(angle);
			//printf("\nEh: %d\n", m->map[(int)x][(int)y]);
			if (m->map[(int)x][(int)y] != EMPTY_SLOT) break;
		}
		int pX = WH * p->xCoord + WH / 2;
		int pY = WH * p->yCoord + WH / 2;
		SDL_RenderDrawLine(renderer, pX, pY, WH * x, WH * y);

	}

}

void drawMap3D(SDL_Renderer* renderer, Map* m, Player* p) {

	const float fov = M_PI / 3;

	for(size_t i = 0; i < SCREEN_WIDTH; i++) {
		float angle = p->xOffset - fov / 2 + fov * i / (float) SCREEN_WIDTH;
		SDL_SetRenderDrawColor(renderer, 50, 50, 50, 0xFF);
		float c = 0;
		float x, y;
		for (; c<20; c+=.05) {
			x = p->xCoord + c*cos(angle);
			y = p->yCoord + c*sin(angle);
			if (m->map[(int)x][(int)y] != EMPTY_SLOT) {
				size_t column_height = SCREEN_HEIGHT / c * cos(angle - p->xOffset);
				SDL_RenderDrawLine(renderer, i, SCREEN_HEIGHT / 2 - column_height, i, SCREEN_HEIGHT / 2 + column_height / 2);
			}
		}
	}

}

void draw(SDL_Renderer* renderer, Map * m, Player * p)
{
	

	/*drawMap2D(renderer, m->map);
	drawPlayer2D(renderer, p);
	drawRay(renderer, m, p);
	for(int i = 0; i < 1; i += 0.2) {
		p->xOffset += i;
		drawMap3D(renderer, m, p);
	}*/
	drawMap3D(renderer, m, p);
}