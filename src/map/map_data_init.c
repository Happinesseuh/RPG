/*
** EPITECH PROJECT, 2021
** <Project_name>
** File description:
** map_data_init.c
*/

#include <stdlib.h>
#include "myrpg.h"

static char *get_tile_line(char *str, int ind)
{
    char *ret = malloc(sizeof(char) * 21);

    if (ret == NULL)
        return (NULL);
    for (int i = 0 ; i < 21 ; i++)
        ret[i] = str[i + ind];
    ret[20] = '\0';
    return (ret);
}

static tile_t format_tile(char *tile)
{
    char **ret = malloc(sizeof(char *) * 19);

    if (ret == NULL)
        return (NULL);
    ret[18] = NULL;
    for (int i = 0 ; i < 360 ; i += 20) {
        ret[i / 20] = get_tile_line(tile, i);
        if (ret[i / 20] == NULL)
            return (NULL);
    }
    return (ret);
}

tile_t *map_data_init(sfRenderWindow *win)
{
    tile_t *ret = malloc(sizeof(tile_t) * 9);
    char **map = open_read("rss/tiles.conf");

    if (ret == NULL || map == NULL)
        return (NULL);
    for (int i = 0 ; i < 9 ; i++) {
        ret[i] = format_tile(map[i]);
        if (ret[i] == NULL)
            return (NULL);
    }
    for (int i = 0 ; map[i] ; i++)
        free(map[i]);
    free(map);
    generate_object(ret, win);
    return (ret);
}
