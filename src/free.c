/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** free
*/

#include "myrpg.h"

void free_map(game_t *game)
{
    sfSprite_destroy(game->map.cursor.spt);
    sfTexture_destroy(game->map.cursor.txt);
    sfSprite_destroy(game->map.player_mini_map.spt);
    sfTexture_destroy(game->map.player_mini_map.txt);
    free(game->map.map);
}

void free_inventory(game_t *game)
{
    for (int i = 0; i < game->player.inventory.max; i++) {
        sfSprite_destroy(game->player.inventory.floor[i]);
        sfSprite_destroy(game->player.inventory.inv[i]);
    }
    sfText_destroy(game->player.inventory.text);
}

void free_quest(game_t *game)
{
    for (int i = 0; i < 3; i++) {
        sfSprite_destroy(game->quest.dialog[i].spt);
        sfTexture_destroy(game->quest.dialog[i].txt);
    }
    for (int i = 0; i < 4; i++)
        sfText_destroy(game->quest.text[i]);
}

void free_sound(game_t *game)
{
    sfSound_stop(game->sound.s_clic);
    sfSound_stop(game->sound.s_inv);
    sfMusic_stop(game->sound.music);
    sfSound_destroy(game->sound.s_clic);
    sfSound_destroy(game->sound.s_inv);
    sfMusic_destroy(game->sound.music);
}

void free_all(rpg_t *rpg)
{
    free_map(&rpg->game);
    free_inventory(&rpg->game);
    free_quest(&rpg->game);
    free_sound(&rpg->game);
}