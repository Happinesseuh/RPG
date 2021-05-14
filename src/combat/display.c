/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** display
*/

#include "myrpg.h"

void show_rewards(rpg_t *rpg)
{
    sfText *txt = sfText_create();
    char *tmp = my_strcat("You've earned", my_itoa(rpg->game.enemy.stat.xp));

    tmp = my_strcat(tmp, "xp !");
    if (txt != NULL) {
        ctext(&txt, "rss/hud/fonts/font.ttf", tmp);
        sfText_setPosition(txt, (sfVector2f) {500, 500});
        sfText_setColor(txt, sfYellow);
        sfText_setScale(txt, (sfVector2f) {3, 3});
    }
}

void display_scene_combat(rpg_t *rpg)
{
    if (!rpg->game.inventory)
        sfRenderWindow_drawSprite(rpg->window,
            rpg->game.s_combat.player_hp.spt, NULL);
    if (rpg->game.enemy.stat.hp >= 75)
        sfSprite_setColor(rpg->game.s_combat.enemy_hp.spt,
            sfBlack);
    else if (rpg->game.enemy.stat.hp >= 40)
        sfSprite_setColor(rpg->game.s_combat.enemy_hp.spt, sfBlack);
    else
        sfSprite_setColor(rpg->game.s_combat.enemy_hp.spt, sfRed);
    sfRenderWindow_drawSprite(rpg->window,
        rpg->game.s_combat.enemy_hp.spt, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->game.player.sprite.spt, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->game.enemy.sprite.spt, NULL);
    if (rpg->game.pause.pause)
        sfRenderWindow_drawSprite(rpg->window, rpg->game.pause.blur.spt, NULL);
}