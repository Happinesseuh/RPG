/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** main.c
*/

void my_rpg(void);

int main(int ac, char **av, char **env)
{
    if (!env)
        return (84);
    (void)ac;
    (void)av;
    my_rpg();
    return (0);
}
