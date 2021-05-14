/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** init_quest
*/

#include "myrpg.h"

int check_start_pnj(game_t *game)
{
    sfFloatRect obj = sfSprite_getGlobalBounds(game->quest.dialog[0].spt);
    sfFloatRect player = sfSprite_getGlobalBounds(game->player.sprite.spt);

    if (sfFloatRect_intersects(&obj, &player, NULL)) {
        game->quest.start = true;
        return (1);
    }
    return (0);
}

int check_end_pnj(game_t *game)
{
    sfFloatRect obj = sfSprite_getGlobalBounds(game->quest.dialog[3].spt);
    sfFloatRect player = sfSprite_getGlobalBounds(game->player.sprite.spt);

    if (sfFloatRect_intersects(&obj, &player, NULL))
        return (1);
    return (0);
}

void init_quest(game_t *game)
{
    char *path[5] = {"rss/quest/pnj1.png", "rss/quest/q1.png",
    "rss/quest/obj.png", "rss/quest/pnj2.png", "rss/quest/end.png"};
    sfVector2f pos[5] = {spos(700, 400), spos(200, 200),
    spos(1350, 100), spos(700, 400)};

    for (int i = 0; i < 5; i++) {
        cstextb(&game->quest.dialog[i].spt, &game->quest.dialog[i].txt
        , path[i]);
        sfSprite_setPosition(game->quest.dialog[i].spt, pos[i]);
    }
    sfSprite_setScale(game->quest.dialog[0].spt, (sfVector2f){1.5, 1.5});
}

void init_kill_monsters(game_t *game)
{
    char *path[4] = {"0", "/", my_itoa(game->quest.monsters),
    "Number of monsters"};
    sfVector2f pos[4] = {spos(1400, 350), spos(1440, 350),
    spos(1480, 350), spos(1325, 300)};

    for (int i = 0; i < 4; i++) {
        ctext(&game->quest.text[i], "rss/hud/fonts/font.ttf", path[i]);
        sfText_setColor(game->quest.text[i], sfYellow);
        sfText_setPosition(game->quest.text[i], pos[i]);
    }
    sfText_scale(game->quest.text[3], spos(0.75, 0.75));
}

void init_end_quest(game_t *game)
{
    if (game->pos_tile == 8) {
        srect(&game->quest.dialog[3].rect, (int[]){94, 94, 0, 0});
        sfSprite_setTextureRect(game->quest.dialog[3].spt,
            game->quest.dialog[3].rect);
    }
    sfSprite_setScale(game->quest.dialog[3].spt, (sfVector2f){1.5, 1.5});
    sfSprite_setPosition(game->quest.dialog[3].spt, (sfVector2f){700, 400});
}