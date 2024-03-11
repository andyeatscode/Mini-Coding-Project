#include "map.h"

void print_interface(char** map, int cols, int rows)
{
  int i, j;
  for(i = 0; i < rows; ++i){
    for(j = 0; j < cols; ++j){
      printf("%c ", map[i][j]);
    }
    printf("\n");
}

