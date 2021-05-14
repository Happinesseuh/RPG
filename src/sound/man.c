/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** init
*/

#include "myrpg.h"

void man_music_state(game_t *game)
{
    if (game->sound.b_music) {
        game->sound.b_music = false;
        sfMusic_setVolume(game->sound.music, 0);
    } else if (!game->sound.b_music) {
        game->sound.b_music = true;
        sfMusic_setVolume(game->sound.music, 50);
    }
}

void man_sound_state(game_t *game)
{
    if (game->sound.sound) {
        game->sound.sound = false;
        sfSound_setVolume(game->sound.s_clic, 0);
        sfSound_setVolume(game->sound.s_inv, 0);
    } else if (!game->sound.sound) {
        game->sound.sound = true;
        sfSound_setVolume(game->sound.s_clic, 50);
        sfSound_setVolume(game->sound.s_inv, 50);
    }
}