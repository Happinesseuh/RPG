/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; src[i] && i < n; i++)
        dest[i] = src[i];
    if (i == n)
        dest[i] = '\0';
    return (dest);
}
