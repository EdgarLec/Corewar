/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** corewar
*/

#ifndef ASM_H_
    #define ASM_H_

    #include <wait.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <errno.h>
    #include <string.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <ncurses.h>
    #include "my.h"
    #include "op.h"
    #include "supaloc.h"
    #include "vm.h"

    #define IN_AR (MEM_SIZE / vm->nb_champions) * champ->nb_champion

typedef struct buffer_t {
    char action;
    char coding_byte;
    char c_byte[8];
    char reg[4];
    short ind[4];
    int dir[4];
    int size;
    int to_do;
} buffer_t;

// utils
int endian(int nb);
void *my_memcpy(void *dest, const void * src, size_t size);
void coding_byte(int nb, char *str);
short short_endian(short nb);

int get_action(char *arena, buffer_t *buffer, int pc);
header_t *init_head(int fd);

// dump param
char *my_convert_to_hex_cap(unsigned long long int a);

// ncurses

    #define NCURSES_WIDTH 291
    #define NCURSES_HEIGHT 90
    #define NCURSES_MAX_HEIGHT 91
    #define NCURSES_MAX_WIDTH 291
    #define Y_MAP_END 76
    #define X_MAP_END 288

// ncurses colors

    #define BLACK_WHITE 0
    #define BLUE_BLACK 1
    #define BLUE_WHITE 2
    #define WHITE_BLUE 3
    #define RED_BLACK 4
    #define RED_WHITE 5
    #define WHITE_RED 6
    #define GREEN_BLACK 7
    #define GREEN_WHITE 8
    #define WHITE_GREEN 9
    #define CYAN_BLACK 10
    #define CYAN_WHITE 11
    #define WHITE_CYAN 12
    #define MAGENTA_BLACK 13
    #define MAGENTA_WHITE 14
    #define WHITE_MAGENTA 15

WINDOW *init_ncurses(vm_t *vm);
int try_print_please_enlarge(WINDOW *window);
int refresh_ncurses(WINDOW *window, vm_t *vm, int mode);
int print_arena(WINDOW *window, vm_t *vm);
int print_vm_stats(WINDOW *window, vm_t *vm);
int print_vm_stats_canvas(WINDOW *window);
int print_champion_stats(WINDOW *window, vm_t *vm, int i);
int print_champion_canvas(WINDOW *window, int i);
void fill_map_belongings(vm_t *vm);
int get_champion_color_nb_pc(vm_t *vm, long nb_champion);
int get_champion_color_nb(vm_t *vm, long nb_champion);
int try_set_color(vm_t *vm, int offset, int *current_color);
void init_vm_values(vm_t *vm);
int try_handle_key_pressed(WINDOW *window, vm_t *vm, int mode);
void print_sleep_time(WINDOW *window, int sleep_value);
int process_end_ncurses(WINDOW *window, vm_t *vm);
int print_back_canvas_arena(WINDOW *window, vm_t *vm);
int draw_edges_init(WINDOW *window, vm_t *vm);

// dump param
int aff(buffer_t *buff, vm_t *vm, champion_t *champ);
int lld(buffer_t *buff, vm_t *vm, champion_t *champ);
int my_ld(buffer_t *buff, vm_t *vm, champion_t *champ);
int and_bit(buffer_t *buff, vm_t *vm, champion_t *champ);
int or_bit(buffer_t *buff, vm_t *vm, champion_t *champ);
int xor_bit(buffer_t *buff, vm_t *vm, champion_t *champ);
int ldi(buffer_t *buff, vm_t *vm, champion_t *champ);
int lldi(buffer_t *buff, vm_t *vm, champion_t *champ);
int live(buffer_t *buff, vm_t *vm, champion_t *champ);
int sti(buffer_t *buff, vm_t *vm, champion_t *champ);
int my_st(buffer_t *buff, vm_t *vm, champion_t *champ);
int add_bit(buffer_t *buff, vm_t *vm, champion_t *champ);
int sub_bit(buffer_t *buff, vm_t *vm, champion_t *champ);
int zjmp(buffer_t *buff, vm_t *vm, champion_t *champ);
int my_fork(buffer_t *buff, vm_t *vm, champion_t *champ);
int my_lfork(buffer_t *buff, vm_t *vm, champion_t *champ);

// dump param exec
int exec_aff(buffer_t *buff, vm_t *vm, champion_t *champ);
int exec_lld(buffer_t *buff, vm_t *vm, champion_t *champ);
int exec_ld(buffer_t *buff, vm_t *vm, champion_t *champ);
int exec_and_bit(buffer_t *buff, vm_t *vm, champion_t *champ);
int exec_or_bit(buffer_t *buff, vm_t *vm, champion_t *champ);
int exec_xor_bit(buffer_t *buff, vm_t *vm, champion_t *champ);
int exec_ldi(buffer_t *buff, vm_t *vm, champion_t *champ);
int exec_lldi(buffer_t *buff, vm_t *vm, champion_t *champ);
int exec_live(buffer_t *buff, vm_t *vm, champion_t *champ);
int exec_sti(buffer_t *buff, vm_t *vm, champion_t *champ);
int exec_st(buffer_t *buff, vm_t *vm, champion_t *champ);
int exec_add_bit(buffer_t *buff, vm_t *vm, champion_t *champ);
int exec_sub_bit(buffer_t *buff, vm_t *vm, champion_t *champ);
int exec_zjmp(buffer_t *buff, vm_t *vm, champion_t *champ);
int exec_my_fork(buffer_t *buff, vm_t *vm, champion_t *champ);
int exec_my_lfork(buffer_t *buff, vm_t *vm, champion_t *champ);

int verif_reg(buffer_t *buff, int nb);

#endif
