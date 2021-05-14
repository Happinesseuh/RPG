/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** turn
*/

#include "myrpg.h"

void udpate_hp_bar(rpg_t *rpg)
{
    srect(&rpg->game.s_combat.enemy_hp.rect,
        (int[]){(rpg->game.enemy.stat.hp / 10 * 50 > 0 ?
            rpg->game.enemy.stat.hp / 10 * 50 : 50), 50, 0, 0});
    sfSprite_setTextureRect(rpg->game.s_combat.enemy_hp.spt,
        rpg->game.s_combat.enemy_hp.rect);
    srect(&rpg->game.s_combat.player_hp.rect,
        (int[]){(rpg->game.player.stat.hp / 10 * 50), 50, 0, 0});
    sfSprite_setTextureRect(rpg->game.s_combat.player_hp.spt,
        rpg->game.s_combat.player_hp.rect);
}

void player_turn(rpg_t *rpg)
{
    udpate_hp_bar(rpg);
    if (rpg->game.player.stat.hp < 10) {
        rpg->game.player.state = DEAD;
        cstextb(&rpg->scene[END].back.spt,
            &rpg->scene[END].back.txt, "rss/hud/background_died.png");
        rpg->state = END;
    }
}

void enemy_turn(rpg_t *rpg)
{
    rpg->game.player.stat.hp -= rpg->game.enemy.stat.attack -
        rpg->game.player.stat.defense;
    if (rpg->game.enemy.stat.hp < 0) {
        rpg->game.enemy.state = DEAD;
        show_rewards(rpg);
        back_to_game(&rpg->game);
        fill_enemy(&rpg->game.enemy);
        rpg->state = GAME;
    }
    rpg->game.player.finish = true;
    rpg->game.enemy.finish = false;
}

void use_potion(rpg_t *rpg)
{
    if (rpg->game.player.inventory.nb_inv[1] > 0) {
        rpg->game.player.inventory.nb_inv[1] -= 1;
        rpg->game.player.stat.hp += 20;
        rpg->game.player.finish = false;
        rpg->game.enemy.finish = true;
    }
}