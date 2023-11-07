/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

static int compare_str(char *str, char const *to_find)
{
    int j = 0;
    int find_length = 0;

    while (to_find[find_length] != '\0')
        find_length++;
    for (j = 0; j < find_length; j++) {
        if (str[j] != to_find[j])
            return 0;
    }
    return 1;
}

int my_strstr(char *str, char const *to_find)
{
    if (to_find[0] == '\0')
        return 0;
    for (int i = 0; str[i]; i++) {
        if (compare_str(&str[i], to_find) == 1)
            return i;
    }
    return -1;
}
