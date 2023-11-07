/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf length_handling_funcs_part_two
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include "include/my_printf.h"
#include "include/my_structs.h"

long long int convert_to_char_length(va_list args, mod_specs *specs)
{
    char a;
    unsigned char b;

    if (specs->conv_specifier == 'u') {
        b = va_arg(args, long long int);
        return (b);
    } else {
        a = va_arg(args, long long int);
        return (a);
    }
}

long long int convert_to_short(va_list args, mod_specs *specs)
{
    short a;
    unsigned short b;

    if (specs->conv_specifier == 'u') {
        b = va_arg(args, long long int);
        return (b);
    } else {
        a = va_arg(args, long long int);
        return (a);
    }
}

long long int convert_to_long(va_list args, mod_specs *specs)
{
    long a;
    unsigned long b;

    if (specs->conv_specifier == 'u') {
        b = va_arg(args, long long int);
        return (b);
    } else {
        a = va_arg(args, long long int);
        return (a);
    }
}
