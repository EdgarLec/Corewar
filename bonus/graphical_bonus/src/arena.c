/*
** EPITECH PROJECT, 2022
** arena.c
** File description:
** arena.c
*/

#include "../include/corewar.h"

void put_champ_in_arena(char *arena, int index, char *champ)
{
    int i = 0;

    while (champ[i] != '\0') {
        arena[index] = champ[i];
        index++;
        i++;
    }
}

int check_valid_champ_size(char *champ, short nb_champ)
{
    int len = strlen(champ);

    if (len > (MEM_SIZE / nb_champ))
        return 0;
    return 1;
}

void add_champ_in_arena(char *arena, char **champ, short nb_champ)
{
    int index;

    for (int i = 0; i < nb_champ; i++) {
        index = (MEM_SIZE / nb_champ) * i;
        if (check_valid_champ_size(champ[i], nb_champ) == 0) {
            write(2, "Error: Champ too big\n", 22);
            supexit(recup(), 84);
        }
        put_champ_in_arena(arena, index, champ[i]);
    }
}

char *init_arena(void)
{
    char *arena = supaloc(MEM_SIZE);

    for (int i = 0; i < MEM_SIZE; i++)
        arena[i] = '\0';
    return arena;
}
