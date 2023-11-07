/*
** EPITECH PROJECT, 2022
** live.c
** File description:
** live
*/

#include "../../include/corewar.h"

int my_st(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    (void)vm;
    if ((buff->coding_byte != 0b01110000 && buff->coding_byte != 0b01010000) ||
    buff->reg[0] - 1 < 0 || buff->reg[0] - 1 >= REG_NUMBER)
        return 1;
    if (buff->coding_byte == 0b01010000 && (buff->reg[1] - 1 < 0 ||
    buff->reg[1] - 1 >= REG_NUMBER))
        return 1;
    champ->busy = 5;
    return 0;
}

void loop_st(const buffer_t *buff, const vm_t *vm, const champion_t *champ,
int reg)
{
    int value;

    for (int h = 0; h < 4; h++) {
        value = (champ->pc - buff->size + (h + short_endian(buff->ind[1]))
        % IDX_MOD) % MEM_SIZE;
        while (value < 0)
            value += MEM_SIZE;
        my_memcpy((char *)(vm->arena) + value, ((char *)&champ->reg[reg])
        + h, 1);
    }
}

int exec_st(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    int reg = buff->reg[0] - 1;

    if (buff->coding_byte == 0b01110000) {
        loop_st(buff, vm, champ, reg);
    } else
        champ->reg[buff->reg[1] - 1] = champ->reg[reg];
    return 0;
}
