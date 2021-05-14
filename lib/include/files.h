/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** files.h
*/

#ifndef FILES_H
#define FILES_H

#include <stddef.h>
#include <stdarg.h>

/*        FUNCTIONS         */
int my_printf(const char *format, ...);
/* int */
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_atoi(char const *str);
int my_intlen(int nb);

/* is */
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isnum(char const *str);
int my_str_isnumop(char *str);
int my_str_isprintable(char *str);
int my_is_prime(int nb);

/* put */
void my_putchar(char c);
void my_putstr(char const *str);
void my_puterror(char const *str);
void my_put_nbr(int nb);
void my_put_nbr_bin(int nb);
void my_put_nbr_un(unsigned int nb);
void my_put_nbr_unhex(unsigned int nb, int maj, int neg);

/* str */
int my_strlen(char const *str);
int my_strlen_tab(char **tab);
char *my_revstr(char *str);

char *my_strdup(char const *src);

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);

int my_strcmp(char *s1, char *s2);
int my_strncmp(char const *s1, char const *s2, int n);

char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);

char *my_strcapitalize(char *str);
char *my_strlowcase(char *str);
char *my_strupcase(char *str);
char *my_strstr(char *str, char const *to_find);

// char **my_str_to_word_array(char *str);

/* to */
char *my_itoa(int nb);
unsigned int my_itooct(unsigned int nb);

char *get_next_line(const int fd);

#endif /* FILES_H */