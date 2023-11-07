/*
** EPITECH PROJECT, 2021
** main_infin_add
** File description:
** performs infinite addition
*/

#include "my.h"

static int check_errors(char const *string, int *counter)
{
    while (string[*counter] == '-' || string[*counter] == '+') {
        (*counter)++;
    }
    if (string[*counter] < '0' || string[*counter] > '9')
        return (84);
    for (int y = *counter; y < *counter + 11; y++) {
        if (string[y] < '0' || string[y] > '9')
            return (0);
    }
    return (84);
}

static int check_pos(char const *str)
{
    int i = 0;
    int pos = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-' && pos == 1) {
            pos = !(pos);
        } else {
            pos = 1;
        }
        i++;
    }
    return (pos);
}

static int check_if_valid(long long int number, int pos)
{
    if (pos == 0) {
        if (number > 2147483648)
            return (0);
    } else {
        if (number > 2147483647)
            return (0);
    }
    return (1);
}

static int add_numbers(char const *str, int index, int pos)
{
    long long int number = 0;
    int end_number;

    while (str[index] >= '0' && str[index] <= '9') {
        number *= 10;
        number += str[index] - '0';
        index++;
    }
    if (check_if_valid(number, pos) == 1) {
        if (pos == 0) {
            end_number = -number;
        } else {
            end_number = number;
        }
        return (end_number);
    }
    return (0);
}

int my_getnbr(char const *str)
{
    int pos;
    int first_nb = 0;
    int final_number;

    if (check_errors(str, &first_nb) == 84)
        return (0);
    pos = check_pos(str);
    final_number = add_numbers(str, first_nb, pos);
    return (final_number);
}
