/*
** EPITECH PROJECT, 2022
** arg_handling.c
** File description:
** arg handling
*/

#include "../include/decomp.h"

void arg_handling(int ac, char **av, vm_t *vm)
{
    short nb_chmp = 0;

    for (int i = 1; i < ac; i++) {
        init_champion(&vm->champions[nb_chmp], av[i], vm->id_chmp[nb_chmp], vm);
        vm->nb_champions++;
        nb_chmp++;
    }
}
