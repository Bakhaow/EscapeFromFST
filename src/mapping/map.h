#ifndef _MAP_H_
#define _MAP_H_

#define MAP_SIZE 16
#define EMPTY_SLOT 1
#define FILLED_SLOT 2
#define PLAYER_SLOT 3

typedef struct {
	int map[MAP_SIZE][MAP_SIZE];
	int players;
} Map;

Map* createMap();
Map* defaultMap();
void freeMap(Map* map);
void updatePlayerPosition(Map* map, int xCoord, int yCoord);
void printMap(Map* map);


#endif