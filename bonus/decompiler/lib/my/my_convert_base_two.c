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

int try_free_mod_specs(mod_specs *specs)
{
    if (specs->len_modifiers != NULL) {
        free(specs->len_modifiers);
        specs->len_modifiers = NULL;
    }
    if (specs->flags_flags != NULL) {
        free(specs->flags_flags);
        specs->flags_flags = NULL;
    }
    return (0);
}

int my_check_convert_dec_two(char *result, long long int *a, int *is_neg)
{
    if (result == NULL)
        return (1);
    if ((*a) == 0) {
        result[0] = '0';
        result[1] = '\0';
    } else if ((*a) < 0) {
        (*a) = (*a) - (*a) - (*a);
        (*is_neg) = 1;
    }
    return (0);
}

int my_check_convert_dec(unsigned long long int a, char *result)
{
    if (result == NULL)
        return (1);
    if (a == 0) {
        result[0] = '0';
        result[1] = '\0';
    }
    return (0);
}
