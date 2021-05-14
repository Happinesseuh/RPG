/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** init
*/

#include "myrpg.h"

void init_combat(rpg_t *rpg)
{
    char *path[3] = {"rss/enemies/en1.png",
        "rss/enemies/en2.png", "rss/enemies/en3.png"};
    sfTexture *txt;

    if (rpg->game.s_combat.en < 0 || rpg->game.s_combat.en > 4)
        rpg->game.s_combat.en = 1;
    txt = sfTexture_createFromFile(path[rpg->game.s_combat.en - 1], NULL);
    sfSprite_setPosition(rpg->game.player.sprite.spt, (sfVector2f){1300, 300});
    sfSprite_setScale(rpg->game.player.sprite.spt, (sfVector2f){4, 4});
    srect(&rpg->game.player.rect, (int[]){32, 32, 0, 32});
    sfSprite_setTexture(rpg->game.enemy.sprite.spt, txt, sfTrue);
    sfSprite_setTextureRect(rpg->game.enemy.sprite.spt,
        rpg->game.enemy.sprite.rect);
}

void init_ui(game_t *game)
{
    cstextb(&game->s_combat.player_hp.spt, &game->s_combat.player_hp.txt,
        "rss/hud/health.png");
    srect(&game->s_combat.player_hp.rect, (int[]){500, 50, 0, 0});
    game->s_combat.player_hp.pos = (sfVector2f){6.5 * 50, 12 * 50};
    sfSprite_setTextureRect(game->s_combat.player_hp.spt,
        game->s_combat.player_hp.rect);
    sfSprite_setPosition(game->s_combat.player_hp.spt,
        game->s_combat.player_hp.pos);
    cstextb(&game->s_combat.enemy_hp.spt,
        &game->s_combat.enemy_hp.txt, "rss/hud/health.png");
    srect(&game->s_combat.enemy_hp.rect, (int[]){500, 50, 0, 0});
    game->s_combat.enemy_hp.pos = (sfVector2f){6.5 * 50, 3 * 50};
    sfSprite_setTextureRect(game->s_combat.enemy_hp.spt,
        game->s_combat.enemy_hp.rect);
    sfSprite_setPosition(game->s_combat.enemy_hp.spt,
        game->s_combat.enemy_hp.pos);
}