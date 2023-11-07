/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** sti_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);

Test(sti_tests, test_my_st, .init = redirect_all_stdout)
{
    buffer_t buff;

    memset(&buff, 0, sizeof(buffer_t));
    sti(&buff, 0, 0);
    buff.coding_byte = 0b01010100;
    sti(&buff, 0, 0);
    buff.reg[0] = -1;
    sti(&buff, 0, 0);
    buff.reg[0] = 2;
    buff.reg[1] = -1;
    sti(&buff, 0, 0);
}
