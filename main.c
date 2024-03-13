#include <stdlib.h>
#include "map.h"
#include "controls.h"
#include "inventory.h"

int pos_x, pos_y;
inventory player_inventory;

int main(void){
  char player_name[15], **map;
  int rand_x, rand_y;
  int map_rows, map_cols, input_size;


  player_inventory.stick.amount = 0;
  strcpy(player_inventory.stick.name, "Sticks");

  player_inventory.wood.amount = 0;
  strcpy(player_inventory.stick.name, "Wood");
  
  player_inventory.stone.amount = 0;
  strcpy(player_inventory.stick.name, "Stone");

  player_inventory.berry.amount = 0;
  strcpy(player_inventory.stick.name, "Berry");

  printf("Welcome to \n");
  printf(" _______  ______   _        _______ _________         _________ _______ \n");
  printf("(  ___  )(  ___ \\ ( \\      (  ____ \\__   __/|\\     /|\\__   __/(  ___  )\n");
  printf("| (   ) || (   ) )| (      | (    \\/   ) (   | )   ( |   ) (   | (   ) |\n");
  printf("| |   | || (__/ / | |      | (__       | |   | |   | |   | |   | |   | |\n");
  printf("| |   | ||  __ (  | |      |  __)      | |   | |   | |   | |   | |   | |\n");
  printf("| |   | || (  \\ \\ | |      | (         | |   | |   | |   | |   | |   | |\n");
  printf("| (___) || )___) )| (____/\\| (____/\\   | |   | (___) |   | |   | (___) |\n");
  printf("(_______)|/ \\___/ (_______/(_______/   )_(   (_______)   )_(   (_______)\n");


  printf("A huge world of adventures and dangers awaits their hero. Become the strongest and beat the ...\n");
  printf("Whats your name?\n");
  scanf("%14s", player_name);

  while(1) {
    printf("How large is your map?\n1. Small\n2. Medium\n3. Large\n4. Custom\n");
    if (scanf("%i", &input_size) == 1 && input_size > 0 && input_size < 5) break;
    printf("Oh no, something went wrong, please contact micorsoft tech sopport! :)\n");
  }

  switch(input_size)
  {
  case 1:
    map_rows = 10;
    map_cols = 15;
    break;
    
  case 2:;
    map_rows = 20;
    map_cols = 30;
    break;
    
  case 3:
    map_rows = 30;
    map_cols = 45;
    break;
    
  case 4: 
    while(1) {
      printf("Put in your map height!\n");
      if (scanf("%i", &map_rows) == 1 && map_rows > 10 && map_rows < 101) break;
    };
    while(1) {
      printf("Put in your map width!\n");
      if (scanf("%i", &map_cols) == 1 && map_cols > 10 && map_cols < 101) break;
    };
    break;
    
  default:
    exit(1);
    break;
  }

  printf("\n\n\n------------------------------------\nThe journey awaits you, %s!\n------------------------------------\n", player_name);

  if ((map = map_init(map_cols, map_rows)) == NULL){
    exit(1);
  }

  fill_map(map, map_cols, map_rows);

  srand(time(NULL));
  while (1) {
    pos_x = rand_x = rand() % map_cols;
    pos_y = rand_y = rand() % map_rows;
    if (map[pos_y][pos_x] == ' ') break;
  }
  map[rand_y][rand_x] = PLAYER;

  while(1){
    print_interface(map, map_cols, map_rows);

    switch (player_control(map, map_cols, map_rows))
    {
    case -3:
      refresh_map(map, map_cols, map_rows);
      break;

    case 0:
      break;

    default:
      exit(1);
      break;
    }
  }

  return 0;
}
