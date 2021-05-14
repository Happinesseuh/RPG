/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** init_storage
*/

#include "myrpg.h"

void init_base_map(game_t *game, int i, int j)
{
    if (game->map.map[game->pos_tile][i][j] == 'O')
        game->map.tile[game->pos_tile].square[game->map.count].txt
        = sfTexture_createFromFile("./rss/map/mur.png", NULL);
    if (game->map.map[game->pos_tile][i][j] == 'S')
        game->map.tile[game->pos_tile].square[game->map.count].txt
        = sfTexture_createFromFile("./rss/map/exit.png", NULL);
    if (game->map.map[game->pos_tile][i][j] == '.')
        game->map.tile[game->pos_tile].square[game->map.count].txt
        = sfTexture_createFromFile("./rss/map/sol.png", NULL);
}

void init_map_texture(game_t *game)
{
    game->map.count = 0;
    game->map.next = 0;
    game->quest.next = 0;

    for (int i = 0; game->map.map[game->pos_tile][i]; i++) {
        for (int j = 0; game->map.map[game->pos_tile][i][j]; j++) {
            game->map.tile[game->pos_tile].square[game->map.count].spt
            = sfSprite_create();
            init_map_object(game, i, j);
            init_enemies(game, i, j);
            init_base_map(game, i, j);
            sfSprite_setTexture(game->map.tile[game->pos_tile]
            .square[game->map.count].spt,
            game->map.tile[game->pos_tile].square[game->map.count].txt, sfTrue);
            sfSprite_setPosition(game->map.tile[game->pos_tile].
            square[game->map.count].spt, spos(j * 50 + 300, i * 50));
            game->map.count += 1;
        }
    }
}

void set_cursor_pos(rpg_t *rpg)
{
    sfRenderWindow_setMouseCursorVisible(rpg->window, sfFalse);
    if (rpg->event.type == sfEvtMouseMoved) {
        rpg->game.map.cursor.pos.x = rpg->event.mouseMove.x;
        rpg->game.map.cursor.pos.y = rpg->event.mouseMove.y;
        sfSprite_setPosition(rpg->game.map.cursor.spt,
            rpg->game.map.cursor.pos);
    }
}
