/*
** EPITECH PROJECT, 2021
** my_str_replace.c
** File description:
** my_str_replace.
*/

#include "my.h"
#include <stdlib.h>

char *my_str_replace(char *str, char *str_to_put, int start, int nb_to_replace)
{
    int len = my_strlen(str) - nb_to_replace + my_strlen(str_to_put) + 2;
    char *new_string = my_strset(len);
    int len_to_put = my_strlen(str_to_put);

    for (int i = 0; i < start; i++)
        new_string[i] = str[i];
    for (int i = start; i < len_to_put + start; i++)
        new_string[i] = str_to_put[i - start];
    for (int i = start + len_to_put; str[i + nb_to_replace - len_to_put]; i++)
        new_string[i] = str[i + nb_to_replace - len_to_put];
    return new_string;
}
