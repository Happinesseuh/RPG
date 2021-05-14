/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-enzo1.vallet
** File description:
** man
*/

#include "myrpg.h"

int init_music(rpg_t *rpg)
{
    sfSoundBuffer *clic = sfSoundBuffer_createFromFile("rss/sound/s_clic.wav");
    sfSoundBuffer *inv = sfSoundBuffer_createFromFile("rss/sound/drop.wav");

    rpg->game.sound.music = sfMusic_createFromFile("rss/sound/music.ogg");
    rpg->game.sound.s_clic = sfSound_create();
    rpg->game.sound.s_inv = sfSound_create();
    sfSound_setBuffer(rpg->game.sound.s_clic, clic);
    sfSound_setBuffer(rpg->game.sound.s_inv, inv);
    sfMusic_setLoop(rpg->game.sound.music, sfTrue);
    sfMusic_setVolume(rpg->game.sound.music, 50);
    sfMusic_play(rpg->game.sound.music);
    rpg->game.sound.b_music = true;
    rpg->game.sound.sound = true;
    return (0);
}