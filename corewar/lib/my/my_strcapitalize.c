/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

static char *lowcase(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    return str;
}

char *my_strcapitalize(char *str)
{
    int charac = 0;

    lowcase(str);
    if (str[0] == '\0')
        return str;
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i - 1] < '0' || str[i - 1] > '9' && str[i - 1] < 'A')
            charac = 1;
        if (str[i - 1] > 'Z' && str[i - 1] < 'a' || str[i - 1] > 'z')
            charac = 1;
        if (str[i] >= 'a' && str[i] <= 'z' && charac == 1)
            str[i] -= 32;
        charac = 0;
    }
    return str;
}
