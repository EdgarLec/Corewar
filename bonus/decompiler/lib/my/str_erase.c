/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-paulin.leclercq
** File description:
** str_erase
*/

#include "my.h"

char *str_erase(char *str, int start, int size)
{
    int count = 0;
    char *new_str = my_strset(my_strlen(str) - size + 1);

    for (int i = 0; i < my_strlen(str); i++) {
        if (i < start || i >= start + size) {
            new_str[count] = str[i];
            count++;
        }
    }
    return new_str;
}
