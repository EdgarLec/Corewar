/*
** EPITECH PROJECT, 2022
** B-CPE-210-LIL-2-1-stumper2-edgar.lecuyer
** File description:
** main
*/

#include "my.h"

void free_data(loc_t **tmp)
{
    free((*tmp)->data);
    free(*tmp);
}

void one_free(void *data, loc_t **list)
{
    loc_t *tmp = *list;
    loc_t *tmp2 = *list;

    if (*list == 0)
        return;
    if (tmp->data == data) {
        tmp2 = tmp->next;
        free_data(&tmp);
        *list = tmp2;
        return;
    }
    for (; tmp->next != 0; tmp = tmp->next) {
        if (tmp->next->data == data) {
            tmp2 = tmp->next->next;
            free_data(&(tmp->next));
            tmp->next = tmp2;
            return;
        }
    }
}

void frexit(void *data, int i)
{
    free(data);
    exit(i);
}

char *realoc_sp(char *str, size_t size)
{
    char *new = supaloc(sizeof(char) * my_strlen(str) + size + 1);

    for (size_t i = 0; i < my_strlen(str) + size; new[i] = '\0', i++);
    my_strcpy(new, str);
    one_free(str, recup());
    return new;
}
