#ifndef _MAP_H_
#define _MAP_H_

#define MAP_SIZE 9
#define EMPTY_SLOT 1
#define FILLED_SLOT 2
#define PLAYER_SLOT 3

typedef struct {
	int map[MAP_SIZE][MAP_SIZE][MAP_SIZE];
	int players;
} Map;

Map* create_map();
void free_map(Map* map);
void add_player(Map* map, int xCoord, int yCoord, int zCoord);
void print_map(Map* map);


#endif