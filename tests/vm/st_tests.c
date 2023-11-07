/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** st_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);

Test(st_tests, test_my_st, .init = redirect_all_stdout)
{
    buffer_t buff;
    champion_t champ;

    memset(&buff, 0, sizeof(buffer_t));
    memset(&champ, 0, sizeof(champion_t));
    my_st(&buff, 0, 0);
    buff.coding_byte = 0b01110000;
    buff.reg[0] = -10;
    my_st(&buff, 0, 0);
    buff.reg[0] = 20;
    my_st(&buff, 0, 0);
    buff.coding_byte = 0b01010000;
    my_st(&buff, 0, 0);
    buff.reg[0] = 10;
    buff.reg[1] = -10;
    my_st(&buff, 0, 0);
    buff.reg[1] = 20;
    my_st(&buff, 0, 0);
    buff.reg[1] = 10;
    my_st(&buff, 0, &champ);
}

Test(st_tests, test_exec_st, .init = redirect_all_stdout)
{
    buffer_t buff;
    champion_t champ;

    memset(&buff, 0, sizeof(buffer_t));
    memset(&champ, 0, sizeof(champion_t));
    exec_st(&buff, 0, &champ);
}