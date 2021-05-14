/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** tools
*/

#include "myrpg.h"

void cstextb(sfSprite **sprite, sfTexture **text, char const *str)
{
    *text = sfTexture_createFromFile(str, NULL);
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, *text, sfTrue);
}

void srect(sfIntRect *rect, int *dims)
{
    rect->width = dims[0];
    rect->height = dims[1];
    rect->left = dims[2];
    rect->top = dims[3];
}

sfVector2f spos(float x, float y)
{
    sfVector2f vector = {x, y};

    return (vector);
}

void srect_2(sfIntRect *rect, float width, float height)
{
    rect->left = 0;
    rect->top = 0;
    rect->width = width;
    rect->height = height;
}

void ctext(sfText **text, char *path_font, char *str)
{
    *text = sfText_create();
    sfFont *font = sfFont_createFromFile(path_font);

    sfText_setFont(*text, font);
    sfText_setString(*text, str);
}
