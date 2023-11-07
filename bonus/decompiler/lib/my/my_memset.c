/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** my_memset
*/

#include "my.h"

void *my_memset(void *dest, int val, size_t len)
{
    unsigned char *ptr = dest;

    for (size_t i = 0; i < len; i++)
        ptr[i] = val;
    return dest;
}
