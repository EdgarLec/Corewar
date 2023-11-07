/*
** EPITECH PROJECT, 2022
** live.c
** File description:
** live
*/

#include "corewar.h"

int find_elem(int info[2], vm_t *vm, buffer_t *buff, champion_t *champ)
{
    int test = 0;
    char *tmp = (char *)&test;
    char byte = buff->coding_byte;
    int value;

    byte = (byte & (3 << info[0])) >> info[0];
    if (byte == 1)
        return (champ->reg[buff->reg[info[1]] - 1]);
    if (byte == 2) {
        for (int h = 0; h < 4; h++) {
            value = (champ->pc - buff->size + (h + short_endian
            (buff->ind[info[1]])) % IDX_MOD) % MEM_SIZE;
            (value < 0) ? (value += MEM_SIZE) : (value = value);
            my_memcpy(tmp + h, vm->arena + value, 1);
        }
        return test;
    }
    if (byte == 3)
        return (buff->dir[info[1]]);
    return 0;
}

int verif_reg(buffer_t *buff, int nb)
{
    if ((buff->coding_byte >> (3 - nb) * 2 & 0b11) == 0b01)
        if (buff->reg[nb] - 1 < 0 || buff->reg[nb] - 1 >= REG_NUMBER)
            return 1;
    return 0;
}

int and_bit(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    if ((buff->coding_byte & 0b00001100) != 0b00000100 ||
    (buff->coding_byte & 0b00000011) != 0b00000000) {
        champ->carry = 0;
        return 1;
    }
    if (verif_reg(buff, 0) || verif_reg(buff, 1) || verif_reg(buff, 2)) {
        champ->carry = 0;
        return 1;
    }
    if ((buff->coding_byte & (3 << 2)) >> 2 != 0 &&
    (buff->coding_byte & (3 << 4)) >> 4 != 0) {
        champ->busy = 6;
        champ->carry = 1;
        buff->dir[0] = find_elem((int [2]){2, 0}, vm, buff, champ);
        buff->dir[1] = find_elem((int [2]){4, 1}, vm, buff, champ);
        return 0;
    }
    champ->carry = 0;
    return 1;
}

int or_bit(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    if ((buff->coding_byte & 0b00001100) != 0b00000100 ||
    (buff->coding_byte & 0b00000011) != 0b00000000) {
        champ->carry = 0;
        return 1;
    }
    if (verif_reg(buff, 0) || verif_reg(buff, 1) || verif_reg(buff, 2)) {
        champ->carry = 0;
        return 1;
    }
    if ((buff->coding_byte & (3 << 2)) >> 2 != 0 &&
    (buff->coding_byte & (3 << 4)) >> 4 != 0) {
        champ->busy = 6;
        champ->carry = 1;
        buff->dir[0] = find_elem((int [2]){2, 0}, vm, buff, champ);
        buff->dir[1] = find_elem((int [2]){4, 1}, vm, buff, champ);
        return 0;
    }
    champ->carry = 0;
    return 1;
}

int xor_bit(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    if ((buff->coding_byte & 0b00001100) != 0b00000100 ||
    (buff->coding_byte & 0b00000011) != 0b00000000) {
        champ->carry = 0;
        return 1;
    }
    if (verif_reg(buff, 0) || verif_reg(buff, 1) || verif_reg(buff, 2)) {
        champ->carry = 0;
        return 1;
    }
    if ((buff->coding_byte & (3 << 2)) >> 2 != 0 &&
    (buff->coding_byte & (3 << 4)) >> 4 != 0) {
        champ->busy = 6;
        champ->carry = 1;
        buff->dir[0] = find_elem((int [2]){2, 0}, vm, buff, champ);
        buff->dir[1] = find_elem((int [2]){4, 1}, vm, buff, champ);
        return 0;
    }
    champ->carry = 0;
    return 1;
}
