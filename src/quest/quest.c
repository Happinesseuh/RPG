/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** quest
*/

#include "myrpg.h"

void event_quest(rpg_t *rpg)
{
    check_collision(rpg);
    if (rpg->game.pos_tile != 0)
        srect(&rpg->game.quest.dialog[0].rect, (int[]){0, 0, 0, 0});
    else
        srect(&rpg->game.quest.dialog[0].rect, (int[]){94, 94, 0, 0});
    sfSprite_setTextureRect(rpg->game.quest.dialog[0].spt,
        rpg->game.quest.dialog[0].rect);
}

void draw_quest(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->game.quest.dialog[2].spt, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawText(rpg->window, rpg->game.quest.text[i], NULL);
}