/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** free
*/

#include "myrpg.h"

void free_player(game_t *game)
{
    free(game->player.inventory.id);
    free(game->player.spell.id);
    sfSprite_destroy(game->player.sprite.spt);
    sfTexture_destroy(game->player.sprite.txt);
    sfText_destroy(game->player.lvl.text_s);
    sfText_destroy(game->player.lvl.text);
    sfSprite_destroy(game->player.lvl.xp.spt);
    sfTexture_destroy(game->player.lvl.xp.txt);
}