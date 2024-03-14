#include "map.h"
#include "inventory.h"

extern int pos_x, pos_y;
extern item player_inventory[];
extern stats player_stats[];

char** map_init(int cols, int rows)
{
  char **map;
  int i, j;
  map = malloc((rows + 2) * sizeof(char*));
  if(map == NULL){
        return NULL;
    }
    
  for(i = 0; i < rows; ++i){
    map[i] = malloc((cols + 2) * sizeof(char));
    if(map[i] == NULL){
        return NULL;
    }
  }

  for(i = 0; i < rows ; ++i){
    for(j = 0; j < cols; ++j){
      map[i][j] = 32;
    }
  }

  return map;
}

void refresh_map(char** map, int cols, int rows)
{
    int i, j;

    for(i = 0; i < rows; ++i){
        for(j = 0; j < cols; ++j){
            map[i][j] = 32;
        }
    }

    map[pos_y][pos_x] = 'P';

    fill_map(map, cols, rows);
}

void print_interface(char** map, int cols, int rows)
{
    int i, j;
    /*Map-Box*/
    printf("%c", 201);
    for(i = 1; i < (2 * (cols - 1)) + 1; ++i){
        printf("%c", 205);
    }
    printf("%c", 187);

    /*Iventory-Box*/
    printf("%c", 201);
    for(i = 1; i < MAX_INV_LEN + 6; ++i){
        printf("%c", 205);
    }
    printf("%c", 187);

    /*Stats-Box*/
    printf("%c", 201);
    for(i = 1; i < MAX_STAT_LEN + 10; ++i){
        printf("%c", 205);
    }
    printf("%c", 187);

    printf("\n");

    /*Visible Map is sourended by one extra space in all direction to prevent false memory access*/
    for(i = 1; i < rows - 1; ++i){
        /*Map*/
        printf("%c", 186);
        for(j = 0; j < cols - 1; ++j){
            printf("%c ", map[i][j]);
        }
        printf("%c", 186);

        /*Inventory*/
        if(i - 1 < ITEM_AMOUNT){
            printf("%c  %s %03i   %c", 186, player_inventory[i - 1].name, player_inventory[i - 1].amount, 186);  
        }
        
        if(i - 1 == ITEM_AMOUNT){
            printf("%c", 200);
            for(j = 1; j < (MAX_INV_LEN + 6); ++j){
                printf("%c", 205);
            }
            printf("%c", 188);
        }
        
        /*Stats*/
        if(i - 1< STATS_AMOUNT){
            printf("%c", 186);
            printf("  %s %03i/%03i   ", player_stats[i - 1].name, player_stats[i - 1].amount, player_stats[i - 1].max_amount);
            printf("%c", 186);
        }
        
        if(i - 1 == STATS_AMOUNT){
            printf("%c", 200);
            for(j = 1; j < (MAX_STAT_LEN + 10); ++j){
                printf("%c", 205);
            }
            printf("%c", 188);
        }

        printf("\n");
    }

    /*Map-Box finish*/
    printf("%c", 200);
    for(i = 1; i < (2 * (cols - 1)) + 1; ++i){
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
        object_x = 1 + rand() % (cols - 1);
        object_y = 2 + (rand() % (rows - 3));
        if(map[object_y][object_x] == 32 && map[object_y + 1][object_x] == 32 && map[object_y - 1][object_x] == 32){
            map[object_y][object_x] = TREE_TOP;
            map[object_y + 1][object_x] = TREE_LOG;  
        }
    }
    
    
    for(i = 0; i < stone_amount; ++i){
        object_x = 1 + rand() % (cols - 1);
        object_y = 1 + rand() % (rows - 1);
        if(map[object_y][object_x] == 32){
            map[object_y][object_x] = STONE;
        }
    }

    for(i = 0; i < bush_amount; ++i){
        object_x = 1 + rand() % (cols - 1);
        object_y = 1 + rand() % (rows - 1);
        if(map[object_y][object_x] == 32){
            map[object_y][object_x] = BUSH;
        }
    } 

}
