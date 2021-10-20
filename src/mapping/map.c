#include "map.h"

Map* create_map() {
	Map* m = calloc(2, sizeof(Map));

	unsigned int i, j, k;
	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			for (k = 0; k < MAP_SIZE; k++) {
				m->map[i][j][k] = EMPTY_SLOT;
			}
		}
	}

	return m;
}

void free_map(Map* map) {
	unsigned int i, j, k;
	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			for (k = 0; k < MAP_SIZE; k++) {
				free(map->map[i][j][k]);
			}
		}
	}
	free(map);
}

void add_player(Map* map, int xCoord, int yCoord, int zCoord) {
	map->map[xCoord][yCoord][zCoord] = PLAYER_SLOT;
}

void print_map(Map* m) {
	unsigned int i, j, k;
	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			for (k = 0; k < MAP_SIZE; k++) {
				printf("%d", m->map[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
		printf("\n");
	}
}