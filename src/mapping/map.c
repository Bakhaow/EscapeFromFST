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

// on ajoute un joueur sur la map
void updatePlayerPosition(Map* map, int xCoord, int yCoord) {
	map->map[xCoord][yCoord] = PLAYER_SLOT;
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