#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../mapping/map.h"

typedef struct {
	int xCoord;
	int yCoord;
	int zCoord;
	float xOffset;
	float yOffset;
} Player;

Player* createPlayer(int xCoord, int yCoord, int zCoord, int xOffset, int yOffset);
void freePlayer(Player* p);

void movePlayerTo(Map*  m, Player* p, int x, int y, int z);
void setPlayerOffset(Player* p, float xOff, float zOff);


#endif