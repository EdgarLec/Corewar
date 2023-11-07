/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** endian
*/

#include "asm.h"

short short_endian(short nb)
{
    short result = 0;

    for (int i = 0; i < 2; i++)
        result = (result << 8) | (nb & 0xFF), nb >>= 8;
    return result;
}

int endian(int nb)
{
    int result = 0;

    for (int i = 0; i < 4; i++)
        result = (result << 8) | (nb & 0xFF), nb >>= 8;
    return result;
}
