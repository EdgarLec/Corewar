/*
** EPITECH PROJECT, 2022
** my_nstrcat.c
** File description:
** my_nstrcat
*/

#include "my.h"

int my_nstrlen(int nb, ...)
{
    int len;
    va_list list_arg;

    va_start(list_arg, nb);
    for (int i = 0; i < nb; i++)
        len += my_strlen(va_arg(list_arg, char *));
    va_end(list_arg);
    return len;
}

char *my_nstrcat(int nb, int len, ...)
{
    va_list list_arg;
    char *str = my_strset(len + 1);

    va_start(list_arg, len);
    for (int i = 0; i < nb; i++)
        my_strcat(str, va_arg(list_arg, char *));
    va_end(list_arg);
    return str;
}
