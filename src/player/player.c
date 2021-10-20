#include "player.h"

Player* create_player(int x, int y, int z, int xOff, int yOff) {
	Player *p = calloc(5, sizeof(Player));

	p->xCoord = x;
	p->yCoord = y;
	p->zCoord = z;
	p->xOffset = xOff;
	p->yOffset = yOff;

	return p;
}

void free_player(Player* p) {
	free(p->xCoord);
	free(p->yCoord);
	free(p->zCoord);
	free(p->xOffset);
	free(p->yOffset);
	free(p);
}