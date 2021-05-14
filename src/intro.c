/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** intro
*/

#include "myrpg.h"

void man_intro(rpg_t *rpg)
{
    if (rpg->intro.step < 11 || rpg->intro.step > 20) {
        rpg->intro.pos.x += 50;
        sfSprite_setPosition(rpg->game.player.sprite.spt, rpg->intro.pos);
    }
    if (rpg->intro.step > 33) {
        back_to_game(&rpg->game);
        rpg->state = GAME;
    }
    rpg->intro.step++;
}