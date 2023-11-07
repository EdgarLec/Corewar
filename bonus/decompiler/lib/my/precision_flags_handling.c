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

int add_space_or_sign_for_p(char *result, char *a, mod_specs *specs)
{
    if (a[0] == '-') {
        add_char_to_beg_string(result, '-');
        move_to_right(a);
        return (1);
    }
    if (is_plus_flag(specs) == 0 && is_space_flag(specs) == 0)
        return (0);
    if (is_space_flag(specs) == 1)
        add_char_to_beg_string(result, ' ');
    else
        add_char_to_beg_string(result, '+');
    return (1);
}

int add_space_or_sign_beg_string(char *result, char *a, mod_specs *specs)
{
    if (a[0] == '-') {
        result[0] = '-';
        result[1] = '\0';
        move_to_right(a);
        return (1);
    }
    if ((is_plus_flag(specs) == 0 && is_space_flag(specs) == 0)
    || (specs->conv_specifier != 'd' && specs->conv_specifier != 'i'))
        return (0);
    if (is_space_flag(specs) == 1)
        result[0] = ' ';
    else
        result[0] = '+';
    result[1] = '\0';
    return (1);
}

int add_precision_zeros(char *result, char *a, mod_specs *specs, int pos)
{
    if (specs->precision == 0 || specs->precision_precision <= my_strlen(a))
        return (0);
    for (int i = 0; i < specs->precision_precision - my_strlen(a); i++)
        result[i + pos] = '0';
    result[pos + specs->precision_precision - my_strlen(a)] = '\0';
    return (specs->precision_precision - my_strlen(a));
}

void add_precision_flags_nbr(char *result, char *a, mod_specs *specs)
{
    int pos = 0;

    pos += add_0x_beg_string(result, specs, a);
    if (specs->conv_specifier == 'p')
        pos += add_space_or_sign_for_p(result, a, specs);
    else
        pos += add_space_or_sign_beg_string(result, a, specs);
    pos += add_precision_zeros(result, a, specs, pos);
    for (int i = 0; i < my_strlen(a) + 1; i++)
        result[i + pos] = a[i];
}

void add_precision_flag_str(char *result, char *a, mod_specs *specs)
{
    int chars_to_print = my_strlen(a);

    if (chars_to_print > specs->precision_precision && specs->precision == 1)
        chars_to_print = specs->precision_precision;
    for (int i = 0; i < chars_to_print; i++)
        result[i] = a[i];
    result[chars_to_print] = '\0';
}
