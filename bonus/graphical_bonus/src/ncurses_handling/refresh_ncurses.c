/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "corewar.h"
#include "op.h"

int print_new_iteration_ncurses(WINDOW *window, vm_t *vm)
{
    print_arena(window, vm);
    for (int i = 0; i < vm->ncurses_values.champ_nb_start; i++)
        print_champion_stats(window, vm, i);
    print_vm_stats(window, vm);
    wrefresh(window);
    return (0);
}

int edit_lives_values_vm(vm_t *vm)
{
    if (vm->cycle_to_die != vm->ncurses_values.last_cycle_to_die) {
        vm->ncurses_values.last_cycle_to_die = vm->cycle_to_die;
        for (int i = 0; i < vm->ncurses_values.champ_nb_start; i++)
            vm->ncurses_values.lives_in_period[i] = 0;
    }
    for (int i = 0; i < vm->ncurses_values.champ_nb_start; i++) {
        if (vm->champions[i].live == 1) {
            vm->ncurses_values.last_lives[i] = vm->cycle_counter;
            vm->ncurses_values.lives_in_period[i]++;
        }
    }
    return (0);
}

void handle_key_pressed(int key, int *sleep_value)
{
    if (key == KEY_DOWN && *sleep_value != 100)
        *sleep_value -= 100;
    if (key == KEY_UP)
        *sleep_value += 100;
    if (key == 27) {
        endwin();
        supexit(recup(), 0);
    }
}

int try_handle_key_pressed(WINDOW *window, vm_t *vm, int mode)
{
    int key = 0;
    static int sleep_value;

    if (mode == 1) {
        sleep_value = 5000;
        return (1);
    }
    print_sleep_time(window, sleep_value);
    key = wgetch(window);
    usleep(sleep_value);
    if (key == ERR)
        return (1);
    handle_key_pressed(key, &sleep_value);
    return (0);
}

int refresh_ncurses(WINDOW *window, vm_t *vm, int mode)
{
    static int size_is_right;

    if (mode == 1)
        size_is_right = 1;
    if (try_print_please_enlarge(window) == 1) {
        wgetch(window);
        size_is_right = 0;
        usleep(4000);
        wrefresh(window);
        return (1);
    }
    if (size_is_right == 0) {
        print_back_canvas_arena(window, vm);
        size_is_right = 1;
    }
    edit_lives_values_vm(vm);
    print_new_iteration_ncurses(window, vm);
    try_handle_key_pressed(window, vm, 0);
    return (0);
}
