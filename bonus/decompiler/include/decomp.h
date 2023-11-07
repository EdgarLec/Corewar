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

// dump param
int aff(buffer_t *buff, vm_t *vm, champion_t *champ);
int lld(buffer_t *buff, vm_t *vm, champion_t *champ);
int ld(buffer_t *buff, vm_t *vm, champion_t *champ);
int and_bit(buffer_t *buff, vm_t *vm, champion_t *champ);
int or_bit(buffer_t *buff, vm_t *vm, champion_t *champ);
int xor_bit(buffer_t *buff, vm_t *vm, champion_t *champ);
int ldi(buffer_t *buff, vm_t *vm, champion_t *champ);
int lldi(buffer_t *buff, vm_t *vm, champion_t *champ);
int live(buffer_t *buff, vm_t *vm, champion_t *champ);
int sti(buffer_t *buff, vm_t *vm, champion_t *champ);
int st(buffer_t *buff, vm_t *vm, champion_t *champ);
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

#endif
