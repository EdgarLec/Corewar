/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my_printf.h"
#include "include/my_structs.h"

int check_for_dollar(const char *str, int *i, mod_specs *specs)
{
    int nb;
    int i_backup = *i;

    if (specs->pos == 1)
        return (0);
    if (str[*i] >= '0' && str[*i] <= '9')
        nb = my_getnbr(str + *i);
    while (str[*i] >= '0' && str[*i] <= '9') {
        (*i)++;
    }
    if (str[*i] == '$') {
        specs->pos++;
        specs->pos_pos = nb;
        (*i)++;
    } else {
        *i = i_backup;
        return (0);
    }
    return (1);
}

int check_for_flags(char const *str, int *i, mod_specs *specs)
{
    int length_flags_flags = my_strlen(specs->flags_flags);

    if (str[*i] == '#' || str[*i] == '0' || str[*i] == '-' ||
        str[*i] == ' ' || str[*i] == '+') {
        specs->flags++;
        specs->flags_flags[length_flags_flags] = str[*i];
        specs->flags_flags[length_flags_flags + 1] = '\0';
        (*i)++;
    } else {
        return (0);
    }
    return (1);
}

int check_for_field(const char *str, int *i, mod_specs *specs, va_list args)
{
    int y = *i;

    if (str[y] == '0') {
        check_for_flags(str, i, specs);
        return (1);
    }
    if (try_get_star_field(str, i, specs, args) == 1)
        return (1);
    if (str[y] > '0' && str[y] <= '9')
        for (; str[y] >= '0' && str[y] <= '9'; y++);
    if (str[*i] > '0' && str[*i] <= '9') {
        specs->field++;
        specs->field_field = my_getnbr(str + *i);
        *i = y;
    } else {
        return (0);
    }
    return (1);
}

int check_for_precision(const char *str, int *i, mod_specs *specs,
va_list args)
{
    int y;

    if (str[*i] == '.') {
        specs->precision++;
        (*i)++;
    }
    if (try_get_star_prec(str, i, specs, args) == 1)
        return (1);
    y = *i;
    if (str[y] >= '0' && str[y] <= '9')
        for (; str[y] >= '0' && str[y] <= '9'; y++);
    if (str[*i] >= '0' && str[*i] <= '9') {
        specs->precision_precision = my_getnbr(str + *i);
        *i = y;
    } else {
        return (0);
    }
    return (1);
}

int check_for_len_modifiers(const char *str, int *i, mod_specs *specs)
{
    if (!(str[*i] == 'h' || str[*i] == 'l' || str[*i] == 'j' ||
    str[*i] == 'z' || str[*i] == 'Z' || str[*i] == 't'))
        return (0);
    specs->len_mod++;
    specs->len_modifiers[0] = str[*i];
    specs->len_modifiers[1] = '\0';
    (*i)++;
    if (str[*i] == 'h' || str[*i] == 'l') {
        specs->len_mod++;
        specs->len_modifiers[1] = str[*i];
        specs->len_modifiers[2] = '\0';
        (*i)++;
    }
    return (1);
}
