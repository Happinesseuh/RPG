/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** check_enemies
*/

#include "myrpg.h"

void launch_combat(rpg_t *rpg, sfTexture *txt, int i)
{
    back_to_combat(&rpg->game);
    rpg->state = COMBAT;
    sfSprite_setTexture(rpg->game.map.tile[rpg->game.quest.
        pos_monsters[i][0]].square[rpg->game.quest.pos_monsters[i][1]].spt,
            txt, sfTrue);
    rpg->game.s_combat.en = rpg->game.map.map[rpg->game.pos_tile]
        [rpg->game.player_pos.y][rpg->game.player_pos.x] - '0';
    rpg->game.quest.pos_monsters[i][0] = 0;
    rpg->game.quest.pos_monsters[i][1] = 0;
    if (rpg->game.player.finish) {
        back_to_game(&rpg->game);
        lvl_up(rpg);
    }
}

void check_enemies(rpg_t *rpg)
{
    sfFloatRect obj;
    sfFloatRect player = sfSprite_getGlobalBounds(rpg->game.player.sprite.spt);
    sfTexture *txt = sfTexture_createFromFile("rss/map/sol.png", NULL);

    for (int i = 0; i < rpg->game.quest.next; i++) {
        obj = sfSprite_getGlobalBounds(rpg->game.map.tile[rpg->game.quest.
        pos_monsters[i][0]].square[rpg->game.quest.pos_monsters[i][1]].spt);
        if (sfFloatRect_intersects(&obj, &player, NULL))
            launch_combat(rpg, txt, i);
    }
}