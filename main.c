#include <stdlib.h>
#include "map.h"

int main(void){
  char player_name[15], **map;


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
    print_interface(map, 10, 10);
    break;
  }

  return 0;
}
