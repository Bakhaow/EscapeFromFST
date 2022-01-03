#include "player.h"

void init(Player *p) {
    p->x = 3;
    p->y = 3;
    p->dx = cos(p->angle);
    p->dy = sin(p->angle);
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