/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** engine
*/

#ifndef ENGINE_H_
#define ENGINE_H_

typedef enum state_e
{
    MENU,
    SKIN,
    OPTION,
    HOW,
    INTRO,
    GAME,
    COMBAT,
    END,
    PAUSE,
    MUSIC,
    SOUND,
    INV,
    ATTACK,
    LEAVE,
    ITEMS_1,
    ITEMS_2,
    ITEMS_3,
    QUIT,
    LEFT,
    RIGHT
} state_t;

enum choice_e
{
    CHOICE_1,
    CHOICE_2,
    CHOICE_3,
    CHOICE_4,
    CHOICE_5,
    CHOICE_6,
    CHOICE_7,
    CHOICE_8,
    CHOICE_9,
    CHOICE_10,
    CHOICE_11,
    CHOICE_12,
    CHOICE_13,
    CHOICE_14,
    CHOICE_15,
    CHOICE_16,
    CHOICE_17,
    CHOICE_18
};

static const int NB_SCENES = 8;
static const int NB_BUTS[] = {4, 3, 3, 3, 1, 2, 6, 1};

static const char * const BG[] = {
    "rss/hud/background_1.png", "rss/hud/background_2.png",
    "rss/hud/background_1.png", "rss/hud/background_1.png",
    "rss/hud/background_cine.png", "rss/hud/background_6.png",
    "rss/hud/background_combat.png", "rss/hud/background_win.png"};

static const char * const BUT_TXT[] = {
    "rss/but/play.png", "rss/but/how.png",
    "rss/but/option.png", "rss/but/exit.png",
    "rss/but/pause.png", "rss/but/resume.png",
    "rss/but/menu.png", "rss/but/combat.png",

    "rss/but/sound.png", "rss/but/music.png",

    "rss/but/start.png", "rss/but/attack.png",
    "rss/but/items.png", "rss/but/leave.png",
    "rss/hud/item.png", "rss/but/left.png",
    "rss/but/right.png", "rss/but/skip.png"};

static const float POS_LIST[][2] = {
    {10, 11}, {17, 11},
    {10, 14}, {17, 14},
    {10, 17}, {17, 17},

    {13.5, 11}, {13.5, 17},

    {25, 2}, {25, 5},

    {25.5, 12}, {25.5, 14},
    {25.5, 16}, {25.5, 18},

    {4.5, 13.5}, {9.5, 13.5},
    {14.5, 13.5}, {26, 15}};

static const int BUT_POS[][6] = {
    {CHOICE_1, CHOICE_2, CHOICE_3, CHOICE_4},
    {CHOICE_7, CHOICE_3, CHOICE_4},
    {CHOICE_7, CHOICE_3, CHOICE_4},
    {CHOICE_7, CHOICE_3, CHOICE_4},
    {CHOICE_18},
    {CHOICE_3, CHOICE_4},
    {CHOICE_11, CHOICE_12, CHOICE_13,
        CHOICE_15, CHOICE_16, CHOICE_17},
    {CHOICE_7}};

static const int BUTTONS[][6] = {
    {CHOICE_11, CHOICE_2, CHOICE_3, CHOICE_4},
    {CHOICE_1, CHOICE_16, CHOICE_17},
    {CHOICE_7, CHOICE_9, CHOICE_10},
    {CHOICE_1, CHOICE_7, CHOICE_4},
    {CHOICE_18},
    {CHOICE_9, CHOICE_10},
    {CHOICE_12, CHOICE_13, CHOICE_14,
        CHOICE_15, CHOICE_15, CHOICE_15},
    {CHOICE_4}};

static const state_t GO_TO[][6] = {
    {SKIN, HOW, OPTION, QUIT},
    {INTRO, LEFT, RIGHT},
    {MENU, SOUND, MUSIC},
    {GAME, MENU, QUIT},
    {GAME},
    {SOUND, MUSIC},
    {ATTACK, INV, LEAVE,
    ITEMS_1, ITEMS_2, ITEMS_3},
    {QUIT}};

#endif /* !ENGINE_H_ */
