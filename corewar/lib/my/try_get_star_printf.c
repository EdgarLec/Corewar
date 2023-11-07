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

int try_get_star_field(const char *str, int *i,
mod_specs *specs, va_list args)
{
    if (str[*i] != '*')
        return (0);
    (*i)++;
    specs->field = 1;
    specs->field_field = va_arg(args, int);
    return (1);
}

int try_get_star_prec(const char *str, int *i,
mod_specs *specs, va_list args)
{
    if (str[*i] != '*')
        return (0);
    (*i)++;
    specs->precision = 1;
    specs->precision_precision = va_arg(args, int);
    return (1);
}
