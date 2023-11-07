/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "asm.h"

int main(int ac, char **av)
{
    int is_error = 0;

    if (ac < 2) {
        my_putstr("Usage: ./asm file_name[.s] ....\n");
        return 84;
    }
    for (int i = 1; av[i]; i++) {
        set_error(0);
        parse_file(av[i]);
        is_error += error(-1);
    }
    return is_error > 0 ? 84 : 0;
}
