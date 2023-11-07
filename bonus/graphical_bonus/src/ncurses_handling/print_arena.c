/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "corewar.h"
#include "op.h"

int try_print_number(vm_t *vm, int offset, int y, int i)
{
    if (vm->ncurses_values.arena_last_iteration[offset] != -1 && vm->
    ncurses_values.arena_last_iteration[offset] == vm->arena[offset])
        return (1);
    mvwprintw(vm->ncurses_values.window, y + 2, 3 * i + 2, "%02hhX ",
    vm->arena[offset]);
    vm->ncurses_values.arena_last_iteration[offset] = vm->arena[offset];
    return (0);
}

int print_number_pc(WINDOW *window, vm_t *vm, int i, int nb_champ)
{
    int color = get_champion_color_nb_pc(vm, nb_champ);

    attron(COLOR_PAIR(color));
    mvwprintw(window, (vm->champions[i].pc % MEM_SIZE) / 96 + 2, 3 * ((vm->
    champions[i].pc % MEM_SIZE) % 96) + 2, "%02hhX", vm->arena[vm->
    champions[i].pc % MEM_SIZE]);
    attroff(COLOR_PAIR(color));
    vm->ncurses_values.arena_last_pc[vm->champions[i].pc % MEM_SIZE] =
    get_champion_color_nb(vm, vm->ncurses_values.map_belongings[vm->
    champions[i].pc % MEM_SIZE]);
    return (0);
}

int print_last_number_pc(WINDOW *window, vm_t *vm)
{
    for (int y = 0; y < MEM_SIZE; y++) {
        if (vm->ncurses_values.arena_last_pc[y] != -1) {
            attron(COLOR_PAIR(vm->ncurses_values.arena_last_pc[y]));
            mvwprintw(window, y / 96 + 2, 3 * (y % 96) + 2, "%02hhX",
            vm->arena[y]);
            attroff(COLOR_PAIR(vm->ncurses_values.arena_last_pc[y]));
            vm->ncurses_values.arena_last_pc[y] = -1;
        }
    }
    return (0);
}

int print_arena(WINDOW *window, vm_t *vm)
{
    int offset = 0;
    int current_color = 0;

    print_last_number_pc(window, vm);
    for (int y = 0; y < Y_MAP_END - 2 && offset < MEM_SIZE; y++) {
        for (int i = 0; i * 3 < X_MAP_END - 2 && offset < MEM_SIZE; i++) {
            try_set_color(vm, offset, &current_color);
            try_print_number(vm, offset, y, i);
            offset++;
        }
    }
    for (int i = 0; i < vm->nb_champions; i++)
        print_number_pc(window, vm, i, vm->champions[i].nb_champion);
    return (0);
}
