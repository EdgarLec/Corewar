/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "corewar.h"
#include "op.h"

int get_champion_color_nb_pc(vm_t *vm, long nb_champion)
{
    for (int i = 0; i < vm->ncurses_values.champ_nb_start; i++) {
        if (vm->champions[i].nb_champion == nb_champion)
            return (i * 3 + 3);
    }
    return (0);
}

int get_champion_color_nb(vm_t *vm, long nb_champion)
{
    for (int i = 0; i < vm->ncurses_values.champ_nb_start; i++) {
        if (vm->champions[i].nb_champion == nb_champion)
            return (i * 3 + 1);
    }
    return (0);
}

int try_set_color(vm_t *vm, int offset, int *current_color)
{
    int champ_nb = 0;

    if (vm->ncurses_values.map_belongings[offset] == 0) {
        if (*current_color != 0)
            attroff(COLOR_PAIR(*current_color));
        return (1);
    }
    for (; champ_nb < vm->nb_champions && vm->ncurses_values.map_belongings
    [offset] != vm->champions[champ_nb].nb_champion; champ_nb++);
    if (vm->ncurses_values.map_belongings[offset] != vm->champions[champ_nb].
    nb_champion)
        return (1);
    *current_color = champ_nb * 3 + 1;
    attron(COLOR_PAIR(*current_color));
    return (0);
}
