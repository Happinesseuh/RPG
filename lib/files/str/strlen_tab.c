/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strlen_tab
*/

int my_strlen_tab(char **tab)
{
    int i;

    for (i = 0; tab[i]; i++);
    return (i);
}
