/*
** EPITECH PROJECT, 2021
** nb
** File description:
** nb
*/

#include <stdlib.h>
#include "my.h"

char *long_to_str(long long nb)
{
    int neg = nb < 0;
    int len = my_len_nbr(nb);
    char *str = my_strset(len + neg + 1);

    if (neg) {
        nb = -nb;
        str[0] = '-';
    }
    for (; len > neg; len--, nb /= 10)
        str[len - 1] = nb % 10 + '0';
    return str;
}
