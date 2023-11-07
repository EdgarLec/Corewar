/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** dump_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);
int print_dump(char *arena, int i, int max_len);

Test(dump_tests, print_dump_tests, .init = redirect_all_stdout)
{
    print_dump("arena", 0, 5);
    print_dump("arena", 6 * 1024, 2);
}
