#ifndef _PLAYER_H_
#define _PLAYER_H_

typedef struct {
	int xCoord;
	int yCoord;
	int zCoord;
	int xOffset;
	int yOffset;
} Player;

Player* create_player(int xCoord, int yCoord, int zCoord, int xOffset, int yOffset);
void free_player(Player* p);


#endif