/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** rpg
*/

#include "myrpg.h"

static void man_mouse(sfRenderWindow *window, scene_t *scene, rpg_t *rpg)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);
    sfFloatRect rect = {0, 0, 0, 0};

    if (rpg->state == COMBAT && rpg->game.pause.pause)
        return;
    for (int i = 0; i < scene->nb_but; i++) {
        rect = sfSprite_getGlobalBounds(scene->but[i].spt);
        if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y) &&
            (int)scene->but[i].state > (NB_SCENES - 1)) {
            advanced_button(rpg, scene->but[i].state);
            sfSound_play(rpg->game.sound.s_clic);
        }
        else if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y)) {
            start_game(rpg, &scene->but[i]);
            sfSound_play(rpg->game.sound.s_clic);
        }
    }
}

static void man_hover(state_t current, sfRenderWindow *window, button_t *but)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);
    sfFloatRect rect = sfSprite_getGlobalBounds(but->spt);
    int width = (current == COMBAT) ? 200 : 250;
    int height = but->rect.height;

    if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y) &&
        sfMouse_isButtonPressed(sfMouseLeft))
        srect(&but->rect, (int[]){width, height, width * 2, 0});
    else if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y) &&
        !sfMouse_isButtonPressed(sfMouseLeft))
        srect(&but->rect, (int[]){width, height, width, 0});
    else
        srect(&but->rect, (int[]){width, height, 0, 0});
    sfSprite_setTextureRect(but->spt, but->rect);
}

static void rpg_event(sfRenderWindow *window, sfEvent event, rpg_t *rpg)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonReleased &&
        event.mouseButton.button == sfMouseLeft &&
        (rpg->state != GAME || rpg->game.pause.pause))
        man_mouse(rpg->window, &rpg->scene[rpg->state], rpg);
    if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape) &&
        (rpg->state == GAME || rpg->state == COMBAT))
        rpg->game.pause.pause = (rpg->game.pause.pause) ? false : true;
    if (rpg->state == GAME)
        move_player_in_map(rpg);
    set_cursor_pos(rpg);
    for (int i = 0; i < rpg->scene[rpg->state].nb_but; i++)
        if (rpg->state != COMBAT || i < 3)
            man_hover(rpg->state, rpg->window,
                &rpg->scene[rpg->state].but[i]);
    event_quest(rpg);
}

static void rpg_loop(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
        rpg_event(rpg->window, rpg->event, rpg);
    if (sfClock_getElapsedTime(rpg->clock).microseconds > 150) {
        if (rpg->state == COMBAT)
            manage_combat(rpg);
        draw_scene(rpg);
        check_enemies(rpg);
        sfText_setString(rpg->game.quest.text[0],
            my_itoa(rpg->game.quest.killed));
        sfClock_restart(rpg->clock);
    }
    if (!rpg->game.pause.pause && rpg->state == GAME)
        do_rain(rpg);
    if (rpg->state == INTRO &&
        sfClock_getElapsedTime(rpg->intro.clock).microseconds > 400000) {
        man_intro(rpg);
        sfClock_restart(rpg->intro.clock);
    }
}

void my_rpg(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    init_window(rpg);
    init_rpg(rpg);
    init_player(&rpg->game);
    init_map(rpg);
    init_stat(&rpg->game.player);
    fill_scenes(rpg);
    fill_enemy(&rpg->game.enemy);
    init_ui(&rpg->game);
    while (sfRenderWindow_isOpen(rpg->window))
        rpg_loop(rpg);
    free_all(rpg);
}