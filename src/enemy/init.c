/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** init
*/

#include "myrpg.h"

void fill_enemy(enemy_t *enemy)
{
    enemy->stat.hp = 100;
    enemy->stat.attack = 5;
    enemy->stat.xp = 10;
    enemy->stat.defense = 10;
    enemy->gold = 10;
    enemy->state = ALIVE;
    enemy->finish = false;
    cstextb(&enemy->sprite.spt, &enemy->sprite.txt,
        "rss/enemies/en1.png");
    srect(&enemy->sprite.rect, (int[]){32, 32, 0, 0});
    sfSprite_setTextureRect(enemy->sprite.spt, enemy->sprite.rect);
    sfSprite_setScale(enemy->sprite.spt, (sfVector2f){4, 4});
    enemy->sprite.pos = (sfVector2f){300, 300};
    sfSprite_setPosition(enemy->sprite.spt, enemy->sprite.pos);
}