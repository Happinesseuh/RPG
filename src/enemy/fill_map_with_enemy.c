/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** fill_map_with_enemy.c
*/

#include <stdlib.h>
#include "myrpg.h"

static int generate_enemy(char **tile)
{
    int row = (rand() % 15) + 2;
    int col = (rand() % 17) + 2;
    int pos = rand() % 3;
    char *list = "123";

    if (tile[row][col] != '.')
        return (0);
    tile[row][col] = list[pos];
    return (1);
}

int fill_map_with_enemy(tile_t *tile)
{
    int nb = open_read_enemy_conf("rss/enemy.conf");
    int ret = nb;
    int rdm = 0;

    if (nb == -1) {
        nb = 5;
        ret = 5;
    }
    while (nb > 0) {
        rdm = (rand() % 8) + 1;
        nb -= generate_enemy(tile[rdm]);
    }
    return (ret);
}
