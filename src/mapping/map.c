#include "map.h"

// creer une map
Map* createMap() {
	Map* m = calloc(2, sizeof(Map));

	unsigned int i, j;
	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			m->map[i][j]= EMPTY_SLOT;
		}
	}

	return m;
}

Map* defaultMap() {
	Map* m = calloc(2, sizeof(Map));

	unsigned int i, j;
	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			if(i == 0 || j == 0 || i == MAP_SIZE - 1 || j == MAP_SIZE - 1) {
				m->map[i][j]= FILLED_SLOT;
			} else {
				m->map[i][j]= EMPTY_SLOT;
			}
		}
	}

	return m;
}

// liberer l'espace memoire de la map
void freeMap(Map* map) {
	unsigned int i, j;
	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
				free(map->map[i][j]);
		}
	}
	free(map);
}

// affiche la carte
void printMap(Map* m) {
	unsigned int i, j;
	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
				printf("%d", m->map[i][j]);
		}
		printf("\n");
	}
}

int canBeMovedTo(Map* m, int x, int y, int z) {
	return (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE || z < 0 || z >= MAP_SIZE || m->map[x][y] != EMPTY_SLOT) ? 0 : 1;
}