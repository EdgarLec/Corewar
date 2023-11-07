/*
** EPITECH PROJECT, 2021
** str_to_long.c
** File description:
** str_to_long
*/

long long int str_to_long(char const *str)
{
    long long int nb = 0;
    int is_neg = str[0] == '-';

    for (int i = is_neg; str[i] >= '0' && str[i] <= '9'; i++) {
        nb *= 10;
        nb += str[i] - '0';
    }
    return is_neg ? -nb : nb;
}
