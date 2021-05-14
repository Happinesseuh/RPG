/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** my_strdup
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    dest = my_strcpy(dest, src);
    return (dest);
}
