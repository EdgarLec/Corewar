/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** loop_ld_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);

Test(loop_ld_tests, test_loop_ld, .init = redirect_all_stdout)
{
    vm_t vm;
    buffer_t buff;
    champion_t champ;

    memset(&vm, 0, sizeof(vm_t));
    memset(&buff, 0, sizeof(buffer_t));
    memset(&champ, 0, sizeof(champion_t));
    champ.pc = -1;
    vm.arena = my_strset(MEM_SIZE + 1);
    loop_ld(&buff, &vm, &champ, vm.arena);
}

Test(loop_ld_tests, test_loop_lld, .init = redirect_all_stdout)
{
    vm_t vm;
    buffer_t buff;
    champion_t champ;

    memset(&vm, 0, sizeof(vm_t));
    memset(&buff, 0, sizeof(buffer_t));
    memset(&champ, 0, sizeof(champion_t));
    champ.pc = -1;
    vm.arena = my_strset(MEM_SIZE + 1);
    loop_lld(&buff, &vm, &champ, vm.arena);
}
