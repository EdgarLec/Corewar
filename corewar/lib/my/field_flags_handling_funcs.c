/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** after_conversion_processing
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include "include/my_printf.h"
#include "include/my_structs.h"

int is_zero_flag(mod_specs *specs)
{
    int is_zero = 0;

    if (!(specs->conv_specifier == 'd' || specs->conv_specifier == 'i' ||
    specs->conv_specifier == 'o' || specs->conv_specifier == 'u' ||
    specs->conv_specifier == 'x' || specs->conv_specifier == 'X' ||
    specs->conv_specifier == 'p'))
        return (0);
    for (int i = 0; i < my_strlen(specs->flags_flags); i++) {
        if (specs->flags_flags[i] == '0')
            is_zero = 1;
    }
    if (is_zero == 1 && specs->precision == 0)
        return (1);
    return (0);
}

int is_minus_flag(mod_specs *specs)
{
    for (int i = 0; i < my_strlen(specs->flags_flags); i++) {
        if (specs->flags_flags[i] == '-')
            return (1);
    }
    return (0);
}

void add_char_field(int is_zeros, char *result, int pos)
{
    if (is_zeros == 1) {
        result[pos] = '0';
        result[pos + 1] = '\0';
    } else {
        result[pos] = ' ';
        result[pos + 1] = '\0';
    }
}

char *get_flags_in_front(char *result, char *a, mod_specs *specs, int *y)
{
    if ((is_plus_flag(specs) || is_space_flag(specs)) && (a[0] == '-' ||
    a[0] == '+' || a[0] == ' ')) {
        result[0] = a[0];
        result[1] = '\0';
        move_to_right(a);
        (*y)++;
    }
    if (is_dieze_flag(specs) && a[0] == '0' && (a[1] == 'x' || a[1] == 'X')) {
        result[0 + *y] = a[0];
        result[1 + *y] = a[1];
        result[2 + *y] = '\0';
        move_to_right(a);
        move_to_right(a);
        (*y) += 2;
    }
    return (result);
}

char *add_zeros_or_spaces_field(char *result, char *a,
mod_specs *specs, int size)
{
    int is_zeros = is_zero_flag(specs);
    int y = 0;

    if (is_zeros == 1)
        result = get_flags_in_front(result, a, specs, &y);
    if (is_minus_flag(specs) == 0) {
        for (; y < size - my_strlen(a); y++)
            add_char_field(is_zeros, result, y);
        for (int i = size - my_strlen(a); i < size; i++)
            result[i] = a[i - size + my_strlen(a)];
    } else {
        for (int i = my_strlen(a); i < size; i++)
            add_char_field(0, result, i);
    }
    return (result);
}
