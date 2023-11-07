/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "corewar.h"
#include "op.h"

void init_vm_values(vm_t *vm)
{
    vm->arena = init_arena();
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->nb_live = 0;
    vm->cycle_counter = 0;
    vm->nb_cycle_dump = -1;
    for (int i = 0; i != 4; i++)
        vm->id_chmp[i] = 0;
}
