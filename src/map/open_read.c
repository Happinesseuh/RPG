/*
** EPITECH PROJECT, 2021
** <Project_name>
** File description:
** open_read.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "myrpg.h"

static char *read_map(int fd)
{
    char *buff = NULL;
    int len = 0 ;

    buff = malloc(sizeof(char) * (3249));
    if (buff == NULL)
        return (NULL);
    len = read(fd, buff, 3249);
    if (len == -1)
        return (NULL);
    buff[len - 1] = '\0';
    return (buff);
}

char **open_read(char *path)
{
    char **ret = NULL;
    char *buff = NULL;
    int fd = 0;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (NULL);
    buff = read_map(fd);
    if (close(fd) || buff == NULL)
        return (NULL);
    ret = my_str_to_word_array(buff, '\n');
    free(buff);
    if (ret == NULL)
        return (NULL);
    return (ret);
}
