/*
** EPITECH PROJECT, 2022
** live.c
** File description:
** live
*/

#include "corewar.h"

int exec_and_bit(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    (void)vm;
    champ->reg[buff->reg[2] - 1] = buff->dir[0] & buff->dir[1];
    champ->carry = 1;
    return 0;
}

int exec_or_bit(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    (void)vm;
    champ->reg[buff->reg[2] - 1] = buff->dir[0] | buff->dir[1];
    champ->carry = 1;
    return 0;
}

int exec_xor_bit(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    (void)vm;
    champ->reg[buff->reg[2] - 1] = buff->dir[0] ^ buff->dir[1];
    champ->carry = 1;
    return 0;
}
