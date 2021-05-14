/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** adv
*/

#include "myrpg.h"

void change_skin(player_t *player, bool left)
{
    if (!left && player->skin + 1 == 3)
        player->skin = 0;
    else if (left && player->skin - 1 < 0)
        player->skin = 2;
    else
        player->skin += (!left) ? 1 : -1;
    player->sprite.txt = sfTexture_createFromFile(SKIN_PATH[player->skin],
        NULL);
    sfSprite_setTexture(player->sprite.spt, player->sprite.txt, sfTrue);
    sfSprite_setTextureRect(player->sprite.spt, player->rect);
}

void advanced_button(rpg_t *rpg, state_t state)
{
    if (state == QUIT)
        sfRenderWindow_close(rpg->window);
    if (state == SOUND)
        man_sound_state(&rpg->game);
    if (state == MUSIC)
        man_music_state(&rpg->game);
    if (state == ATTACK)
        manage_attack(rpg);
    if (state == INV && rpg->state == COMBAT)
        rpg->game.inventory = (rpg->game.inventory) ? false : true;
    if (state == LEAVE) {
        back_to_game(&rpg->game);
        rpg->state = GAME;
    }
    if (state == LEFT)
        change_skin(&rpg->game.player, true);
    else if (state == RIGHT)
        change_skin(&rpg->game.player, false);
}

void start_game(rpg_t *rpg, button_t *but)
{
    if (but->state == GAME)
        back_to_game(&rpg->game);
    if (but->state == COMBAT)
        back_to_combat(&rpg->game);
    if (but->state == INTRO)
        back_to_intro(&rpg->game, &rpg->intro);
    rpg->state = but->state;
}