/*
** EPITECH PROJECT, 2022
** my_is_snake_case.c
** File description:
** my_is_snake_case
*/

#include "my.h"
#include <stdlib.h>

int my_is_snake_case(char *str)
{
    char *str_dup = my_strdup(str);

    my_strlowcase(str_dup);
    for (int i = 0 ; str[i]; i++) {
        if ((str_dup[i] < 'a' || str_dup[i] > 'z') &&
        (str_dup[i] < '0' || str_dup[i] > '9') && str_dup[i] != '_') {
            free(str_dup);
            return 0;
        }
    }
    free(str_dup);
    return 1;
}
