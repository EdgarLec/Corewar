/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "corewar.h"
#include "op.h"

int endian(int nb)
{
    int result = 0;

    for (int i = 0; i < 4; i++)
        result = (result << 8) | (nb & 0xFF), nb >>= 8;
    return result;
}

void *my_memcpy(void *dest, const void *src, size_t size)
{
    char *d = dest;
    const char *s = src;

    for (size_t i = 0; i < size; i++)
        d[i] = s[i];
    return dest;
}

short short_endian(short nb)
{
    short result = 0;

    for (int i = 0; i < 2; i++)
        result = (result << 8) | (nb & 0xFF), nb >>= 8;
    return result;
}

vm_t *get_vm(bool set)
{
    static vm_t *vm;

    if (set)
        vm = malloc(sizeof(vm_t));
    return vm;
}
