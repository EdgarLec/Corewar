/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-paulin.leclercq
** File description:
** is_str_empty
*/

#include "my.h"

int is_empty(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
            return 0;
    }
    return 1;
}
