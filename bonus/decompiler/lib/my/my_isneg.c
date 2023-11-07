/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** Write a function that displays if it's positive or null.
*/

#include "my.h"

int my_isneg(int n)
{
    my_putchar(n < 0 ? 'N' : 'P');
    return 0;
}
