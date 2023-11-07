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
#include "include/my_structs.h"

int my_print_int(va_list args, mod_specs *specs)
{
    long long int nbr;
    char *result;

    if (specs->len_mod > 0)
        nbr = get_right_int_length(args, specs);
    else
        nbr = va_arg(args, int);
    result = my_convert_to_dec(nbr);
    if (result == NULL)
        return (1);
    process_after_conversion(result, specs);
    return (0);
}

int my_print_octal(va_list args, mod_specs *specs)
{
    unsigned long long int nbr;
    char *oct;

    nbr = my_convert_unsigned_int(args, *specs);
    oct = my_convert_to_oct(nbr);
    process_after_conversion(oct, specs);
    return (0);
}

int my_print_dec(va_list args, mod_specs *specs)
{
    long long int nbr;
    unsigned int u_nbr;
    char *result;

    if (specs->len_mod > 0) {
        nbr = get_right_int_length(args, specs);
        result = my_convert_to_un_dec(nbr);
        if (result == NULL)
            return (1);
        process_after_conversion(result, specs);
    } else {
        u_nbr = va_arg(args, int);
        result = my_convert_to_un_dec(u_nbr);
        if (result == NULL)
            return (1);
        process_after_conversion(result, specs);
    }
    return (0);
}

int my_print_hex(va_list args, mod_specs *specs)
{
    unsigned long long int nbr;
    char *hex;

    nbr = my_convert_unsigned_int(args, *specs);
    hex = my_convert_to_hex(nbr);
    if (hex == NULL)
        return (1);
    process_after_conversion(hex, specs);
    return (0);
}

int my_print_bin(va_list args, mod_specs *specs)
{
    unsigned long long int nbr;
    char *result = malloc(sizeof(char) * 65);
    int result_counter = 0;

    if (result == NULL)
        return (1);
    nbr = my_convert_unsigned_int(args, *specs);
    if (my_check_convert_dec(nbr, result) == 1)
        return (1);
    while (nbr > 0) {
        result[result_counter] = nbr % 2 + '0';
        result[result_counter + 1] = '\0';
        nbr = nbr / 2;
        result_counter++;
    }
    my_revstr(result);
    process_after_conversion(result, specs);
    return (0);
}
