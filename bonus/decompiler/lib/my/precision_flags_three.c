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

int is_dieze_flag(mod_specs *specs)
{
    for (int i = 0; i < my_strlen(specs->flags_flags); i++) {
        if (specs->flags_flags[i] == '#')
            return (1);
    }
    return (0);
}
