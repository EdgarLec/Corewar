/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** bitshift_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);
int find_elem(int info[2], vm_t *vm, buffer_t *buff, champion_t *champ);

Test(bitshift_tests, find_elem_tests, .init = redirect_all_stdout)
{
    vm_t vm;
    buffer_t buff;
    champion_t champ;
    int infos[2] = {0, 0};

    memset(&vm, 0, sizeof(vm_t));
    memset(&buff, 0, sizeof(buffer_t));
    memset(&champ, 0, sizeof(champion_t));
    vm.arena = my_strset(MEM_SIZE + 1);
    champ.pc = -1;
    find_elem(infos, &vm, &buff, &champ);
    buff.coding_byte = 0b10101010;
    find_elem(infos, &vm, &buff, &champ);
    buff.coding_byte = 0b10101011;
    find_elem(infos, &vm, &buff, &champ);
}

Test(bitshift_tests, and_bit_tests, .init = redirect_all_stdout)
{
    buffer_t buff;
    champion_t champ;
    int infos[2] = {0, 0};

    memset(&buff, 0, sizeof(buffer_t));
    memset(&champ, 0, sizeof(champion_t));
    buff.coding_byte = 0b01010100;
    buff.reg[0] = -1;
    and_bit(&buff, 0, &champ);
    buff.reg[0] = 10;
    buff.reg[1] = -1;
    and_bit(&buff, 0, &champ);
    buff.reg[1] = 10;
    buff.reg[2] = -1;
    and_bit(&buff, 0, &champ);
    buff.reg[2] = 10;
    buff.coding_byte = 0b11110100;
    and_bit(&buff, 0, &champ);
    buff.coding_byte = 0b01000100;
    and_bit(&buff, 0, &champ);
}

Test(bitshift_tests, or_bit_tests, .init = redirect_all_stdout)
{
    buffer_t buff;
    champion_t champ;
    int infos[2] = {0, 0};

    memset(&buff, 0, sizeof(buffer_t));
    memset(&champ, 0, sizeof(champion_t));
    buff.coding_byte = 0b01010100;
    buff.reg[0] = -1;
    or_bit(&buff, 0, &champ);
    buff.reg[0] = 10;
    buff.reg[1] = -1;
    or_bit(&buff, 0, &champ);
    buff.reg[1] = 10;
    buff.reg[2] = -1;
    or_bit(&buff, 0, &champ);
    buff.reg[2] = 10;
    buff.coding_byte = 0b11110100;
    or_bit(&buff, 0, &champ);
    buff.coding_byte = 0b01000100;
    or_bit(&buff, 0, &champ);
}

Test(bitshift_tests, xor_bit_tests, .init = redirect_all_stdout)
{
    buffer_t buff;
    champion_t champ;
    int infos[2] = {0, 0};

    memset(&buff, 0, sizeof(buffer_t));
    memset(&champ, 0, sizeof(champion_t));
    buff.coding_byte = 0b01010100;
    buff.reg[0] = -1;
    xor_bit(&buff, 0, &champ);
    buff.reg[0] = 10;
    buff.reg[1] = -1;
    xor_bit(&buff, 0, &champ);
    buff.reg[1] = 10;
    buff.reg[2] = -1;
    xor_bit(&buff, 0, &champ);
    buff.reg[2] = 10;
    buff.coding_byte = 0b11110111;
    xor_bit(&buff, 0, &champ);
    buff.coding_byte = 0b01000100;
    xor_bit(&buff, 0, &champ);
}
