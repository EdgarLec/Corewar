/*
** EPITECH PROJECT, 2022
** live.c
** File description:
** live
*/

#include "../../include/corewar.h"

int add_bit(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    (void)vm;
    if (buff->coding_byte != 0b01010100) {
        champ->carry = 0;
        return 1;
    }
    if (buff->reg[0] - 1 < 0 || buff->reg[0]
    - 1 >= REG_NUMBER || buff->reg[1] - 1 < 0 || buff->reg[1]
    - 1 >= REG_NUMBER || buff->reg[2] - 1 < 0 || buff->reg[2]
    - 1 >= REG_NUMBER) {
        champ->carry = 0;
        return 1;
    }
    champ->busy = 10;
    return 0;
}

int exec_add_bit(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    (void)vm;
    champ->reg[buff->reg[2] - 1] = endian(endian(champ->
    reg[buff->reg[0] - 1]) + endian(champ->reg[buff->reg[1] - 1]));
    champ->carry = 1;
    return 0;
}

int sub_bit(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    (void)vm;
    if (buff->coding_byte != 0b01010100) {
        champ->carry = 0;
        return 1;
    }
    if (buff->reg[0] - 1 < 0 || buff->reg[0]
    - 1 >= REG_NUMBER || buff->reg[1] - 1 < 0 || buff->reg[1]
    - 1 >= REG_NUMBER || buff->reg[2] - 1 < 0 || buff->reg[2]
    - 1 >= REG_NUMBER) {
        champ->carry = 0;
        return 1;
    }
    champ->busy = 10;
    return 0;
}

int exec_sub_bit(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    (void)vm;
    champ->reg[buff->reg[2] - 1] = endian(endian(
    champ->reg[buff->reg[0] - 1]) - endian(champ->reg[buff->reg[1] - 1]));
    champ->carry = 1;
    return 0;
}
