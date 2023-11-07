/*
** EPITECH PROJECT, 2021
** count_valid_queens_placements.c
** File description:
** description.
*/

#include <stdlib.h>
#include "my.h"

char **word_array_alloc(char **tmp)
{
    int len = len_array(tmp);
    char **str = my_dbstrset(len + 1);

    for (int i = 0; i < len; i++) {
        str[i] = my_strdup(tmp[i]);
        free(tmp[i]);
    }
    free(tmp);
    return str;
}

char **my_str_to_word_array(char const *str, char *delimiters)
{
    int count = 0;
    int start = -1;
    int len = my_strlen(str);
    char **tmp = my_dbstrset(len + 1);

    for (int i = 0; i <= len; i++) {
        if (!is_in_str(str[i], delimiters) && str[i] != 0 && start == -1)
            start = i;
        if ((is_in_str(str[i], delimiters) || str[i] == 0) && start >= 0) {
            tmp[count] = my_strndup(str + start, i - start);
            start = -1;
            count++;
        }
    }
    return word_array_alloc(tmp);
}
