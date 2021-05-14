/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** generate_object.c
*/

#include <stdlib.h>
#include "myrpg.h"

static int generate_obj(char **tile, char c)
{
    int row = (rand() % 15) + 2;
    int col = (rand() % 17) + 2;

    if (tile[row][col] != '.')
        return (0);
    tile[row][col] = c;
    return (1);
}

static void generate_potion(tile_t *tile)
{
    int ite = 0;

    for (int i = 1 ; i <= 8 ; i++) {
        ite = rand() % 5;
        while (ite >= 0)
            ite -= generate_obj(tile[i], 'V');
    }
}

void generate_object(tile_t *tile, sfRenderWindow *win)
{
    srand((unsigned long) win);
    if (rand() % 2) {
        generate_obj(tile[2], 'B');
        generate_obj(tile[5], 'R');
        generate_obj(tile[6], 'X');
    } else if (rand() % 2){
        generate_obj(tile[2], 'X');
        generate_obj(tile[6], 'B');
        generate_obj(tile[5], 'R');
    } else {
        generate_obj(tile[2], 'R');
        generate_obj(tile[6], 'X');
        generate_obj(tile[5], 'B');
    }
    generate_potion(tile);
}
