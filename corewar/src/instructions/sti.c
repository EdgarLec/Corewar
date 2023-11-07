/*
** EPITECH PROJECT, 2022
** live.c
** File description:
** live
*/

#include "../../include/corewar.h"

int get_index(int info[2], vm_t *vm, buffer_t *buff, champion_t *champ)
{
    char byte = buff->coding_byte;

    (void)vm;
    byte = (byte & (3 << info[0])) >> info[0];
    if (byte == 1)
        return (endian(champ->reg[buff->reg[info[1]] - 1]));
    return short_endian(buff->ind[info[1]]);
}

int sti(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    if ((buff->coding_byte & 0b11000011) != 0b01000000 || verif_reg(buff, 0) ||
    verif_reg(buff, 1) || verif_reg(buff, 2))
        return 1;
    champ->busy = 25;
    buff->dir[0] = get_index((int [2]){2, 2}, vm, buff, champ);
    buff->dir[1] = get_index((int [2]){4, 1}, vm, buff, champ);
    return 0;
}

int exec_sti(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    int value;

    for (int h = 0; h < 4; h++) {
        value = (champ->pc - buff->size + (h + buff->dir[0] + buff->dir[1])
        % IDX_MOD) % MEM_SIZE;
        while (value < 0)
            value += MEM_SIZE;
        my_memcpy(vm->arena + value, ((char *)(&champ->reg[buff->reg[0] - 1]))
        + h, 1);
    }
    return 0;
}
