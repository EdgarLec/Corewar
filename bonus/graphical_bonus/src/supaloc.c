/*
** EPITECH PROJECT, 2022
** B-CPE-210-LIL-2-1-stumper2-edgar.lecuyer
** File description:
** main
*/

#include "../include/supaloc.h"

void append_node(loc_t **list, void *data)
{
    loc_t *tmp;

    if (*list == 0) {
        (*list) = malloc(sizeof(loc_t));
        if ((*list) == 0)
            frexit(data, 84);
        (*list)->next = 0;
        (*list)->data = data;
    } else {
        tmp = (*list)->next;
        (*list)->next = malloc(sizeof(loc_t));
        if ((*list)->next == 0) {
            (*list)->next = tmp;
            free(data);
            supexit(recup(), 84);
        }
        (*list)->next->next = tmp;
        (*list)->next->data = data;
    }
}

loc_t **recup(void)
{
    static loc_t *new = 0;

    return &new;
}

void supfree(loc_t **list)
{
    loc_t *tmp = 0;

    if (*list == 0)
        return;
    while (*list != 0) {
        tmp = (*list)->next;
        free((*list)->data);
        free(*list);
        *list = tmp;
    }
}

void supexit(loc_t **loc_list, int i)
{
    supfree(loc_list);
    exit(i);
}

void *supaloc(size_t size)
{
    void *ret = malloc(size);
    loc_t **loc_list = recup();

    if (ret == NULL)
        supexit(loc_list, 84);
    append_node(loc_list, ret);
    for (size_t i = 0; i < size; i++)
        ((char *)ret)[i] = 0;
    return ret;
}
