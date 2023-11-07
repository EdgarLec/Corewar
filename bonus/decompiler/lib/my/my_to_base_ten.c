/*
** EPITECH PROJECT, 2021
** base_trans.c
** File description:
** base_trans
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *exponential(char *t, int y)
{
    char *tmp;
    char *result = my_strdup("1");

    if (y != 0) {
        for (int i = 0; i < y; i++) {
            tmp = infinmult(result, t);
            free(result);
            result = tmp;
        }
    } else {
        result[0] = '1';
        result[1] = '\0';
    }
    return result;
}

int position(char *str, char cha)
{
    int i = 0;

    for (i; str[i] != cha; i++);
    return i;
}

char *cbase(char *str, char *base, int i, int j)
{
    char *tmp;
    char *result = my_strdup("0");

    str = my_revstr(str);
    for (int y = 0; y < j; y++) {
        tmp = infinmult(long_to_str(position(base, str[y])),
        exponential(long_to_str(i), y));
        result = ope(result, tmp);
        free(tmp);
    }
    return result;
}

char *change_base_ten(char *str, char *base)
{
    int i = 0;
    int j = 0;

    for (i; base[i]; i++);
    for (j; str[j]; j++);
    return (cbase(str, base, i, j));
}
