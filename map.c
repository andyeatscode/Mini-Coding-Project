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

void init_dungeon(char** map, int cols, int rows)
{
    int i, j, way_height, way_width;
    way_height = (int)((rows) * 0.3);
    way_width = (int)((cols) * 0.3);

    /*
    XX|    |X
    ---    --
     
    ---    --
    XX|    |X
    */

    for(i = 0; i < rows; ++i){
        for(j = 0; j < cols; ++j){
            map[i][j] = '.';
        }
    }

    /*Horizontaler Schnitt*/
    for (i = way_height + 1; i < (way_height + 1) * 2; ++i){
        for(j = 0; j < cols; j++) {
            map[i][j] = 32;
        }
    }

    /*Vertikaler schnitt*/
    for (i = way_width + 1; i < (way_width + 1) * 2; ++i){
        for(j = 0; j < rows; j++) {
            map[j][i] = 32;
        }
    }

    map[rows - 2][(int)(0.5 * cols)] = 'P';
    pos_x = (int)(0.5 * cols);
    pos_y = rows - 2;

}

void create_dungeonroom(char** map, int cols, int rows, char direction)
{
    /*Direction defines where the playercame from i.e. d means he exited the last room in the up direction*/
    int i, j;
    char new_dir;
    i = rand() % 3;
    switch (direction) {
        case 'u':
            map[0 + 2][(int)(0.5 * cols)] = 'P';
            pos_x = (int)(0.5 * cols);
            pos_y = rows - 2;

            if(i == 0) new_dir = 'r';
            if(i == 1) new_dir = 'l';
            if(i == 2) new_dir = 'd';
            break;
            
        case 'r':
            map[(int)(0.5 * rows)][cols - 2] = 'P';
            pos_x = (int)(0.5 * cols);
            pos_y = rows - 2;

            if(i == 0) new_dir = 'l';
            if(i == 1) new_dir = 'u';
            if(i == 2) new_dir = 'd';
            break;

        case 'l':
            map[(int)(0.5 * rows)][0 + 2] = 'P';
            pos_x = (int)(0.5 * cols);
            pos_y = rows - 2;
            
            if(i == 0) new_dir = 'r';
            if(i == 1) new_dir = 'u';
            if(i == 2) new_dir = 'd';
            break;
            
        case 'd':
            map[rows - 2][(int)(0.5 * cols)] = 'P';
            pos_x = (int)(0.5 * cols);
            pos_y = rows - 2;
            
            if(i == 0) new_dir = 'r';
            if(i == 1) new_dir = 'u'; 
            if(i == 2) new_dir = 'l';
            break;
        default:
            exit(1);
    }

    /*
    XXX              - - ----
                   >>>>>>>>>>>>>>
                   --- -----|v|
    X|-
    XPX
    */

}


void print_interface(char** map, int cols, int rows)
{
    int i, j;
    /*Map-Box*/
    printf("%c", 201);
    for(i = 1; i < (2 * (cols - 2)) + 1; ++i){
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
        for(j = 1; j < cols - 1; ++j){
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
    for(i = 1; i < (2 * (cols - 2)) + 1; ++i){
        printf("%c", 205);
    }
    printf("%c", 188);
    printf("\n");
}

void fill_map(char** map, int cols, int rows){
    int stone_amount = 0, tree_amount = 0, bush_amount = 0, i = 0, object_x = 0, object_y = 0, map_type = 0;
    double space = (double)(rows * cols);
    srand(time(NULL));

    map_type = rand() % 4;

    /*
    Map-types:

    0. Grassland
    1. Forest
    2. Mixed
    3. xXMountainXx
    
    */

    /*on the smallest map is only 0.01 allowed!!!*/
    switch (map_type)
    {
    case 0:
        printf("\n\n\n------------------------------------\nYou entered the grasslands!\n------------------------------------\n");
        stone_amount = rand() % ((int)(space * 0.09));
        tree_amount = rand() % ((int)(space * 0.02));
        bush_amount = rand() % ((int)(space * 0.15));
        break;
    
    case 1:
        printf("\n\n\n------------------------------------\nYou entered the forest\n------------------------------------\n");
        stone_amount = rand() % ((int)(space * 0.08));
        tree_amount = (space * 0.1) + rand() % ((int)(space * 0.2));
        bush_amount = rand() % ((int)(space * 0.1));
        break;

    case 2:
        printf("\n\n\n------------------------------------\nYou entered the wilderness!\n------------------------------------\n");
        if(STONE_PERCENTAGE) stone_amount = rand() % ((int)(space * STONE_PERCENTAGE));
        if(TREE_PERCENTAGE) tree_amount = rand() % ((int)(space * TREE_PERCENTAGE));
        if(BUSH_PERCENTAGE) bush_amount = rand() % ((int)(space * BUSH_PERCENTAGE));
        break;
    
    case 3:
        printf("\n\n\n------------------------------------\nYou entered the mountain region!\n------------------------------------\n");
        stone_amount = (space * 0.1) + rand() % ((int)(space * 0.2));
        tree_amount = rand() % ((int)(space * 0.05));
        bush_amount = rand() % ((int)(space * 0.05));
        break;
    
    default:
        printf("\n\n\n------------------------------------\nYou lost your hat! Please try again...\n------------------------------------\n");
        exit(1);
        break;
    }

    
    if((rand() % 101) < (int)(DUNGEON_PERCENTAGE * 100)){
        while (1) {
            object_x = 1 + rand() % (cols - 1);
            object_y = 1 + rand() % (rows - 1);
            if(map[object_y][object_x] == 32 && map[object_y - 1][object_x] == 32 && map[object_y][object_x - 1] == 32 && map[object_y - 1][object_x - 1] == 32){
               /*Rechts unten*/
               map[object_y][object_x] = -68;
               /*Rechts oben*/
               map[object_y - 1][object_x] = -69;
               /*Unten Links*/
               map[object_y][object_x - 1] = -56;
               /*Oben Links*/
               map[object_y - 1][object_x - 1] = -55;
               break;
            }
        }
    }


    for(i = 0; i < tree_amount; ++i){
        object_x = 1 + rand() % (cols - 1);
        object_y = 1 + (rand() % (rows - 3));
        
        if((map[object_y][object_x] == TREE_TOP || map[object_y][object_x] == ' ') && map[object_y - 1][object_x] == 32 && (map[object_y + 1][object_x] == 32 || map[object_y + 1][object_x] == TREE_LOG)){
            map[object_y - 1][object_x] = TREE_TOP; /*mit + verwandelt sich die welt in ein lolipop wunderland*/
            map[object_y][object_x] = TREE_LOG;
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
