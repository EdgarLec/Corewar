/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "corewar.h"
#include "op.h"

int main(int ac, char **av)
{
    vm_t *vm = get_vm(true);

    vm->arena = init_arena();
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->nb_live = 0;
    vm->cycle_counter = 0;
    vm->nb_cycle_dump = -1;
    vm->last_alive = -1;
    stock_champions(vm, av, ac);
    fix_chmp_order();
    vm->buffer = supaloc(sizeof(buffer_t) * vm->nb_champions);
    for (int i = 0; i < vm->nb_champions;
    vm->buffer[i].action = 0, vm->buffer[i].to_do = 0, i++);
    corewar_loop(vm, vm->nb_champions);
    if (vm->last_alive != -1)
        my_dprintf(1, "Le joueur %i (%s) a gagné.\n",
    vm->champions[vm->last_alive].nb_champion, vm->champions[vm->last_alive].
    header->prog_name);
    supexit(recup(), 0);
}
