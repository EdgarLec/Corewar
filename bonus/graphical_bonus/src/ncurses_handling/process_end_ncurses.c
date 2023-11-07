/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "corewar.h"
#include "op.h"

int process_end_ncurses(WINDOW *window, vm_t *vm)
{
    attron(COLOR_PAIR(GREEN_BLACK));
    mvwprintw(window, NCURSES_HEIGHT - 14, 4 + 58 * vm->last_alive + 2,
    "PLAYER %d (%s) WINS", vm->last_alive + 1, vm->champions[vm->last_alive].
    header->prog_name);
    attroff(COLOR_PAIR(GREEN_BLACK));
    mvwprintw(window, NCURSES_HEIGHT - 13, 4 + 58 * vm->last_alive + 2,
    "Press ESC to quit", vm->last_alive + 1, vm->champions[vm->last_alive].
    header->prog_name);
    wtimeout(window, -1);
    while (wgetch(window) != 27);
    endwin();
    return (0);
}
