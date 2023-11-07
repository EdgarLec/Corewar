/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** Write a function that displays, one-by-one, the characters of a string.
*/

#include "my.h"
#include <unistd.h>

int my_puterror(char const *str)
{
    return write(2, str, my_strlen(str));
}

int my_putstr(char const *str)
{
    return write(1, str, my_strlen(str));
}
