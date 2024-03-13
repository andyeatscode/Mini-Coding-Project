#include "map.h"

char** map_init(int cols, int rows)
{
  char **map;
  int i, j;
  map = malloc(rows * sizeof(char*));
  if(map == NULL){
        return NULL;
    }
    
  for(i = 0; i < rows; ++i){
    map[i] = malloc(cols * sizeof(char));
    if(map[i] == NULL){
        return NULL;
    }
  }

  for(i = 0; i < rows; ++i){
    for(j = 0; j < cols; ++j){
      map[i][j] = 32;
    }
  }

  return map;
}


void print_interface(char** map, int cols, int rows)
{
    int i, j;

    printf("%c", 201);
    for(i = 1; i < (2 * cols) + 1; ++i){
        printf("%c", 205);
    }
    printf("%c", 187);
    printf("\n");

    for(i = 0; i < rows; ++i){
        printf("%c", 186);
        for(j = 0; j < cols; ++j){
            printf("%c ", map[i][j]);
        }
        printf("%c\n", 186);
    }

    printf("%c", 200);
    for(i = 1; i < (2 * cols) + 1; ++i){
        printf("%c", 205);
    }
    printf("%c", 188);
    printf("\n");
}

void fill_map(char** map, int cols, int rows){
    int stone_amount = 0, tree_amount = 0, bush_amount = 0, i, object_x = 0, object_y = 0;
    double space = (double)(rows * cols);
    srand(time(NULL));
    stone_amount = rand() % ((int)(space * STONE_PERCENTAGE));
    tree_amount = rand() % ((int)(space * TREE_PERCENTAGE));
    bush_amount = rand() % ((int)(space * BUSH_PERCENTAGE));

    for(i = 0; i < tree_amount; ++i){
        object_x = rand() % cols;
        object_y = 1 + (rand() % (rows - 2));
        if(map[object_y][object_x] == 32 && map[object_y + 1][object_x] == 32 && map[object_y - 1][object_x] == 32){
            map[object_y][object_x] = TREE_TOP;
            map[object_y + 1][object_x] = TREE_LOG;  
        }
    }
    

    for(i = 0; i < stone_amount; ++i){
        object_x = rand() % cols;
        object_y = rand() % rows;
        if(map[object_y][object_x] == 32){
            map[object_y][object_x] = STONE;
        }
    }

    for(i = 0; i < bush_amount; ++i){
        object_x = rand() % cols;
        object_y = rand() % rows;
        if(map[object_y][object_x] == 32){
            map[object_y][object_x] = BUSH;
        }
    }

}
