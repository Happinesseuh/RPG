/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** lvl
*/

#include "myrpg.h"

void init_lvl(game_t *game)
{
    game->player.lvl.nb = 1;
    ctext(&game->player.lvl.text_s, "rss/hud/fonts/font.ttf", "Level:");
    sfText_setColor(game->player.lvl.text_s, sfWhite);
    sfText_scale(game->player.lvl.text_s, spos(2, 2));
    sfText_setCharacterSize(game->player.lvl.text_s, 20);
    game->player.lvl.pos_s = spos(55, 50);
    sfText_setPosition(game->player.lvl.text_s, game->player.lvl.pos_s);
    ctext(&game->player.lvl.text, "rss/hud/fonts/font.ttf",
    my_itoa(game->player.lvl.nb));
    sfText_setColor(game->player.lvl.text, sfWhite);
    sfText_scale(game->player.lvl.text, spos(2, 2));
    sfText_setCharacterSize(game->player.lvl.text, 20);
    game->player.lvl.pos = spos(200, 50);
    sfText_setPosition(game->player.lvl.text, game->player.lvl.pos);
}

void init_xp_bar(game_t *game)
{
    cstextb(&game->player.lvl.xp.spt,
    &game->player.lvl.xp.txt, "rss/hud/xp.png");
    sfSprite_setScale(game->player.lvl.xp.spt, (sfVector2f){0.4, 1});
    game->player.lvl.xp.pos = (sfVector2f) {50, 100};
    sfSprite_setPosition(game->player.lvl.xp.spt, game->player.lvl.xp.pos);
    game->player.lvl.xp.rect.width = 0;
    game->player.lvl.xp.rect.height = 50;
    game->player.lvl.xp.rect.top = 0;
    game->player.lvl.xp.rect.left = 0;
    sfSprite_setTextureRect(game->player.lvl.xp.spt, game->player.lvl.xp.rect);
}

void lvl_up(rpg_t *rpg)
{
    rpg->game.quest.killed += 1;
    rpg->game.player.lvl.xp.rect.width += 250;
    sfSprite_setTextureRect(rpg->game.player.lvl.xp.spt,
    rpg->game.player.lvl.xp.rect);
    if (rpg->game.player.lvl.xp.rect.width >= 500) {
        rpg->game.player.lvl.xp.rect.width = 0;
        sfSprite_setTextureRect(rpg->game.player.lvl.xp.spt,
        rpg->game.player.lvl.xp.rect);
        rpg->game.player.lvl.nb += 1;
        sfText_setString(rpg->game.player.lvl.text,
        my_itoa(rpg->game.player.lvl.nb));
    }
}