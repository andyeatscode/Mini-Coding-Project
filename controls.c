#include "controls.h"

void player_control(char** map, int cols, int rows){
    extern int pos_x, pos_y;
    int i = 0;
    char input[6]; 

    scanf("%5s", input);

    while (input[i] != '\0'){
        input[i] = toupper(input[i]);
        i++;
    }

    if (strcmp(input, "RIGHT") == 0) {
        if (pos_x == cols - 1) {
            printf("You tried walking into a wall, that hurts!\n");
        } else if (map[pos_y][pos_x + 1] == ' '){
            map[pos_y][pos_x] = ' ';
            pos_x++;
            map[pos_y][pos_x] = PLAYER;
        }
    } else if (strcmp(input, "LEFT") == 0) {
        if (pos_x == 0) {
            printf("You tried walking into a wall, that hurts!\n");
        } else if (map[pos_y][pos_x - 1] == ' '){
            map[pos_y][pos_x] = ' ';
            pos_x--;
            map[pos_y][pos_x] = PLAYER;
        }
    } else if (strcmp(input, "UP") == 0) {
        if (pos_y == 0) {
            printf("You tried walking into a wall, that hurts!\n");
        } else if (map[pos_y - 1][pos_x] == ' ') {
            map[pos_y][pos_x] = ' ';
            pos_y--;
            map[pos_y][pos_x] = PLAYER;
        }
    } else if (strcmp(input, "DOWN") == 0) {
        if (pos_y == rows - 1) {
            printf("You tried walking into a wall, that hurts!\n");
        } else if (map[pos_y + 1][pos_x] == ' '){
            map[pos_y][pos_x] = ' ';
            pos_y++;
            map[pos_y][pos_x] = PLAYER;
        }
    } else {
        printf("Invalid move, please try again!\n");
    }
}
