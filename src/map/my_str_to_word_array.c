/*
** EPITECH PROJECT, 2021
** <Project_name>
** File description:
** my_str_to_word_array.c
*/

#include <stdbool.h>
#include <stdlib.h>

static bool c_delim(char c, char delim)
{
    if (c != delim)
        return (true);
    return (false);
}

static char **array_alloc(char const *str, char delim)
{
    char **ret = NULL;
    int size = 1;

    for (int i = 0 ; str[i] ;) {
        for (; !c_delim(str[i], delim) && str[i] ; i++);
        if (str[i])
            size += 1;
        for (; c_delim(str[i], delim) && str[i] ; i++);
    }
    ret = malloc(size * sizeof(char *));
    if (ret == NULL)
        return (NULL);
    ret[size - 1] = NULL;
    return (ret);
}

static char *string_ret(char const *str, char delim)
{
    char *ret = NULL;
    int size = 0;

    for (; c_delim(str[size], delim) && str[size] ; size++);
    ret = malloc((size + 2) * sizeof(char));
    if (ret == NULL)
        return (NULL);
    ret[size] = '\0';
    for (size = 0 ; c_delim(str[size], delim) && str[size] ; size++)
        ret[size] = str[size];
    return (ret);
}

char **my_str_to_word_array(char const *str, char delim)
{
    char **ret = NULL;
    int ind = 0;

    ret = array_alloc(str, delim);
    if (ret == NULL)
        return (NULL);
    for (int i = 0 ; str[i] ; ind++) {
        for (; !c_delim(str[i], delim) && str[i] ; i++);
        ret[ind] = string_ret(str + i, delim);
        for (; c_delim(str[i], delim) && str[i] ; i++);
        for (; !c_delim(str[i], delim) && str[i] ; i++);
    }
    return (ret);
}
