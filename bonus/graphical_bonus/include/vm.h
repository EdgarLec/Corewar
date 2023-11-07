/*
** EPITECH PROJECT, 2022
** vm.h
** File description:
** vm
*/

#ifndef VM_H_
    #define VM_H_

    #include <wait.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <errno.h>
    #include <string.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include "my.h"
    #include "op.h"

typedef struct champion {
    int pc;
    header_t *header;
    int reg[REG_NUMBER];
    int busy;
    bool carry;
    bool alive;
    int live;
    int nb_champion;
    long index;
    char *prog;
} champion_t;

typedef struct buffer_t buffer_t;

typedef struct ncurses_values {
    WINDOW *window;
    int last_cycle_to_die;
    int last_lives[4];
    int lives_in_period[4];
    long *map_belongings;
    char *arena_last_iteration;
    long *arena_last_pc;
    int champ_nb_start;
    int current_offset_write;
} ncurses_values_t;

typedef struct vm {
    int cycle_to_die;
    int nb_live;
    char *arena;
    buffer_t *buffer;
    champion_t *champions;
    int nb_champions;
    int cycle_counter;
    long id_chmp[4];
    long nb_cycle_dump;
    int last_alive;
    ncurses_values_t ncurses_values;
} vm_t;

void stock_champions(vm_t *vm, char **av, int ac);
char *init_arena(void);
int try_print_dump(vm_t *vm);
void arg_handling(int ac, char **av, vm_t *vm);
void init_champion(champion_t *chmp, char *file, long nb);
vm_t *get_vm(bool set);
void put_in_arena(champion_t *chmp, vm_t *vm, long i);
void init_and_update_id_and_reg(char *const *av, const short *nb_chmp,
const int *i);
void fix_chmp_order(void);

void a_second_flag(int ac, char *const *av, const short *nb_chmp,
int *i);
void check_second_arg_with_a(int ac, char *const *av, const short
*nb_chmp, int *i);
void a_first_flag(int ac, char *const *av, short *nb_chmp, int *i);
void n_second_flag(int ac, char *const *av, const short *nb_chmp,
int *i);
void check_second_arg_with_n(int ac, char *const *av, const short
*nb_chmp, int *i);
void n_first_flag(int ac, char *const *av, short *nb_chmp, int *i);
void kill_champ(vm_t *vm, int champ_id);
int check_champs_alive(vm_t *vm, int nb_champs);
void loop_ld(const buffer_t *buff, const vm_t *vm, const champion_t *champ,
char *tmp);
void loop_lld(const buffer_t *buff, const vm_t *vm, const champion_t *champ,
char *tmp);
void change_value_my_fork(buffer_t *buff, vm_t *vm, champion_t *champ,
champion_t *champ_array);
void change_value_my_lfork(buffer_t *buff, vm_t *vm, champion_t *champ,
champion_t *champ_array);

#endif
