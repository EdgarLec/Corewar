/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "corewar.h"
#include "op.h"

int print_champion_canvas(WINDOW *window, int i)
{
    mvwprintw(window, NCURSES_HEIGHT - 21, 2 + 58 * i, "%c", '+');
    mvwprintw(window, NCURSES_HEIGHT - 21, 55 + 58 * i, "%c", '+');
    mvwprintw(window, NCURSES_HEIGHT - 3, 2 + 58 * i, "%c", '+');
    mvwprintw(window, NCURSES_HEIGHT - 3, 55 + 58 * i, "%c", '+');
    mvwhline(window, NCURSES_HEIGHT - 21, 3 + 58 * i, '-', 52);
    mvwhline(window, NCURSES_HEIGHT - 3, 3 + 58 * i, '-', 52);
    mvwvline(window, NCURSES_HEIGHT - 20, 2 + 58 * i, '|', 17);
    mvwvline(window, NCURSES_HEIGHT - 20, 55 + 58 * i, '|', 17);
    return (0);
}

int print_champion_stats(WINDOW *window, vm_t *vm, int i)
{
    mvwprintw(window, NCURSES_HEIGHT - 19, 4 + 58 * i, "                    ");
    mvwprintw(window, NCURSES_HEIGHT - 19, 4 + 58 * i, "Player %d -> ", i + 1);
    attron(COLOR_PAIR(i * 3 + 1));
    mvwprintw(window, NCURSES_HEIGHT - 19, 16 + 58 * i, vm->champions[i].
    header->prog_name);
    attroff(COLOR_PAIR(i * 3 + 1));
    mvwprintw(window, NCURSES_HEIGHT - 18, 4 + 58 * i + 2, "Last live :");
    mvwprintw(window, NCURSES_HEIGHT - 17, 4 + 58 * i + 2,
    "Lives in current period :");
    attron(COLOR_PAIR(MAGENTA_BLACK));
    mvwprintw(window, NCURSES_HEIGHT - 18, 30 + 58 * i + 2, "               ");
    mvwprintw(window, NCURSES_HEIGHT - 18, 30 + 58 * i + 2, "%d", vm->
    ncurses_values.last_lives[i]);
    mvwprintw(window, NCURSES_HEIGHT - 17, 30 + 58 * i + 2, "               ");
    mvwprintw(window, NCURSES_HEIGHT - 17, 30 + 58 * i + 2, "%d", vm->
    ncurses_values.lives_in_period[i]);
    attroff(COLOR_PAIR(MAGENTA_BLACK));
    return (0);
}

int print_vm_stats_canvas(WINDOW *window)
{
    mvwprintw(window, NCURSES_HEIGHT - 21, 2 + 232, "%c", '+');
    mvwprintw(window, NCURSES_HEIGHT - 21, 55 + 232, "%c", '+');
    mvwprintw(window, NCURSES_HEIGHT - 3, 2 + 232, "%c", '+');
    mvwprintw(window, NCURSES_HEIGHT - 3, 55 + 232, "%c", '+');
    mvwhline(window, NCURSES_HEIGHT - 21, 3 + 232, '-', 52);
    mvwhline(window, NCURSES_HEIGHT - 3, 3 + 232, '-', 52);
    mvwvline(window, NCURSES_HEIGHT - 20, 2 + 232, '|', 17);
    mvwvline(window, NCURSES_HEIGHT - 20, 55 + 232, '|', 17);
    return (0);
}

int print_vm_stats(WINDOW *window, vm_t *vm)
{
    mvwprintw(window, NCURSES_HEIGHT - 19, 4 + 232, "Current cycle :");
    mvwprintw(window, NCURSES_HEIGHT - 18, 4 + 232, "CYCLE_TO_DIE :");
    mvwprintw(window, NCURSES_HEIGHT - 17, 4 + 232, "CYCLE_DELTA :");
    mvwprintw(window, NCURSES_HEIGHT - 14, 4 + 232, "Champions outputs :");
    mvwprintw(window, NCURSES_HEIGHT - 19, 20 + 232, "                      ");
    mvwprintw(window, NCURSES_HEIGHT - 18, 20 + 232, "                      ");
    mvwprintw(window, NCURSES_HEIGHT - 17, 20 + 232, "                      ");
    attron(COLOR_PAIR(MAGENTA_BLACK));
    mvwprintw(window, NCURSES_HEIGHT - 19, 24 + 232, "%d", vm->cycle_counter);
    mvwprintw(window, NCURSES_HEIGHT - 18, 24 + 232, "%d", vm->cycle_to_die);
    mvwprintw(window, NCURSES_HEIGHT - 17, 24 + 232, "%d", CYCLE_DELTA);
    attroff(COLOR_PAIR(MAGENTA_BLACK));
    return (0);
}

void print_sleep_time(WINDOW *window, int sleep_value)
{
    mvwprintw(window, NCURSES_HEIGHT - 16, 4 + 232, "                       "
    "             ");
    mvwprintw(window, NCURSES_HEIGHT - 16, 4 + 232, "usleep/iterations :");
    attron(COLOR_PAIR(MAGENTA_BLACK));
    mvwprintw(window, NCURSES_HEIGHT - 16, 24 + 232, "%d", sleep_value);
    attroff(COLOR_PAIR(MAGENTA_BLACK));
}
