#ifndef MAP_INCLUDED_H
#define MAP_INCLUDED_H

#define PLAYER 80
#define STONE_PERCENTAGE 0.10
#define TREE_PERCENTAGE 0.10
#define BUSH_PERCENTAGE 0.10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inventory.h"

void print_interface(char** map, int cols, int rows);
char** map_init(int rows, int cols);
void fill_map(char** map, int rows, int cols);
void refresh_map(char** map, int cols, int rows);

#endif