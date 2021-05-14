/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** init_amp_object
*/

#include "myrpg.h"

void choose_init_enemies(game_t *game, int i, int j, char *path)
{
    if (game->map.map[game->pos_tile][i][j] == game->map.c) {
        game->map.tile[game->pos_tile].square[game->map.count].txt
        = sfTexture_createFromFile(path, NULL);
        game->quest.pos_monsters[game->quest.next][0] = game->pos_tile;
        game->quest.pos_monsters[game->quest.next][1] = game->map.count;
        game->quest.next += 1;
    }
}

void choose_init_object(game_t *game, int i, int j, char *path)
{
    if (game->map.map[game->pos_tile][i][j] == game->map.c) {
        game->map.tile[game->pos_tile].square[game->map.count].txt
        = sfTexture_createFromFile(path, NULL);
        game->player.inventory.objects[game->map.next][0] = game->pos_tile;
        game->player.inventory.objects[game->map.next][1] = game->map.count;
        game->map.next += 1;
    }
}

void init_enemies(game_t *game, int i, int j)
{
    char *path[3] = {"rss/enemies/en1_1.png", "rss/enemies/en2_2.png",
    "rss/enemies/en3_3.png"};

    if (game->map.map[game->pos_tile][i][j] == '1') {
        game->map.c = '1';
        choose_init_enemies(game, i, j, path[0]);
    }
    if (game->map.map[game->pos_tile][i][j] == '2') {
        game->map.c = '2';
        choose_init_enemies(game, i, j, path[1]);
    }
    if (game->map.map[game->pos_tile][i][j] == '3') {
        game->map.c = '3';
        choose_init_enemies(game, i, j, path[2]);
    }
}

void init_map_object(game_t *game, int i, int j)
{
    char *path[4] = {"rss/item/bow.png", "rss/item/pv.png",
    "rss/item/xp.png", "rss/item/sword.png"};

    if (game->map.map[game->pos_tile][i][j] == 'B') {
        game->map.c = 'B';
        choose_init_object(game, i, j, path[0]);
    }
    if (game->map.map[game->pos_tile][i][j] == 'V') {
        game->map.c = 'V';
        choose_init_object(game, i, j, path[1]);
    }
    if (game->map.map[game->pos_tile][i][j] == 'X') {
        game->map.c = 'X';
        choose_init_object(game, i, j, path[2]);
    }
    if (game->map.map[game->pos_tile][i][j] == 'R') {
        game->map.c = 'R';
        choose_init_object(game, i, j, path[3]);
    }
}