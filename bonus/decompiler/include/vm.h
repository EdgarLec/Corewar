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
    int fd;
    int pc;
    header_t *header;
    list_t *commands;
    char *prog;
} champion_t;

typedef struct buffer_t buffer_t;

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
} vm_t;

void stock_champions(vm_t *vm, char **av, int ac);
char *init_arena(void);
int try_print_dump(vm_t *vm);
void arg_handling(int ac, char **av, vm_t *vm);
void init_champion(champion_t *chmp, char *file, long nb, vm_t *vm);
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

#endif
