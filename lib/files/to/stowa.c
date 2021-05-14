/*
** EPITECH PROJECT, 2020
** to_word_array.c
** File description:
** to_word_array
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/macro.h"

int count_words(char *str)
{
    int word = 0;
    int nb = 0;

    for (int i = 0; str[i]; i++) {
        if (word == 0 && !CHAR_IS_SEP(str[i])) {
            word = 1;
            nb++;
        }
        if (word == 1 && CHAR_IS_SEP(str[i]))
            word = 0;
    }
    return (nb);
}

void fill_word(char *res, char *str, int beg, int end)
{
    int i;

    for (i = 0; beg <= end; i++, beg++)
        res[i] = str[beg];
    res[i] = '\0';
}

void for_word(char *str, int *i, int *beg, int *end)
{
    for (; str[*i] && CHAR_IS_SEP(str[*i]); *i += 1);
    *beg = *i;
    for (; str[*i] && !CHAR_IS_SEP(str[*i]); *i += 1);
    *end = *i - 1;
}

void fill_tab(char **tab, char *str, int nb)
{
    int beg = 0;
    int end = 0;
    int cur = 0;

    for (int i = 0; cur < nb; i++, cur++) {
        for_word(str, &i, &beg, &end);
        tab[cur] = (char *) malloc(sizeof(char) * (i - beg + 1));
        fill_word(tab[cur], str, beg, end);
    }
    tab[nb] = NULL;
}

char **my_str_to_word_array(char *str)
{
    int nb = count_words(str);
    char **tab = malloc(sizeof(char *) * (nb + 1));

    fill_tab(tab, str, nb);
    return (tab);
}
