/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** back_to
*/

#include "myrpg.h"

void back_to_game(game_t *game)
{
    game->quest.start = true;
    srect(&game->player.rect, (int[]){32, 32, 0, 0});
    sfSprite_setTextureRect(game->player.sprite.spt, game->player.rect);
    sfSprite_setScale(game->player.sprite.spt, (sfVector2f){1.5, 1.5});
    game->player_pos.x = 2;
    game->player_pos.y = 2;
    sfSprite_setColor(game->rain.spt, sfWhite);
    game->player.stat.xp += game->enemy.stat.xp;
}

void back_to_combat(game_t *game)
{
    srect(&game->player.rect, (int[]){32, 32, 0, 0});
    sfSprite_setTextureRect(game->player.sprite.spt, game->player.rect);
    sfSprite_setScale(game->player.sprite.spt, (sfVector2f){6.25, 6.25});
        game->player.sprite.pos = (sfVector2f){2 * 50 + 300, 2 * 50};
    sfSprite_setPosition(game->player.sprite.spt,
        (sfVector2f){POS_LIST[CHOICE_7][0] * 50 + 21.5, 5 * 50});
    sfSprite_setColor(game->rain.spt, sfRed);
}

void back_to_intro(game_t *game, intro_t *intro)
{
    intro->pos = (sfVector2f){3 * 50, 9 * 50};
    intro->rect = (sfFloatRect){32, 32, 0, 64};
    srect(&game->player.rect, (int[]){32, 32, 0, 64});
    sfSprite_setTextureRect(game->player.sprite.spt, game->player.rect);
    sfSprite_setScale(game->player.sprite.spt, (sfVector2f){1.5, 1.5});
    sfSprite_setPosition(game->player.sprite.spt, intro->pos);
    intro->clock = sfClock_create();
    intro->step = 0;
}