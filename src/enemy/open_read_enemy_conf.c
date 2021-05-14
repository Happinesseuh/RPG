/*
** EPITECH PROJECT, 2021
** <Project_name>
** File description:
** open_read_enemy_conf.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int my_getnbr(char const *str)
{
    int nb = 0;

    for (int i = 0 ; str[i] ; i++)
        nb = nb * 10 + (str[i] - '0');
    return (nb);
}

static char *read_enemy_conf(int fd)
{
    char *buff = NULL;
    int len = 0 ;

    buff = malloc(sizeof(char) * (2));
    if (buff == NULL)
        return (NULL);
    len = read(fd, buff, 2);
    if (len == -1)
        return (NULL);
    buff[len - 1] = '\0';
    return (buff);
}

int open_read_enemy_conf(char *path)
{
    char *buff = NULL;
    int ret = 0;
    int fd = 0;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (-1);
    buff = read_enemy_conf(fd);
    if (close(fd) || buff == NULL)
        return (-1);
    ret = my_getnbr(buff);
    free(buff);
    return (ret);
}
