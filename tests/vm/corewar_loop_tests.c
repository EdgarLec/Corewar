/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** corewar_loop_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);
void exec_action(vm_t *vm, champion_t *champ, buffer_t *buffer);
int champ_loop(int i, vm_t *vm, buffer_t *buffer);

Test(corewar_loop_tests, test_exec_action, .init = redirect_all_stdout)
{
    buffer_t buff;
    int coo[2] = {0, 0};

    memset(&buff, 0, sizeof(buffer_t));
    exec_action(0, 0, &buff);
    buff.to_do = 1;
    exec_action(0, 0, &buff);
    buff.action = 0x12;
    exec_action(0, 0, &buff);
}

Test(corewar_loop_tests, test_champ_loop, .init = redirect_all_stdout)
{
    vm_t vm;

    memset(&vm, 0, sizeof(vm_t));
    vm.champions = malloc(sizeof(champion_t));
    vm.champions[0].alive = 0;
    champ_loop(0, &vm, 0);
}
