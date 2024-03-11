#ifndef MAP_INCLUDED_H
#define MAP_INCLUDED_H

#define STONE -2
#define PLAYER 80
#define STONE_PERCENTAGE 0.10
#define TREE_PERCENTAGE 0.15
#define BUSH_PERCENTAGE 0.10
#define TREE_TOP 79
#define TREE_LOG -70
#define BUSH -99

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_interface(char** map, int cols, int rows);
char** map_init(int rows, int cols);
void fill_map(char** map, int rows, int cols);

#endif