/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

int my_str_isupper(char const *str)
{
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i]; i++) {
        if (str[i] < 'A' || str[i] > 'Z')
            return 0;
    }
    return 1;
}
