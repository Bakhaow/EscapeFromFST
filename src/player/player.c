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

void freePlayer(Player* p) {
	free(p);
}