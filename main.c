#include <stdlib.h>
#include "map.h"
#include "controls.h"
#include "inventory.h"

int pos_x, pos_y;
item player_inventory[ITEM_AMOUNT];
stats player_stats[STATS_AMOUNT];

/*
ToDo:
- Statscreen fix
- Dungeon spawn on map
- Dungeon enter

*/

int main(void){
  char player_name[15], **map;
  int rand_x, rand_y, i = 0;
  int map_rows, map_cols, input_size;

  i = i;

  /*Inventory*/
  player_inventory[0].amount = 0;
  strcpy(player_inventory[0].name, "Stick ");

  player_inventory[1].amount = 0;
  strcpy(player_inventory[1].name, "Wood  ");

  player_inventory[2].amount = 0;
  strcpy(player_inventory[2].name, "Stone ");

  player_inventory[3].amount = 0;
  strcpy(player_inventory[3].name, "Berry ");


  /*Stats*/
  player_stats[0].amount = 1;
  player_stats[0].max_amount = 100;
  strcpy(player_stats[0].name, "Level");

  player_stats[1].amount = 0;
  player_stats[1].max_amount = 10;
  strcpy(player_stats[1].name, "EXP");
  
  player_stats[2].amount = 20;
  player_stats[2].max_amount = 20;
  strcpy(player_stats[2].name, "Health");
  
  player_stats[3].amount = 2;
  player_stats[3].max_amount = 0;
  strcpy(player_stats[3].name, "Attack");

  player_stats[4].amount = 2;
  player_stats[4].max_amount = 0;
  strcpy(player_stats[4].name, "Defense");

  /*Game Start*/
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
    while (getchar() != '\n');
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

  /*Player Spawn*/
  srand(time(NULL));
  while (1) {
    pos_x = rand_x = 1 + rand() % (map_cols - 2);
    pos_y = rand_y = 1 + rand() % (map_rows - 2);
    if (map[pos_y][pos_x] == ' ') break;
  }
  map[rand_y][rand_x] = PLAYER;
  i = 1;
  while(1){

    if(i == -1)print_interface(map, map_cols, map_rows);
    if(i == -2)print_dungeon(map, map_cols, map_rows);

    switch (player_control(map, map_cols, map_rows))
    {
    case -3:
      refresh_map(map, map_cols, map_rows);
      break;

    case 0:
      break;
    
    case SWITCH:
      i = 
      break;

    default:
      exit(1);
      break;
    }
  }

  return 0;
}
