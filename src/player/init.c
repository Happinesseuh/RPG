/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** init
*/

#include "myrpg.h"

static inv_t init_inv(inv_t inv)
{
    inv.id = malloc(sizeof(int) * (2));
    inv.id[1] = -1;
    return inv;
}

static spell_t init_spell(spell_t spell)
{
    spell.id = malloc(sizeof(int) * (2));
    spell.id[1] = -1;
    return spell;
}

void init_stat(player_t *player)
{
    player->stat.hp = 100;
    player->stat.xp = 0;
    player->stat.attack = 20;
    player->stat.defense = 3;
    player->gold = 0;
    player->mana = 100;
    player->inventory = init_inv(player->inventory);
    player->spell = init_spell(player->spell);
}

void init_player_sprite(game_t *game)
{
    cstextb(&game->player.sprite.spt, &game->player.sprite.txt, SKIN_PATH[0]);
    srect(&game->player.rect, (int[]){32, 32, 0, 0});
    sfSprite_setTextureRect(game->player.sprite.spt, game->player.rect);
    sfSprite_setScale(game->player.sprite.spt, (sfVector2f){6.25, 6.25});
    game->player.sprite.pos = (sfVector2f){2 * 50 + 300, 2 * 50};
    sfSprite_setPosition(game->player.sprite.spt,
        (sfVector2f){POS_LIST[CHOICE_7][0] * 50 + 21.5, 5 * 50});
}

int init_player(game_t *game)
{
    game->player.state = ALIVE;
    game->player.finish = true;
    game->player.rect.width = 32;
    game->player.rect.height = 32;
    game->player_pos.x = 2;
    game->player_pos.y = 2;
    game->player_pos.z = 0;
    game->player.inventory.max = 0;
    game->player.inventory.pos = (sfVector2f){0, 500};
    init_player_sprite(game);
    init_lvl(game);
    init_xp_bar(game);
    game->player.clock = sfClock_create();
    return (0);
}