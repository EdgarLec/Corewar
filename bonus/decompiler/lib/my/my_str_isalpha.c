/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

int my_str_isalpha(char const *str)
{
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i]; i++) {
        if (str[i] < 'A')
            return 0;
        if (str[i] > 'Z' && str[i] < 'a' || str[i] > 'z')
            return 0;
    }
    return 1;
}
