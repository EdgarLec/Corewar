/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** lists
*/

#include "my.h"

void append_node(list_t **begin, void *data)
{
    list_t *new = malloc(sizeof(list_t));

    new->data = data;
    if (!(*begin)) {
        *begin = new;
        new->next = new;
        new->prev = new;
        return;
    }
    new->next = (*begin);
    new->prev = (*begin)->prev;
    (*begin)->prev->next = new;
    (*begin)->prev = new;
}

void remove_node(list_t **begin, int index, void (*free_func)(void *))
{
    list_t *start = *begin;
    list_t *next;
    list_t *prev;

    if (!start)
        return;
    for (int i = 0; i < index; i++)
        start = start->next;
    if (free_func)
        free_func(start->data);
    if (start == start->next)
        *begin = NULL;
    else {
        prev = start->prev;
        next = start->next;
        prev->next = next;
        next->prev = prev;
        *begin = next;
    }
    free(start);
}
