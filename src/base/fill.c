/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** fill
*/

#include "myrpg.h"

static void fill_buttons(scene_t *scene, const int *buts,
    const int *pos, const state_t *go_to)
{
    for (int i = 0; i < scene->nb_but; i++) {
        scene->but[i].txt = sfTexture_createFromFile(BUT_TXT[buts[i]], NULL);
        scene->but[i].spt = sfSprite_create();
        sfSprite_setTexture(scene->but[i].spt,
            scene->but[i].txt, sfTrue);
        scene->but[i].state = go_to[i];
        srect(&scene->but[i].rect, (int[]){250, 100, 0, 0});
        sfSprite_setTextureRect(scene->but[i].spt,
            scene->but[i].rect);
        sfSprite_setPosition(scene->but[i].spt,
            (sfVector2f){POS_LIST[pos[i]][0] * 50, POS_LIST[pos[i]][1] * 50});
    }
}

static void fix_combat(scene_t *scene)
{
    for (int i = 0; i < scene->nb_but; i++) {
        if (i < 3)
            srect(&scene->but[i].rect, (int[]){200, 50, 0, 0});
        else
            srect(&scene->but[i].rect, (int[]){200, 100, 0, 0});
        sfSprite_setTextureRect(scene->but[i].spt,
            scene->but[i].rect);
    }
}

int fill_scenes(rpg_t *rpg)
{
    for (int i = 0; i < NB_SCENES; i++) {
        rpg->scene[i].back.txt = sfTexture_createFromFile(BG[i], NULL);
        rpg->scene[i].back.spt = sfSprite_create();
        sfSprite_setTexture(rpg->scene[i].back.spt,
            rpg->scene[i].back.txt, sfTrue);
        fill_buttons(&rpg->scene[i], BUTTONS[i], BUT_POS[i], GO_TO[i]);
    }
    fix_combat(&rpg->scene[COMBAT]);
    return (0);
}