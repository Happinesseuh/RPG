/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** draw
*/

#include "myrpg.h"

static void draw_intro(sfRenderWindow *window, game_t *game, intro_t *intro)
{
    sfRenderWindow_drawSprite(window, game->quest.dialog[0].spt, NULL);
    sfRenderWindow_drawSprite(window, game->player.sprite.spt, NULL);
    if (intro->step >= 11 && intro->step <= 20)
        sfRenderWindow_drawSprite(window, game->quest.dialog[1].spt, NULL);
}

void draw_inventory(rpg_t *rpg)
{
    for (int i = 0; i < rpg->game.player.inventory.max; i++) {
        sfRenderWindow_drawSprite(rpg->window,
            rpg->game.player.inventory.floor[i], NULL);
        sfRenderWindow_drawSprite(rpg->window,
            rpg->game.player.inventory.inv[i], NULL);
    }
    if (rpg->game.player.inventory.full == 1) {
        sfRenderWindow_drawText(rpg->window,
            rpg->game.player.inventory.text, NULL);
        if (sfClock_getElapsedTime(rpg->game.player.inventory.clock)
            .microseconds > 2000000) {
            rpg->game.player.inventory.full = 0;
            sfClock_restart(rpg->game.player.inventory.clock);
        }
    }
}

static void draw_game(rpg_t *rpg)
{
    for (int i = 0; i < 360; i++)
        sfRenderWindow_drawSprite(rpg->window,
            rpg->game.map.tile[rpg->game.pos_tile].square[i].spt, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->game.player.lvl.text, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->game.player.lvl.text_s, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->game.player.lvl.xp.spt, NULL);
    if (rpg->game.pos_tile == 8 &&
        rpg->game.quest.killed >= rpg->game.quest.monsters) {
        init_end_quest(&rpg->game);
        sfRenderWindow_drawSprite(rpg->window,
            rpg->game.quest.dialog[3].spt, NULL);
        if (check_end_pnj(&rpg->game))
            rpg->state = END;
    }
    draw_quest(rpg);
    draw_inventory(rpg);
    sfRenderWindow_drawSprite(rpg->window, rpg->game.player.sprite.spt, NULL);
    sfRenderWindow_drawSprite(rpg->window,
        rpg->game.map.player_mini_map.spt, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->game.rain.spt, NULL);
}

static void draw_buttons(rpg_t *rpg)
{
    for (int i = 0; i < rpg->scene[rpg->state].nb_but; i++) {
        if ((rpg->state == COMBAT && i >= 3 && !rpg->game.inventory) ||
            (rpg->state == COMBAT && rpg->game.pause.pause) ||
            (rpg->state == GAME && !rpg->game.pause.pause))
            break;
        sfRenderWindow_drawSprite(rpg->window,
            rpg->scene[rpg->state].but[i].spt, NULL);
    }
}

void draw_scene(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    sfRenderWindow_drawSprite(rpg->window,
        rpg->scene[rpg->state].back.spt, NULL);
    if (rpg->state == INTRO)
        draw_intro(rpg->window, &rpg->game, &rpg->intro);
    if (rpg->state == GAME)
        draw_game(rpg);
    else if (rpg->state == COMBAT)
        display_scene_combat(rpg);
    if (rpg->state == SKIN)
        sfRenderWindow_drawSprite(rpg->window,
            rpg->game.player.sprite.spt, NULL);
    if (rpg->state == HOW)
        sfRenderWindow_drawSprite(rpg->window, rpg->game.how.spt, NULL);
    draw_buttons(rpg);
    sfRenderWindow_drawSprite(rpg->window, rpg->game.map.cursor.spt, NULL);
    sfRenderWindow_display(rpg->window);
}