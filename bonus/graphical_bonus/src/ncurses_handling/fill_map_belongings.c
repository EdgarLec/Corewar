/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "corewar.h"
#include "op.h"

void set_champ_fill_map(const vm_t *vm, int i, int *current_champ,
int *on_champ)
{
    for (int y = 0; y < vm->nb_champions; y++) {
        if (vm->champions[y].index == i) {
            *current_champ = y;
            *on_champ = 1;
        }
    }
}

void fill_map_belongings(vm_t *vm)
{
    for (int i = 0, current_champ = 0, on_champ = 0; i < MEM_SIZE; i++) {
        set_champ_fill_map(vm, i, &current_champ, &on_champ);
        if (on_champ == 1 && i == vm->champions[current_champ].index +
        endian(vm->champions[current_champ].header->prog_size))
            on_champ = 0;
        if (on_champ == 1)
            vm->ncurses_values.map_belongings[i] = vm->
            champions[current_champ].nb_champion;
    }
}
