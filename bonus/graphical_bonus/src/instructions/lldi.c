/*
** EPITECH PROJECT, 2022
** live.c
** File description:
** live
*/

#include "../../include/corewar.h"

short loop_lldi(const buffer_t *buff, const vm_t *vm, const champion_t *champ,
short *tmp)
{
    int value;

    for (int h = 0; h < IND_SIZE; h++) {
        value = (champ->pc - buff->
        size + (h + short_endian(buff->ind[0]))) % MEM_SIZE;
        if (value < 0)
            value += MEM_SIZE;
        my_memcpy((char *)(tmp) + h, vm->arena + value, 1);
    }
    return (*tmp);
}

int read_lldi(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    int sum = 0;
    short tmp = 0;

    if ((buff->coding_byte & 0b11000011) == 0b01000000) {
        sum += endian(champ->reg[buff->reg[0] - 1]);
    } else {
        tmp = loop_lldi(buff, vm, champ, &tmp);
        sum += short_endian(tmp);
    }
    if ((buff->coding_byte & 0b00110011) == 0b00010000) {
        sum += endian(champ->reg[buff->reg[1] - 1]);
    } else
        sum += short_endian(buff->ind[1]);
    return sum;
}

int lldi(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    int value;
    int sum = 0;

    if ((buff->coding_byte & 0b1111) != 0b0100 ||
    buff->reg[2] - 1 < 0 || buff->reg[2] - 1 >= REG_NUMBER ||
    verif_reg(buff, 0) || verif_reg(buff, 1)) {
        champ->carry = 0;
        return 1;
    }
    champ->busy = 25;
    champ->carry = 1;
    sum = read_lldi(buff, vm, champ);
    for (int h = 0; h < 4; h++) {
        value = (champ->pc + (h + sum)) % MEM_SIZE;
        if (value < 0)
            value += MEM_SIZE;
        my_memcpy((char *)(&buff->dir[0]) + h, vm->arena + value, 1);
    }
    return 0;
}

int exec_lldi(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    (void)vm;
    champ->reg[buff->reg[2] - 1] = buff->reg[0];
    return 0;
}
