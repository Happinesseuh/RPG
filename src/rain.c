/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** rain
*/

#include "myrpg.h"

void init_rain(rpg_t *rpg)
{
    cstextb(&rpg->game.rain.spt,
        &rpg->game.rain.txt, "rss/hud/rain_game.png");
    srect(&rpg->game.rain.rect, (int[]){900, 800, 0, 0});
    sfSprite_setTextureRect(rpg->game.rain.spt, rpg->game.rain.rect);
    sfSprite_setPosition(rpg->game.rain.spt, (sfVector2f){7 * 50, 50});
    sfSprite_setColor(rpg->game.rain.spt, sfWhite);
    rpg->game.rain_clock = sfClock_create();
}

void do_rain(rpg_t *rpg)
{
    if (sfClock_getElapsedTime(rpg->game.rain_clock).microseconds > 100000) {
        rpg->game.rain.rect.left += 900;
        if (rpg->game.rain.rect.left >= 5400)
            rpg->game.rain.rect.left = 0;
        sfSprite_setTextureRect(rpg->game.rain.spt, rpg->game.rain.rect);
        sfClock_restart(rpg->game.rain_clock);
    }
}