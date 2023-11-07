/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf length_handling_funcs_part_one
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include "include/my_printf.h"
#include "include/my_structs.h"

long long int convert_to_size_t(va_list args, mod_specs *specs)
{
    long int a;
    unsigned long int b;

    if (specs->conv_specifier == 'u') {
        b = va_arg(args, long long int);
        return (b);
    } else {
        a = va_arg(args, long long int);
        return (a);
    }
}

long long int convert_to_ptrdiff_t(va_list args, mod_specs *specs)
{
    long long int a;

    a = va_arg(args, long long int);
    return (a);
}

long long int check_double_length_mod(va_list args, mod_specs *specs)
{
    long long int result = 0;

    if (specs->len_modifiers[0] == 'h' && specs->len_modifiers[1] == 'h' ) {
        result = convert_to_char_length(args, specs);
        return (result);
    } else if ((specs->len_modifiers[0] == 'l' &&
    specs->len_modifiers[1] == 'l') ||
    specs->len_modifiers[0] == 'q' ||
    specs->len_modifiers[0] == 'j') {
        result = va_arg(args, long long int);
        return (result);
    }
    return (0);
}

long long int get_right_int_length(va_list args, mod_specs *specs)
{
    long long int result = 0;
    int length_mod_nb = 0;
    char *length_mod_list = "hlzZt";
    long long int(*fun_ptr_arr[])(va_list args, mod_specs *specs) =
    {convert_to_short, convert_to_long, convert_to_size_t,
    convert_to_size_t, convert_to_ptrdiff_t};

    result = check_double_length_mod(args, specs);
    if (result != 0 || specs->len_modifiers[1] == 'l'
        || specs->len_modifiers[1] == 'h')
        return (result);
    for (; specs->len_modifiers[0] != length_mod_list[length_mod_nb];
    length_mod_nb++);
    result = (*fun_ptr_arr[length_mod_nb])(args, specs);
    return (result);
}

unsigned long long int my_convert_unsigned_int(va_list args, mod_specs specs)
{
    unsigned long long int nbr;
    unsigned int nbr2;

    specs.conv_specifier = 'u';
    if (specs.len_mod > 0)
        nbr = get_right_int_length(args, &specs);
    else {
        nbr2 = va_arg(args, unsigned long long int);
        nbr = nbr2;
    }
    return (nbr);
}
