/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** move_direction
*/

#include "myrpg.h"

void move_right(rpg_t *rpg, sfVector2f pos, int tile)
{
    if (rpg->game.player_pos.x == 18 && (rpg->game.player_pos.y == 8
        || rpg->game.player_pos.y == 9) && tile != 2 && tile != 3
        && tile != 4 && tile != 5 && tile != 8) {
        rpg->game.player.sprite.pos.x = 350;
        rpg->game.player.sprite.pos.y += pos.y;
        rpg->game.player_pos.x = 1;
        rpg->game.pos_tile += 1;
        init_map_texture(&rpg->game);
        pos_in_mini_map(&rpg->game, 1);
    } else if (rpg->game.player_pos.x == 18) {
        return;
    } else {
        rpg->game.player.sprite.pos.x += pos.x;
        rpg->game.player.sprite.pos.y += pos.y;
        rpg->game.player_pos.x += 1;
    }
}

void move_left(rpg_t *rpg, sfVector2f pos, int tile)
{
    if (rpg->game.player_pos.x == 1 && (rpg->game.player_pos.y == 8
        || rpg->game.player_pos.y == 9) && tile != 0 && tile != 3
        && tile != 4 && tile != 5 && tile != 6) {
        rpg->game.player.sprite.pos.x = 1200;
        rpg->game.player.sprite.pos.y += pos.y;
        rpg->game.player_pos.x = 18;
        rpg->game.pos_tile -= 1;
        init_map_texture(&rpg->game);
        pos_in_mini_map(&rpg->game, -1);
    } else if (rpg->game.player_pos.x == 1) {
        return;
    } else {
        rpg->game.player.sprite.pos.x += pos.x;
        rpg->game.player.sprite.pos.y += pos.y;
        rpg->game.player_pos.x -= 1;
    }
}

void move_up(rpg_t *rpg, sfVector2f pos, int tile)
{
    if (rpg->game.player_pos.y == 1 && (rpg->game.player_pos.x == 9
        || rpg->game.player_pos.x == 10) && tile >= 3 && tile != 5) {
        rpg->game.player.sprite.pos.x += pos.x;
        rpg->game.player.sprite.pos.y = 800;
        rpg->game.player_pos.y = 16;
        rpg->game.pos_tile -= 3;
        init_map_texture(&rpg->game);
        pos_in_mini_map(&rpg->game, 2);
    } else if (rpg->game.player_pos.y == 1) {
        return;
    } else {
        rpg->game.player.sprite.pos.x += pos.x;
        rpg->game.player.sprite.pos.y += pos.y;
        rpg->game.player_pos.y -= 1;
    }
}

void move_down(rpg_t *rpg, sfVector2f pos, int tile)
{
    if (rpg->game.player_pos.y == 16 && (rpg->game.player_pos.x == 9
        || rpg->game.player_pos.x == 10) && tile < 6 && tile != 2) {
        rpg->game.player.sprite.pos.x += pos.x;
        rpg->game.player.sprite.pos.y = 50;
        rpg->game.player_pos.y = 1;
        rpg->game.pos_tile += 3;
        init_map_texture(&rpg->game);
        pos_in_mini_map(&rpg->game, -2);
    } else if (rpg->game.player_pos.y == 16) {
        return;
    } else {
        rpg->game.player.sprite.pos.x += pos.x;
        rpg->game.player.sprite.pos.y += pos.y;
        rpg->game.player_pos.y += 1;
    }
}