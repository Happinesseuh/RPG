/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** myrpg.h
*/

#ifndef MYRPG_H
#define MYRPG_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "engine.h"
#include "../lib/include/myprintf.h"

static const char * const SKIN_PATH[] = {
    "rss/skin/default.png", "rss/skin/male.png",
    "rss/skin/female.png"};

// - - - - - - - - - - - - - - - - - utils - - - - - - - - - - - - - - - - - //

typedef enum life_e {
    ALIVE,
    DEAD
} life_t;

typedef struct pos_s {
    int x;
    int y;
    int z;
} pos_t;

typedef struct sprite_s {
    sfTexture *txt;
    sfSprite *spt;
    sfVector2f pos;
    sfIntRect rect;
} sprite_t;

// - - - - - - - - - - - - - - - - - player - - - - - - - - - - - - - - - - - //
typedef struct stat_s {
    int hp;
    int xp;
    int attack;
    int defense;
} stat_t;

typedef struct spell_s {
    int *id;
} spell_t;

typedef struct inv_s {
    int *id;
    int max;
    int full;
    int objects[16][2];
    sprite_t sprite[2];
    sfIntRect rect[16];
    sfSprite *floor[16];
    sfSprite *inv[16];
    sfClock *clock;
    sfVector2f pos;
    sfText *text;
    int nb_inv[4];
} inv_t;

typedef struct lvl_s {
    sfText *text;
    sfText *text_s;
    sfVector2f pos;
    sfVector2f pos_s;
    int nb;
    sprite_t xp;
} lvl_t;

typedef struct player_s {
    sprite_t sprite;
    sfClock *clock;
    sfIntRect rect;
    stat_t stat;
    spell_t spell;
    inv_t inventory;
    int mana;
    int gold;
    lvl_t lvl;
    life_t state;
    bool finish;
    int skin;
} player_t;

typedef struct enemy_s {
    sprite_t sprite;
    stat_t stat;
    int gold;
    life_t state;
    bool finish;
} enemy_t;

typedef struct intro_s {
    int step;
    sfFloatRect rect;
    sfVector2f pos;
    sfClock *clock;
    sprite_t *sprite;
} intro_t;

typedef struct quest_s {
    sprite_t dialog[5];
    bool start;
    sfText *text[4];
    int monsters;
    int killed;
    int pos_monsters[9][2];
    int next;
} quest_t;
// - - - - - - - - - - - - - - - - - map - - - - - - - - - - - - - - - - - //

typedef struct square_s {
    sprite_t square[360];
} square_t;

typedef char ** tile_t;

typedef struct map_s {
    sfFloatRect rect;
    tile_t *map;
    square_t tile[10];
    sprite_t cursor;
    int count;
    int next;
    char c;
    sprite_t player_mini_map;
} map_t;

// - - - - - - - - - - - - - - - - - base - - - - - - - - - - - - - - - - - //

typedef struct button_s {
    sfTexture *txt;
    sfSprite *spt;
    state_t state;
    sfIntRect rect;
} button_t;

typedef struct sprite_combat_s {
    sprite_t player_hp;
    sprite_t enemy_hp;
    int en;
} s_combat_t;

typedef struct sound_s {
    sfSound *s_clic;
    sfSound *s_inv;
    sfMusic *music;
    bool sound;
    bool b_music;
} sound_t;

typedef struct pause_s {
    sprite_t blur;
    bool pause;
} pause_t;

typedef struct game_s
{
    pause_t pause;
    bool inventory;
    enum {WON, LOSE} end;
    player_t player;
    enemy_t enemy;
    s_combat_t s_combat;
    map_t map;
    pos_t player_pos;
    int pos_tile;
    quest_t quest;
    sound_t sound;
    sfClock *rain_clock;
    sprite_t rain;
    sprite_t how;
} game_t;

typedef struct scene_s {
    int nb_but;
    button_t *but;
    sprite_t back;
} scene_t;

typedef struct rpg_s
{
    sfRenderWindow *window;
    sfVector2f window_size;
    sfEvent event;
    sfClock *clock;
    state_t state;
    scene_t *scene;
    game_t game;
    intro_t intro;
    bool free;
} rpg_t;

void my_rpg(void);

void show_rewards(rpg_t *rpg);

int init_window(rpg_t *def);
int init_rpg(rpg_t *def);

int fill_scenes(rpg_t *rpg);

void draw_scene(rpg_t *rpg);

void cstextb(sfSprite **sprite, sfTexture **text, char const *str);
void srect(sfIntRect *rect, int *dims);
void srect_2(sfIntRect *rect, float width, float height);

void man_intro(rpg_t *rpg);

/* PLAYER */
void back_to_game(game_t *game);
void back_to_combat(game_t *game);
void back_to_intro(game_t *game, intro_t *intro);

int init_player(game_t *game);
void move_player_in_map(rpg_t *rpg);
void change_map(rpg_t *rpg);
void init_stat(player_t *player);
void init_lvl(game_t *game);
void init_xp_bar(game_t *game);
void lvl_up(rpg_t *rpg);
void anim_player(rpg_t *rpg, int top);
void move_right(rpg_t *rpg, sfVector2f pos, int tile);
void move_left(rpg_t *rpg, sfVector2f pos, int tile);
void move_up(rpg_t *rpg, sfVector2f pos, int tile);
void move_down(rpg_t *rpg, sfVector2f pos, int tile);

/* MAP */
char **open_read(char *path);
tile_t *map_data_init(sfRenderWindow *win);
char **my_str_to_word_array(char const *str, char delim);
void set_cursor_pos(rpg_t *rpg);
void init_storage(game_t *game);
void init_map_texture(game_t *game);
int init_map(rpg_t *rpg);
void init_mini_map(game_t *game);
void pos_in_mini_map(game_t *game, int state);
void init_map_object(game_t *game, int i, int j);
void init_enemies(game_t *game, int i, int j);

/* INVENTORY */
void init_rect_objects(rpg_t *rpg);
void ctext(sfText **text, char *path_font, char *str);
void init_inventory_text(game_t *game);
void generate_object(tile_t *tile, sfRenderWindow *win);

/* QUEST */
void check_collision(rpg_t *rpg);
void init_quest(game_t *game);
int check_start_pnj(game_t *game);
// int check_pnj(sfSprite *pnj, sfSprite *player, game_t *game, int state);
void init_kill_monsters(game_t *game);
void init_end_quest(game_t *game);
int check_end_pnj(game_t *game);

/* COMBAT */
void display_scene_combat(rpg_t *rpg);
void manage_combat(rpg_t *rpg);
void manage_attack(rpg_t *rpg);
void init_ui(game_t *game);

/* ENEMY */
int fill_map_with_enemy(tile_t *tile);
int open_read_enemy_conf(char *path);
void fill_enemy(enemy_t *enemy);

void back_to_game(game_t *game);
void check_enemies(rpg_t *rpg);

/* SOUND */
void man_music_state(game_t *game);
int init_music(rpg_t *rpg);
void man_sound_state(game_t *game);

/* TOOLS */
sfVector2f spos(float x, float y);

void change_skin(player_t *player, bool left);
void advanced_button(rpg_t *rpg, state_t state);
void start_game(rpg_t *rpg, button_t *but);

void init_rain(rpg_t *rpg);
void do_rain(rpg_t *rpg);

void event_quest(rpg_t *rpg);

void draw_quest(rpg_t *rpg);
void draw_inventory(rpg_t *rpg);

void init_combat(rpg_t *rpg);
void init_ui(game_t *game);

void udpate_hp_bar(rpg_t *rpg);
void player_turn(rpg_t *rpg);
void enemy_turn(rpg_t *rpg);
void use_potion(rpg_t *rpg);

void free_all(rpg_t *rpg);

#endif /* MYRPG_H */
