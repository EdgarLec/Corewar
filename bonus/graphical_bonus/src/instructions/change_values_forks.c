/*
** EPITECH PROJECT, 2022
** change_values_forks.c
** File description:
** change values
*/

#include "../../include/corewar.h"
#include "../../include/vm.h"

void change_value_my_fork(buffer_t *buff, vm_t *vm, champion_t *champ,
champion_t *champ_array)
{
    int value = (champ->pc - buff->size + (short_endian(buff->ind[0]) %
    IDX_MOD)) % MEM_SIZE;

    if (value < 0)
        value += MEM_SIZE;
    champ_array[vm->nb_champions - 1].pc = value;
}

void change_value_my_lfork(buffer_t *buff, vm_t *vm, champion_t *champ,
champion_t *champ_array)
{
    int value = (champ->pc - buff->size + (short_endian(buff->ind[0])))
    % MEM_SIZE;

    if (value < 0)
        value += MEM_SIZE;
    champ_array[vm->nb_champions - 1].pc = value;
}
