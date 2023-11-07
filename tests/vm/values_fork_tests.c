/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** values_fork_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);

Test(values_fork_tests, change_value_my_fork_tests, .init = redirect_all_stdout)
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
    change_value_my_fork(&buff, &vm, &champ, (champion_t *)vm.arena);
    change_value_my_lfork(&buff, &vm, &champ, (champion_t *)vm.arena);
}
