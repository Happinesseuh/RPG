/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** init_inventory
*/

#include "myrpg.h"

void set_texture_inventory(game_t *game, int i)
{
    sfTexture *txt = sfTexture_createFromFile("rss/map/sol.png", NULL);
    sfVector2f old_pos = sfSprite_getPosition(game->map.tile[game->player.
    inventory.objects[i][0]].square[game->player.inventory.objects[i][1]].spt);
    sfVector2f supp = (sfVector2f){-100, -100};

    game->player.inventory.floor[game->player.inventory.max]
    = sfSprite_create();
    game->player.inventory.inv[game->player.inventory.max] = sfSprite_create();
    sfSprite_setTexture(game->player.inventory.floor[game->player.inventory.max]
    , txt, sfTrue);
    sfSprite_setTexture(game->player.inventory.inv[game->player.inventory.max]
    , game->map.tile[game->player.inventory.objects[i][0]].square[game->player.
    inventory.objects[i][1]].txt, sfTrue);
    sfSprite_setPosition(game->map.tile[game->player.inventory.objects[i][0]].
    square[game->player.inventory.objects[i][1]].spt, supp);
    sfSprite_setPosition(game->player.inventory.floor
    [game->player.inventory.max], old_pos);
    sfSprite_setPosition(game->player.inventory.inv[game->player.inventory.max],
    game->player.inventory.pos);
}

void put_in_inventory(game_t *game, int i)
{
    if (game->player.inventory.max >= 16) {
        game->player.inventory.full = 1;
        return;
    }
    game->player.inventory.pos.x += 50;
    if (game->player.inventory.max % 4 == 0) {
        game->player.inventory.pos.x = 50;
        game->player.inventory.pos.y += 50;
    }
    set_texture_inventory(game, i);
    game->player.inventory.max += 1;
}

int which_item(game_t *game)
{
    char item = game->map.map[game->pos_tile]
    [game->player_pos.y][game->player_pos.x];

    if (item == 'B')
        return (0);
    if (item == 'V')
        return (1);
    if (item == 'X')
        return (2);
    if (item == 'R')
        return (3);
    return (0);
}

void check_collision(rpg_t *rpg)
{
    sfFloatRect obj;
    sfFloatRect player = sfSprite_getGlobalBounds(rpg->game.player.sprite.spt);
    int item = 0;

    for (int i = 0; i != rpg->game.map.next; i++) {
        obj = sfSprite_getGlobalBounds(rpg->game.map.tile[rpg->game.
        player.inventory.objects[i][0]].square[rpg->game.player.
        inventory.objects[i][1]].spt);
        if (sfFloatRect_intersects(&obj, &player, NULL)) {
            item = which_item(&rpg->game);
            rpg->game.player.inventory.nb_inv[item] += 1;
            put_in_inventory(&rpg->game, i);
            sfSound_play(rpg->game.sound.s_inv);
        }
    }
}

void init_inventory_text(game_t *game)
{
    game->player.inventory.full = 0;
    game->player.inventory.clock = sfClock_create();
    ctext(&game->player.inventory.text,
    "rss/hud/fonts/font.ttf", "Inventory full !");
    sfText_setColor(game->player.inventory.text, sfRed);
    sfText_setPosition(game->player.inventory.text, spos(500, 500));
}