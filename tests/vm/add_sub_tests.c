/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** add_sub_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);

Test(add_sub_tests, add_bit_tests, .init = redirect_all_stdout)
{
    buffer_t buff;
    champion_t champ;
    int infos[2] = {0, 0};

    memset(&buff, 0, sizeof(buffer_t));
    memset(&champ, 0, sizeof(champion_t));
    buff.coding_byte = 0b01010100;
    buff.reg[0] = -1;
    add_bit(&buff, 0, &champ);
    buff.reg[0] = 100;
    add_bit(&buff, 0, &champ);
    buff.reg[0] = 10;
    buff.reg[1] = -1;
    add_bit(&buff, 0, &champ);
    buff.reg[1] = 100;
    add_bit(&buff, 0, &champ);
    buff.reg[1] = 10;
    buff.reg[2] = -1;
    add_bit(&buff, 0, &champ);
    buff.reg[2] = 100;
    add_bit(&buff, 0, &champ);
}

Test(add_sub_tests, sub_bit_tests, .init = redirect_all_stdout)
{
    buffer_t buff;
    champion_t champ;
    int infos[2] = {0, 0};

    memset(&buff, 0, sizeof(buffer_t));
    memset(&champ, 0, sizeof(champion_t));
    buff.coding_byte = 0b01010100;
    buff.reg[0] = -1;
    sub_bit(&buff, 0, &champ);
    buff.reg[0] = 100;
    sub_bit(&buff, 0, &champ);
    buff.reg[0] = 10;
    buff.reg[1] = -1;
    sub_bit(&buff, 0, &champ);
    buff.reg[1] = 100;
    sub_bit(&buff, 0, &champ);
    buff.reg[1] = 10;
    buff.reg[2] = -1;
    sub_bit(&buff, 0, &champ);
    buff.reg[2] = 100;
    sub_bit(&buff, 0, &champ);
}
