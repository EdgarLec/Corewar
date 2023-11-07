/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** my_strdup.c
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *my_strndup(char const *src, int nb)
{
    int i = 0;
    char *dest = my_strset(nb + 1);

    while (i < nb) {
        dest[i] = src[i];
        i++;
    }
    return dest;
}

char *my_strdup(char const *src)
{
    int i = 0;
    int size = my_strlen(src);
    char *dest = my_strset(size + 1);

    while (i < size) {
        dest[i] = src[i];
        i++;
    }
    return dest;
}
