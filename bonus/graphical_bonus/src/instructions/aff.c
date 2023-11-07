/*
** EPITECH PROJECT, 2022
** live.c
** File description:
** live
*/

#include "../../include/corewar.h"

int aff(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    (void)vm;
    champ->busy = 2;
    if (buff->coding_byte != 0b01000000)
        return 1;
    return 0;
}

int exec_aff(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    char c = endian(champ->reg[buff->reg[0] - 1]) % 256;

    (void)vm;
    if (vm->ncurses_values.current_offset_write >= 50 * 8)
        vm->ncurses_values.current_offset_write = 0;
    mvwprintw(vm->ncurses_values.window, NCURSES_HEIGHT - 12 + vm->
    ncurses_values.current_offset_write / 50, 4 + 232 + vm->ncurses_values.
    current_offset_write % 50,
    "%c", c);
    vm->ncurses_values.current_offset_write++;
    return 0;
}
