/*
** EPITECH PROJECT, 2022
** live.c
** File description:
** live
*/

#include "../../include/corewar.h"

int aff(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    (void)vm;
    champ->busy = 2;
    if (buff->coding_byte != 0b01000000)
        return 1;
    return 0;
}

int exec_aff(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    char c = endian(champ->reg[buff->reg[0] - 1]) % 256;

    (void)vm;
    write(1, &c, 1);
    return 0;
}
