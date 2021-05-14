/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** str_isprintable
*/

int my_str_isprintable(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 32 || str[i] > 126)
            return (0);
    return (1);
}
