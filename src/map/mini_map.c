/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** mini_map
*/

#include "myrpg.h"

void init_mini_map(game_t *game)
{
    cstextb(&game->map.player_mini_map.spt,
    &game->map.player_mini_map.txt, "rss/hud/map_pos.png");
    game->map.player_mini_map.pos = (sfVector2f){1300, 600};
    sfSprite_setPosition(game->map.player_mini_map.spt,
    game->map.player_mini_map.pos);
}

void pos_in_mini_map(game_t *game, int state)
{
    if (state == 1 || state == -1)
        game->map.player_mini_map.pos.x += 100 * state;
    if (state == -2)
        game->map.player_mini_map.pos.y += 100;
    if (state == 2)
        game->map.player_mini_map.pos.y -= 100;
    sfSprite_setPosition(game->map.player_mini_map.spt,
    game->map.player_mini_map.pos);
}