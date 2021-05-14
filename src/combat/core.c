/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** core
*/

#include "myrpg.h"

void manage_attack(rpg_t *rpg)
{
    int damage = 0;

    if (!rpg->game.player.finish || rpg->game.enemy.state == DEAD)
        return;
    sfSprite_setPosition(rpg->game.player.sprite.spt, (sfVector2f) {900, 300});
    if (rpg->game.player.stat.attack > rpg->game.enemy.stat.defense)
        damage = rpg->game.player.stat.attack - rpg->game.enemy.stat.defense;
    else {
        damage = 0;
        rpg->game.enemy.stat.defense -= rpg->game.player.stat.attack;
    }
    rpg->game.enemy.stat.hp -= damage;
    if (rpg->game.enemy.stat.hp < 0)
        rpg->game.enemy.state = DEAD;
    rpg->game.player.finish = false;
    rpg->game.enemy.finish = true;
}

void idle_anim(rpg_t *rpg)
{
    static float y = 300;

    if (sfClock_getElapsedTime(rpg->game.player.clock).microseconds > 500000) {
        y += 10;
        if (y > 300)
            y = 290;
        sfSprite_setPosition(rpg->game.player.sprite.spt,
            (sfVector2f) {1300, y});
        sfSprite_setPosition(rpg->game.enemy.sprite.spt,
            (sfVector2f){rpg->game.enemy.sprite.pos.x, y});
        sfClock_restart(rpg->game.player.clock);
    }
}

void manage_combat(rpg_t *rpg)
{
    init_combat(rpg);
    idle_anim(rpg);

    if (rpg->game.player.finish)
        player_turn(rpg);
    else if (rpg->game.enemy.finish)
        enemy_turn(rpg);
}