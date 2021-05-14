/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);
    char *ret = malloc(sizeof(char) * (len_dest + len_src + 1));
    int i = 0;

    for (; dest[i]; i++)
        ret[i] = dest[i];
    for (i = 0; src[i]; i++)
        ret[len_dest + i] = src[i];
    ret[len_dest + i] = '\0';
    return (ret);
}
