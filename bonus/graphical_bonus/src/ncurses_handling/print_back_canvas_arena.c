/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "corewar.h"
#include "op.h"

int print_back_canvas_arena(WINDOW *window, vm_t *vm)
{
    draw_edges_init(window, vm);
    for (int i = 0; i < MEM_SIZE; i++)
        vm->ncurses_values.arena_last_iteration[i] = -1;
    print_arena(window, vm);
    for (int i = 0; i < vm->ncurses_values.champ_nb_start; i++)
        print_champion_stats(window, vm, i);
    print_vm_stats(window, vm);
    wrefresh(window);
    return (0);
}
