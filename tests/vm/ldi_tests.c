/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** ldi_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);
short loop_ldi(const buffer_t *buff, const vm_t *vm, const champion_t *champ,
short *tmp);
int read_ldi(buffer_t *buff, vm_t *vm, champion_t *champ);

Test(ldi_tests, test_loop_ldi, .init = redirect_all_stdout)
{
    vm_t vm;
    buffer_t buff;
    champion_t champ;

    memset(&vm, 0, sizeof(vm_t));
    memset(&buff, 0, sizeof(buffer_t));
    memset(&champ, 0, sizeof(champion_t));
    champ.pc = -1;
    vm.arena = my_strset(MEM_SIZE + 1);
    loop_ldi(&buff, &vm, &champ, (short *)vm.arena);
}

Test(ldi_tests, test_read_ldi, .init = redirect_all_stdout)
{
    buffer_t buff;
    champion_t champ;

    memset(&buff, 0, sizeof(buffer_t));
    memset(&champ, 0, sizeof(champion_t));
    champ.pc = -1;
    buff.coding_byte = 0b01000000;
    read_ldi(&buff, 0, &champ);
}

Test(ldi_tests, test_ldi, .init = redirect_all_stdout)
{
    vm_t vm;
    buffer_t buff;
    champion_t champ;

    memset(&vm, 0, sizeof(vm_t));
    memset(&buff, 0, sizeof(buffer_t));
    memset(&champ, 0, sizeof(champion_t));
    vm.arena = my_strset(MEM_SIZE + 1);
    champ.pc = -1;
    buff.coding_byte = 0;
    ldi(&buff, &vm, &champ);
    buff.coding_byte = 0b01010100;
    buff.reg[0] = 100;
    buff.reg[1] = 100;
    ldi(&buff, &vm, &champ);
    buff.reg[2] = -1;
    ldi(&buff, &vm, &champ);
    buff.reg[2] = 100;
    ldi(&buff, &vm, &champ);
    buff.reg[2] = 1;
    ldi(&buff, &vm, &champ);
    buff.reg[0] = 1;
    ldi(&buff, &vm, &champ);
    buff.reg[1] = 1;
    ldi(&buff, &vm, &champ);
}

