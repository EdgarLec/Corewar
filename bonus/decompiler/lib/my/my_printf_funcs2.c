/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf funcs
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include "include/my_printf.h"

int my_print_hex_cap(va_list args, mod_specs *specs)
{
    unsigned long long int nbr;
    char *hex;

    nbr = my_convert_unsigned_int(args, *specs);
    hex = my_convert_to_hex_cap(nbr);
    if (hex == NULL)
        return (1);
    process_after_conversion(hex, specs);
    return (0);
}

int my_print_char(va_list args, mod_specs *specs)
{
    char ch;
    char *result = malloc(sizeof(char) * 2);

    if (result == NULL)
        return (1);
    ch = va_arg(args, int);
    if (specs->len_modifiers[0] == 'l' || specs->len_modifiers[0] == 'q' ||
    specs->len_modifiers[0] == 'j' || specs->len_modifiers[0] == 'z' ||
    specs->len_modifiers[0] == 'Z' || specs->len_modifiers[0] == 't')
        return (0);
    result[0] = ch;
    result[1] = '\0';
    process_after_conversion(result, specs);
    return (0);
}

int my_print_str(va_list args, mod_specs *specs)
{
    char *string;

    string = va_arg(args, char *);
    if (specs->len_modifiers[0] == 'l' || specs->len_modifiers[0] == 'q' ||
    specs->len_modifiers[0] == 'j' || specs->len_modifiers[0] == 'z' ||
    specs->len_modifiers[0] == 'Z' || specs->len_modifiers[0] == 't')
        return (0);
    process_after_conversion(string, specs);
    return (0);
}

int my_print_void(va_list args, mod_specs *specs)
{
    unsigned long long int nbr;
    char *hex;

    nbr = va_arg(args, unsigned long long int);
    hex = my_convert_to_hex(nbr);
    if (hex == NULL)
        return (1);
    process_after_conversion(hex, specs);
    return (0);
}

int my_print_mod(va_list args, mod_specs *specs)
{
    my_putchar('%');
    return (0);
}
