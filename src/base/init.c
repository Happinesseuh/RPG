/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** init
*/

#include "myrpg.h"

static int init_scenes(rpg_t *rpg)
{
    rpg->scene = malloc(sizeof(scene_t) * (NB_SCENES + 1));
    if (!rpg->scene)
        return (1);
    (void)rpg->scene[NB_SCENES];
    for (int i = 0; i < NB_SCENES; i++) {
        rpg->scene[i].nb_but = NB_BUTS[i];
        rpg->scene[i].but = malloc(sizeof(button_t) * NB_BUTS[i]);
        if (!rpg->scene[i].but)
            return (1);
    }
    return (0);
}

int init_map(rpg_t *rpg)
{
    rpg->game.map.map = map_data_init(rpg->window);
    rpg->game.quest.monsters = fill_map_with_enemy(rpg->game.map.map);
    rpg->game.pos_tile = 0;
    rpg->game.quest.start = false;
    init_map_texture(&rpg->game);
    if (!rpg->game.map.map)
        return (1);
    cstextb(&rpg->game.map.cursor.spt,
        &rpg->game.map.cursor.txt, "rss/hud/cursor.png");
    sfSprite_setScale(rpg->game.map.cursor.spt, (sfVector2f){0.75, 0.75});
    init_quest(&rpg->game);
    init_inventory_text(&rpg->game);
    init_mini_map(&rpg->game);
    init_kill_monsters(&rpg->game);
    init_music(rpg);
    rpg->game.quest.killed = 0;
    rpg->game.s_combat.en = 0;
    for (int i = 0; i < 4; i++)
        rpg->game.player.inventory.nb_inv[i] = 0;
    return (0);
}

int init_rpg(rpg_t *rpg)
{
    rpg->free = false;
    rpg->state = MENU;
    rpg->window_size.x = sfRenderWindow_getSize(rpg->window).x;
    rpg->window_size.y = sfRenderWindow_getSize(rpg->window).y;
    if (init_scenes(rpg))
        return (1);
    rpg->game.pause.pause = false;
    cstextb(&rpg->game.pause.blur.spt, &rpg->game.pause.blur.txt,
        "rss/hud/background_blur.png");
    rpg->game.inventory = false;
    rpg->game.player.skin = 0;
    init_rain(rpg);
    rpg->clock = sfClock_create();
    cstextb(&rpg->game.how.spt, &rpg->game.how.txt, "rss/how/how.png");
    sfSprite_setPosition(rpg->game.how.spt, (sfVector2f){200, 50});
    return (0);
}

int init_window(rpg_t *rpg)
{
    sfVideoMode mode = {1600, 900, 60};

    rpg->window = sfRenderWindow_create(mode, "MyRPG",
        sfTitlebar | sfClose, NULL);
    if (!rpg->window)
        return (1);
    sfRenderWindow_setFramerateLimit(rpg->window, 60);
    return (0);
}
