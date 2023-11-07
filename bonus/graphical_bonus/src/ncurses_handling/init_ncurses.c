/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "corewar.h"
#include "op.h"

int try_print_please_enlarge(WINDOW *window)
{
    int offset_x = 0;
    int offset_y = 0;

    if (!(LINES < NCURSES_HEIGHT || COLS < NCURSES_WIDTH))
        return (0);
    clear();
    offset_x = (COLS - 39) / 2;
    offset_y = (LINES - 1) / 2;
    if (offset_x < 0)
        offset_x = 0;
    if (offset_y < 0)
        offset_y = 0;
    mvwprintw(window, offset_y, offset_x,
    "Please enlarge the terminal. (Zoom out)");
    return (1);
}

int draw_edges_init(WINDOW *window, vm_t *vm)
{
    mvwprintw(window, 0, 0, "%c", '+');
    mvwprintw(window, 0, 290, "%c", '+');
    mvwprintw(window, NCURSES_HEIGHT - 1, 290, "%c", '+');
    mvwprintw(window, NCURSES_HEIGHT - 1, 0, "%c", '+');
    mvwvline(window, 1, 0, '|', NCURSES_HEIGHT - 2);
    mvwvline(window, 1, 290, '|', NCURSES_HEIGHT - 2);
    mvwhline(window, 0, 1, '-', NCURSES_WIDTH - 2);
    mvwhline(window, NCURSES_HEIGHT - 1, 1, '-', NCURSES_WIDTH - 2);
    mvwhline(window, NCURSES_HEIGHT - 23, 1, '-', NCURSES_WIDTH - 2);
    mvwprintw(window, NCURSES_HEIGHT - 23, 290, "%c", '+');
    mvwprintw(window, NCURSES_HEIGHT - 23, 0, "%c", '+');
    print_vm_stats_canvas(window);
    for (int i = 0; i < vm->ncurses_values.champ_nb_start; i++)
        print_champion_canvas(window, i);
    return (0);
}

int init_colors(void)
{
    start_color();
    init_pair(0, COLOR_BLACK, COLOR_WHITE);
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_WHITE);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_WHITE);
    init_pair(6, COLOR_WHITE, COLOR_RED);
    init_pair(7, COLOR_GREEN, COLOR_BLACK);
    init_pair(8, COLOR_GREEN, COLOR_WHITE);
    init_pair(9, COLOR_WHITE, COLOR_GREEN);
    init_pair(10, COLOR_CYAN, COLOR_BLACK);
    init_pair(11, COLOR_CYAN, COLOR_WHITE);
    init_pair(12, COLOR_WHITE, COLOR_CYAN);
    init_pair(13, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(14, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(15, COLOR_WHITE, COLOR_MAGENTA);
    return (0);
}

int init_ncurses_struct(vm_t *vm)
{
    vm->ncurses_values.map_belongings = supaloc(sizeof(long) *
    (MEM_SIZE + 1));
    vm->ncurses_values.arena_last_iteration = supaloc(sizeof(char) *
    (MEM_SIZE + 1));
    vm->ncurses_values.arena_last_pc = supaloc(sizeof(long) *
    (MEM_SIZE + 1));
    for (int i = 0; i < MEM_SIZE + 1; i++) {
        vm->ncurses_values.map_belongings[i] = 0;
        vm->ncurses_values.arena_last_pc[i] = -1;
        vm->ncurses_values.arena_last_iteration[i] = -1;
    }
    fill_map_belongings(vm);
    vm->ncurses_values.last_cycle_to_die = CYCLE_TO_DIE;
    for (int i = 0; i != 4; i++) {
        vm->ncurses_values.last_lives[i] = 0;
        vm->ncurses_values.lives_in_period[i] = 0;
    }
    vm->ncurses_values.champ_nb_start = vm->nb_champions;
    vm->ncurses_values.current_offset_write = 0;
    return (0);
}

WINDOW *init_ncurses(vm_t *vm)
{
    WINDOW *window = initscr();

    vm->ncurses_values.window = window;
    init_ncurses_struct(vm);
    keypad(window, TRUE);
    curs_set(0);
    noecho();
    init_colors();
    wtimeout(window, 0);
    refresh_ncurses(window, vm, 1);
    try_handle_key_pressed(window, vm, 1);
    while (try_print_please_enlarge(window) == 1) {
        wrefresh(window);
        usleep(500);
    }
    draw_edges_init(window, vm);
    wrefresh(window);
    return (window);
}
