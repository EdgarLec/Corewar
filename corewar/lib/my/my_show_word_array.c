/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

#include "my.h"

int len_array(char * const *tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return i;
}

char * const *my_show_word_array(char * const *tab)
{
    int len = len_array(tab);

    for (int i = 0; i < len; i++) {
        my_putstr(tab[i]);
        write(1, "\n", 1);
    }
    return tab;
}
