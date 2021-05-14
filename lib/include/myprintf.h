/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** m_printf.h
*/

#ifndef PRINTF_H
#define PRINTF_H

#include "files.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdarg.h>

void pf_str(va_list list);
void pf_c(va_list list);
void pf_di(va_list list);
void pf_prc(va_list list);

#endif /* PRINTF_H */