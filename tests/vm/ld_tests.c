/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** ld_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);

Test(ld_tests, test_my_ld, .init = redirect_all_stdout)
{
    buffer_t buff;
    champion_t champ;

    memset(&buff, 0, sizeof(buffer_t));
    memset(&champ, 0, sizeof(champion_t));
    buff.coding_byte = 0b11010000;
    buff.reg[1] = -1;
    my_ld(&buff, 0, &champ);
    buff.reg[1] = 100;
    my_ld(&buff, 0, &champ);
}

Test(ld_tests, test_lld, .init = redirect_all_stdout)
{
    buffer_t buff;
    champion_t champ;

    memset(&buff, 0, sizeof(buffer_t));
    memset(&champ, 0, sizeof(champion_t));
    lld(&buff, 0, &champ);
    buff.coding_byte = 0b10010000;
    buff.reg[1] = -1;
    lld(&buff, 0, &champ);
    buff.reg[1] = 100;
    lld(&buff, 0, &champ);
    buff.reg[1] = 1;
    lld(&buff, 0, &champ);
}
