/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n && src[i]; i++)
        dest[i] = src[i];
    if (i < n)
        dest[i] = 0;
    return dest;
}
