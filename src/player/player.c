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

void movePlayerTo(Map* m, Player* p, int x, int y, int z) {
	if(canBeMovedTo(m, x, y, z)) {
		p->xCoord = x;
		p->yCoord = y;
		p->zCoord = z;
	}
}

void setPlayerOffset(Player* p, float xOff, float zOff) {
	p->xOffset = xOff;
	p->yOffset = zOff;
}

void freePlayer(Player* p) {
	free(p);
}