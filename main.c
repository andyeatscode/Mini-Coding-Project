#include <stdlib.h>
#include "map.h"
#include "controls.h"

int pos_x, pos_y;

int main(void){
  char player_name[15], **map;
  int rand_x, rand_y;
  int map_rows = 20, map_cols = 30;

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
  printf("The journey awaits you, %s!\n", player_name);

  while(1){
    print_interface(map, map_cols, map_rows);
    player_control(map, map_cols, map_rows);
  }

  return 0;
}
