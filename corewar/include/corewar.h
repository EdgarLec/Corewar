/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** corewar
*/

/// @file corewar.h
/// @brief Header file for the virtual machine. Contains all the prototypes,
///        macros, arrays and structures needed for the vm.

#ifndef COREWAR_H_
    #define COREWAR_H_

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
    #include "vm.h"

    #define IN_AR (MEM_SIZE / vm->nb_champions) * champ->nb_champion

////////////////////////////////////////////////////////////
/// \brief Struct with all informations of an instruction.
///
/// \param action The nb of the instruction (ex 0 for live, 1 for ld).
///
/// \param coding_byte The coding byte.
///
/// \param reg all the registers.
///
/// \param ind all the indirects numbers (or indexes).
///
/// \param dir all the directes numbers.
///
/// \param size size of the instruction in byte.
///
/// \param to_do 1 if there is an action to execute 0 if not.
///
////////////////////////////////////////////////////////////
typedef struct buffer_t {
    char action;
    char coding_byte;
    char reg[4];
    short ind[4];
    int dir[4];
    int size;
    int to_do;
} buffer_t;

////////////////////////////////////////////////////////////
/// \brief Reverse the endianess of an int.
///
/// \param nb Number to reverse.
///
/// \return Return the reversed number.
///
////////////////////////////////////////////////////////////
int endian(int nb);

////////////////////////////////////////////////////////////
/// \brief Reverse the endianess of a short.
///
/// \param nb Number to reverse.
///
/// \return Return the reversed number.
///
////////////////////////////////////////////////////////////
short short_endian(short nb);

void *my_memcpy(void *dest, const void * src, size_t size);

////////////////////////////////////////////////////////////
/// \brief Read all the elements of an instruction and place it in a buffer_t.
///
/// \param arena The place where all the instructions are contained.
///
/// \param buffer The pointer of the structure where the instruction will be placed.
///
/// \param pc The index of the beginning of the instruction in arena.
///
/// \return Return the size of the instruction.
///
////////////////////////////////////////////////////////////
int get_action(char *arena, buffer_t *buffer, int pc);

/// \brief Init the header of a champion and verify if it's valid.
header_t *init_head(int fd);

// dump param
char *my_convert_to_hex_cap(unsigned long long int a);

/// \brief takes 1 parameter, which must be a register. It displays on the
///        standard output the character
///        whose ASCII code is the content of the register (in base 10).
///        A 256 modulo is applied to this ASCII code.
///        aff r3 displays ’*’ if r3 contains 42.
int aff(buffer_t *buff, vm_t *vm, champion_t *champ);

/// \brief takes 2 parameters. It loads the value of the first parameter into
///        the second parameter, which must be a register (not the PC).
///        This operation modifies the carry.
int my_ld(buffer_t *buff, vm_t *vm, champion_t *champ);

/// \brief Similar to ld without the % IDX_MOD. This operation modifies the
///        carry.
int lld(buffer_t *buff, vm_t *vm, champion_t *champ);

/// \brief takes 3 parameters. It performs a binary AND between the first two
/// parameters and stores the result into the third one (which must be a
/// register). This operation modifies the carry.
/// and r2, %0,r3 puts r2 & 0 into r3.
int and_bit(buffer_t *buff, vm_t *vm, champion_t *champ);

/// \brief Similar to and, but performing a binary OR.
int or_bit(buffer_t *buff, vm_t *vm, champion_t *champ);

/// \brief Similar to and, but performing a binary XOR.
int xor_bit(buffer_t *buff, vm_t *vm, champion_t *champ);

/// \brief takes 3 parameters. The first two must be indexes or registers,
/// the third one must
/// be a register. This operation modifies the carry.
/// ldi 3,%4,r1 reads IND_SIZ bytes from the address PC + 3 % IDX_MOD, adds 4
/// to this value.
/// The sum is named S. REG_SIZE bytes are read from the address PC + S %
/// IDX_MOD and copied into r1
int ldi(buffer_t *buff, vm_t *vm, champion_t *champ);

/// \brief Similar to ld without the % IDX_MOD. This operation modifies
/// the carry.
int lldi(buffer_t *buff, vm_t *vm, champion_t *champ);

/// \brief takes 1 parameter: 4 bytes that represent the player’s number.
/// It indicates that the player is alive.
int live(buffer_t *buff, vm_t *vm, champion_t *champ);

/// \brief takes 3 parameters. The first one must be a register. The other two
/// can be indexes or registers.
/// sti r2,%4,%5 copies the content of r2 into the address PC + (4+5)% IDX_MOD.
int sti(buffer_t *buff, vm_t *vm, champion_t *champ);

/// \brief takes 2 parameters. It stores the first parameter’s value (which is a
/// register) into
/// the second (whether a register or a number).
/// st r4,34 stores the content of r4 at the address PC + 34 % IDX_MOD.
/// st r3,r8 copies the content of r3 into r8.
int my_st(buffer_t *buff, vm_t *vm, champion_t *champ);

/// \brief takes 3 registers as parameters. It adds the content of the first two
/// and puts the sum into
/// the third one (which must be a register). This operation modifies the carry.
/// add r2,r3,r5 adds the content of r2 and r3 and puts the result into r5.
int add_bit(buffer_t *buff, vm_t *vm, champion_t *champ);

/// \brief Similar to add, but performing a subtraction.
int sub_bit(buffer_t *buff, vm_t *vm, champion_t *champ);

/// \brief takes 1 parameter, which must be an index. It jumps to this index if
/// the carry is worth 1.
/// Otherwise, it does nothing but consumes the same time.
/// zjmp %23 puts, if carry equals 1, PC + 23 % IDX_MOD into the PC.
int zjmp(buffer_t *buff, vm_t *vm, champion_t *champ);

/// \brief takes 1 parameter, which must be an index. It creates a new program
/// that inherits different
/// states from the parent. This program is executed at the address
/// PC + first parameter % IDX_MOD.
int my_fork(buffer_t *buff, vm_t *vm, champion_t *champ);

/// \brief Similar to fork without the % IDX_MOD.
int my_lfork(buffer_t *buff, vm_t *vm, champion_t *champ);

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
