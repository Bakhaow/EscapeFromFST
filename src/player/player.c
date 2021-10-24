#include "player.h"

Player* createPlayer(int x, int y, int z, int xOff, int yOff) {
	Player *p = calloc(5, sizeof(Player));

	p->xCoord = x;
	p->yCoord = y;
	p->zCoord = z;
	p->xOffset = xOff;
	p->yOffset = yOff;

	return p;
}

void freePlayer(Player* p) {
	free(p);
}