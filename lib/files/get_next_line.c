/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** get_next_line
*/

#include <stdlib.h>
#include <unistd.h>

void my_puterror(char const *str);

char *get_next_line(const int fd)
{
    char c;
    char *res = malloc(sizeof(char) * 233);
    int rd = read(fd, &c, 1);
    int i;

    if (rd == 0 || rd == -1)
        return (NULL);
    res[0] = c;
    for (i = 1; c != '\n' && i < 232; i++) {
        read(fd, &c, 1);
        res[i] = c;
    }
    res[i - 1] = '\0';
    return (res);
}
