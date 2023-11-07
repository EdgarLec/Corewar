/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "corewar.h"
#include "op.h"

int print_dump(char *arena, int i, int max_len)
{
    int counter = 0;

    my_printf("%-*X : ", max_len, i);
    for (; counter < 32 && i + counter != MEM_SIZE; counter++)
        my_printf("%02hhX ", arena[counter + i]);
    my_putchar('\n');
    return (counter);
}

int get_max_len_arena(void)
{
    char *max_len_string = my_convert_to_hex_cap(MEM_SIZE);
    int max_len = 0;

    if (max_len_string == NULL)
        return (-1);
    max_len = my_strlen(max_len_string);
    free(max_len_string);
    return (max_len);
}

int try_print_dump(vm_t *vm)
{
    long nbr_cycles = vm->nb_cycle_dump;
    int i = 0;
    int max_len = 0;

    if (vm->cycle_counter != nbr_cycles)
        return (0);
    max_len = get_max_len_arena();
    if (max_len == -1)
        return (1);
    while (i < MEM_SIZE)
        i += print_dump(vm->arena, i, max_len);
    return (1);
}
