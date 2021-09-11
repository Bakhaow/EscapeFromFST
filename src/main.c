#include <stdio.h>
#include <SDL.h>

/*
 *
 *	EFST Main program
 *
 */

int init_sdl()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("sdl init error!");
		return -1;
	}
	return 0;
}

// debug purpose only
void debugging(char msg[]) {
	printf("[EFST-DEBUG] %s\n", msg);
}

SDL_Window* createWindow()
{
	SDL_Window* Window = NULL;

	// window creation
	Window = SDL_CreateWindow("EFST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);

	return Window;
}

// Main
int main(int argc, char* argv[]) {

	debugging("start");
	init_sdl();

	debugging("sdl init end");
	SDL_Window* win = createWindow();

	debugging("window creation end");
	SDL_Delay(2000);

	debugging("end");

	SDL_Quit();
	return 0;
}