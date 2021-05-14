/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** move_player
*/

#include "myrpg.h"

void anim_player(rpg_t *rpg, int top)
{
    rpg->game.player.rect.top = top;
    if (rpg->game.player.rect.left < 96) {
        rpg->game.player.rect.left += 32;
        if (rpg->game.player.rect.left >= 96) {
            rpg->game.player.rect.left = 0;
            sfSprite_setTextureRect(rpg->game.player.sprite.spt,
            rpg->game.player.rect);
            sfClock_restart(rpg->clock);
        }
    }
}

void where_move(rpg_t *rpg, int top, sfVector2f pos)
{
    if (pos.x == 50)
        move_right(rpg, pos, rpg->game.pos_tile);
    if (pos.x == -50)
        move_left(rpg, pos, rpg->game.pos_tile);
    if (pos.y == 50)
        move_down(rpg, pos, rpg->game.pos_tile);
    if (pos.y == -50)
        move_up(rpg, pos, rpg->game.pos_tile);
    anim_player(rpg, top);
}

void move_player_in_map(rpg_t *rpg)
{
    if (rpg->game.pause.pause)
        return;
    if (rpg->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyDown))
        where_move(rpg, 0, spos(0, 50));
    if (rpg->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyLeft))
        where_move(rpg, 32, spos(-50, 0));
    if (rpg->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyRight))
        where_move(rpg, 64, spos(50, 0));
    if (rpg->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyUp))
        where_move(rpg, 96, spos(0, -50));
    sfSprite_setPosition(rpg->game.player.sprite.spt,
    rpg->game.player.sprite.pos);
    sfSprite_setTextureRect(rpg->game.player.sprite.spt, rpg->game.player.rect);
}
