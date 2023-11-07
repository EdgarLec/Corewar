/*
** EPITECH PROJECT, 2022
** my_find_str.c
** File description:
** my_find_str
*/

#include "my.h"

int find_str(char *to_find, char *src)
{
    int i = 0;
    int nb = 0;
    int len = my_strlen(to_find);

    for (; src[i] && len != nb; i++)
        nb += to_find[nb] == src[i] ? 1 : -nb;
    if (len == nb)
        return i - len;
    return -1;
}
