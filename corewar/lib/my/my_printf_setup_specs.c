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

int update_specs(char const *str, int *i, mod_specs *specs, va_list args)
{
    int changes = 0;

    if (specs->flags == 0 && specs->field == 0 && specs->precision == 0
        && specs->len_mod == 0)
        changes += check_for_dollar(str, i, specs);
    if (specs->field == 0 && specs->precision == 0 && specs->len_mod == 0)
        changes += check_for_flags(str, i, specs);
    if (specs->field == 0 && specs->precision == 0 && specs->len_mod == 0)
        changes += check_for_field(str, i, specs, args);
    if (specs->precision == 0 && specs->len_mod == 0)
        changes += check_for_precision(str, i, specs, args);
    if (specs->len_mod == 0)
        changes += check_for_len_modifiers(str, i, specs);
    return (changes);
}

int get_mod_specs(char const *str, int i, mod_specs *specs, va_list args)
{
    int temp_i = i;
    int length;

    if (specs->len_modifiers == NULL || specs->flags_flags == NULL)
        return (-1);
    i++;
    for (; str[i] != 'd' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
    str[i] != 'x' && str[i] != 'X' && str[i] != 'c' && str[i] != 's' &&
    str[i] != 'p' && str[i] != '%' && str[i] != 'b' && str[i] != 'S';) {
        if (update_specs(str, &i, specs, args) == 0)
            return (0);
    }
    specs->conv_s++;
    specs->conv_specifier = str[i];
    length = i - temp_i;
    return (length);
}

void set_reset_struct_two(mod_specs *specs)
{
    specs->flags_flags[0] = '\0';
    specs->field = 0;
    specs->field_field = 0;
    specs->precision = 0;
    specs->precision_precision = 0;
    specs->len_mod = 0;
}

int set_reset_struct(mod_specs *specs, int fd)
{
    specs->pos = 0;
    specs->pos_pos = 0;
    specs->flags = 0;
    specs->flags_flags = malloc(sizeof(char) * 6);
    if (specs->flags_flags == NULL)
        return (1);
    set_reset_struct_two(specs);
    specs->len_modifiers = malloc(sizeof(char) * 3);
    if (specs->len_modifiers == NULL)
        return (1);
    specs->len_modifiers[0] = '\0';
    specs->conv_s = 0;
    specs->conv_specifier = 0;
    specs->mod_length = 0;
    specs->fd = fd;
    return (0);
}
