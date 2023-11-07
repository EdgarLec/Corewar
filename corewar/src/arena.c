/*
** EPITECH PROJECT, 2022
** arena.c
** File description:
** arena.c
*/

#include "../include/corewar.h"

char *init_arena(void)
{
    char *arena = supaloc(MEM_SIZE);

    for (int i = 0; i < MEM_SIZE; i++)
        arena[i] = '\0';
    return arena;
}
