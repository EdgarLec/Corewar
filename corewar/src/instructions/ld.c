/*
** EPITECH PROJECT, 2022
** live.c
** File description:
** live
*/

#include "../../include/corewar.h"

int my_ld(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    char *tmp = (char *)&buff->dir[0];

    if (((buff->coding_byte & 0b11111111) != 0b11010000
    && (buff->coding_byte & 0b11111111) != 0b10010000) ||
    buff->reg[1] - 1 < 0 || buff->reg[1] - 1 >= REG_NUMBER) {
        champ->carry = 0;
        return 1;
    }
    champ->busy = 5;
    champ->carry = 1;
    if ((buff->coding_byte & 0b11111111) == 0b11010000)
        loop_ld(buff, vm, champ, tmp);
    return 0;
}

int exec_ld(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    int reg = buff->reg[1] - 1;

    (void)vm;
    champ->carry = 1;
    champ->reg[reg] = 0;
    champ->reg[reg] = buff->dir[0];
    return 0;
}

int lld(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    char *tmp = (char *)&buff->dir[0];

    if (((buff->coding_byte & 0b11111111) != 0b11010000
    && (buff->coding_byte & 0b11111111) != 0b10010000) ||
    buff->reg[1] - 1 < 0 || buff->reg[1] - 1 >= REG_NUMBER) {
        champ->carry = 0;
        return 1;
    }
    champ->busy = 10;
    champ->carry = 1;
    if (buff->coding_byte == (char)0b11010000)
        loop_lld(buff, vm, champ, tmp);
    return 0;
}

int exec_lld(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    int reg = buff->reg[1] - 1;

    (void)vm;
    champ->carry = 1;
    champ->reg[reg] = 0;
    champ->reg[reg] = buff->dir[0];
    return 0;
}
