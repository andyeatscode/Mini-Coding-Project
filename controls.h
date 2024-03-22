#ifndef CONTROLS_INCLUDED_H
#define CONTROLS_INCLUDED_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "inventory.h"

#define PLAYER 80

int player_control(char** map, int cols, int rows);
int player_control_dungeon(char** map, int cols, int rows);


#endif