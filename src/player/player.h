#ifndef _PLAYER_H_
#define _PLAYER_H_

typedef struct {
	int xCoord;
	int yCoord;
	int zCoord;
	float xOffset;
	float yOffset;
} Player;

Player* createPlayer(int xCoord, int yCoord, int zCoord, int xOffset, int yOffset);
void freePlayer(Player* p);


#endif