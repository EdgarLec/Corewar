/*
** EPITECH PROJECT, 2022
** live.c
** File description:
** live
*/

#include "../../include/corewar.h"

int zjmp(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    (void)buff;
    (void)vm;
    champ->busy = 20;
    return 0;
}

int exec_zjmp(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    int value;

    (void)vm;
    if (!champ->carry)
        return 0;
    value = (champ->pc - 3 + (short_endian(buff->ind[0]) % IDX_MOD)) % MEM_SIZE;
    while (value < 0)
        value += MEM_SIZE;
    champ->pc = value;
    return 0;
}
