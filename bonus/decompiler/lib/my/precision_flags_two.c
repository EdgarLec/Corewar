/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** precision handling
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include "include/my_printf.h"
#include "include/my_structs.h"

int is_space_flag(mod_specs *specs)
{
    int is_space = 0;

    for (int i = 0; i < my_strlen(specs->flags_flags); i++) {
        if (specs->flags_flags[i] == ' ')
            is_space = 1;
        if (specs->flags_flags[i] == '+')
            return (0);
    }
    return (is_space);
}

int is_plus_flag(mod_specs *specs)
{
    for (int i = 0; i < my_strlen(specs->flags_flags); i++) {
        if (specs->flags_flags[i] == '+')
            return (1);
    }
    return (0);
}

int add_0x_beg_string(char *result, mod_specs *specs, char *a)
{
    if (specs->conv_specifier == 'p') {
        result[0] = '0';
        result[1] = 'x';
        result[2] = '\0';
        return (2);
    }
    if (check_if_octal_or_hex(specs, a) == 0)
        return (0);
    result[0] = '0';
    if (specs->conv_specifier == 'X')
        result[1] = 'X';
    else if (specs->conv_specifier == 'x')
        result[1] = 'x';
    if (specs->conv_specifier == 'o') {
        result[1] = '\0';
        return (1);
    }
    result[2] = '\0';
    return (2);
}

char *move_to_right(char *arg)
{
    int i = 0;

    if (arg[0] == '\0')
        return (arg);
    while (arg[i] != '\0') {
        arg[i] = arg[i + 1];
        i++;
    }
    return (arg);
}

void add_char_to_beg_string(char *result, char a)
{
    result[3] = '\0';
    result[2] = result[1];
    result[1] = result[0];
    result[0] = a;
}
