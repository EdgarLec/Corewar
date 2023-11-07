/*
** EPITECH PROJECT, 2022
** loops_ld_lld.c
** File description:
** loops ld lld
*/

#include "../../include/corewar.h"

void loop_ld(const buffer_t *buff, const vm_t *vm, const champion_t *champ,
char *tmp)
{
    int value;

    for (int h = 0; h < 4; h++) {
        value = (champ->pc - buff->size + (h + short_endian(buff->ind[1]))
        % IDX_MOD) % MEM_SIZE;
        if (value < 0)
            value += MEM_SIZE;
        my_memcpy(tmp + h, vm->arena + value, 1);
    }
}

void loop_lld(const buffer_t *buff, const vm_t *vm, const champion_t *champ,
char *tmp)
{
    int value;

    for (int h = 0; h < IND_SIZE; h++) {
        value = (champ->pc - buff->size + h + short_endian(buff->ind[0]))
        % MEM_SIZE;
        if (value < 0)
            value += MEM_SIZE;
        my_memcpy(tmp + h, vm->arena + value, 1);
    }
}
