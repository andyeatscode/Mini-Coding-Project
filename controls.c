#include "controls.h"

int player_control(char** map, int cols, int rows){
    extern int pos_x, pos_y;
    extern item player_inventory[];

    int i = 0, res = 0, j = 0, res_port = 0;
    char input[7], checker;

    scanf("%6s", input);

    while (input[i] != '\0'){
        input[i] = toupper(input[i]);
        i++;
    }

    if (strcmp(input, "RIGHT") == 0 || strcmp(input, "R") == 0) {
        if (pos_x == cols - 1) {
            printf("You tried walking into unknown land Do you want to change the location? (y/n)\n");
            while(1) {
                if (scanf("%c", &checker) == 1 && (checker == 'y' || checker == 'n')) break;
            }
            if (checker == 'y') {
                pos_x = 0;
                checker = ' '; 
                return -3;
            }
            checker = ' '; 
        } else if (map[pos_y][pos_x + 1] == ' '){
            map[pos_y][pos_x] = ' ';
            pos_x++;
            map[pos_y][pos_x] = PLAYER;
        }
    } else if (strcmp(input, "LEFT") == 0 || strcmp(input, "L") == 0) {
        if (pos_x == 0) {
            printf("You tried walking into unknown land Do you want to change the location? (y/n)\n");
            while(1) {
                if (scanf("%c", &checker) == 1 && (checker == 'y' || checker == 'n')) break;
            }
            if (checker == 'y') {
                pos_x = cols - 1;
                checker = ' '; 
                return -3;
            }
            checker = ' '; 
        } else if (map[pos_y][pos_x - 1] == ' '){
            map[pos_y][pos_x] = ' ';
            pos_x--;
            map[pos_y][pos_x] = PLAYER;
        }
    } else if (strcmp(input, "UP") == 0 || strcmp(input, "U") == 0) {
        if (pos_y == 0) {
            printf("You tried walking into unknown land Do you want to change the location? (y/n)\n");
            while(1) {
                if (scanf("%c", &checker) == 1 && (checker == 'y' || checker == 'n')) break;
            }
            if (checker == 'y') {
                pos_y = rows - 1;
                checker = ' '; 
                return -3;
            }
            checker = ' '; 
        } else if (map[pos_y - 1][pos_x] == ' ') {
            map[pos_y][pos_x] = ' ';
            pos_y--;
            map[pos_y][pos_x] = PLAYER;
        }
    } else if (strcmp(input, "DOWN") == 0 || strcmp(input, "D") == 0) {
        if (pos_y == rows - 1) {
            printf("You tried walking into unknown land Do you want to change the location? (y/n)\n");
            while(1) {
                if (scanf("%c", &checker) == 1 && (checker == 'y' || checker == 'n')) break;
            }
            if (checker == 'y') {
                pos_y = 0;
                checker = ' '; 
                return -3;
            }
            checker = ' '; 
        } else if (map[pos_y + 1][pos_x] == ' '){
            map[pos_y][pos_x] = ' ';
            pos_y++;
            map[pos_y][pos_x] = PLAYER;
        }
    } else if (strcmp(input, "GATHER") == 0) {
        printf("What are you looking for?\n");
        while(1){
            if (scanf("%5s", input) == 1) break;
        }
        i = 0;
        while (input[i] != '\0'){
            input[i] = toupper(input[i]);
            i++;
        }

        if (strcmp(input, "WOOD") == 0) {
            res = TREE_LOG;
            res_port = 1;
        } else if (strcmp(input, "BERRY") == 0) {
            res = BUSH;
            res_port = 3;
        } else if (strcmp(input, "STONE") == 0) {
            res = STONE;
            res_port = 2;
        } else {
            printf("Material not found!\n");
            res = 0;
        }

        if(res != 0){
            for(i = -1; i < 2; ++i){
                for(j = -1; j < 2; ++j){
                    if(map[pos_y + i][pos_x + j] == res){
                        player_inventory[res_port].amount++;
                        goto end;
                    }
                }
            }
        }
        printf("Material not found!\n");
    
    } else {
        printf("Invalid move, please try again!\n");
    }
    end:
    return 0;
}
