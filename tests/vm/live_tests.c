/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** live_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);
int try_live(int id_champ, vm_t *vm, champion_t *champ);

Test(live_tests, test_kill_champ, .init = redirect_all_stdout)
{
    vm_t vm;
    champion_t champ;

    memset(&vm, 0, sizeof(vm_t));
    memset(&champ, 0, sizeof(champion_t));
    vm.champions = malloc(sizeof(champion_t) * 1);
    vm.nb_champions = 1;
    vm.champions[0].live = 1;
    kill_champ(&vm, 0);
}

Test(live_tests, test_try_live, .init = redirect_all_stdout)
{
    vm_t vm;
    champion_t champ;

    memset(&vm, 0, sizeof(vm_t));
    memset(&champ, 0, sizeof(champion_t));
    vm.champions = malloc(sizeof(champion_t) * 2);
    vm.nb_champions = 1;
    vm.champions[0].live = 1;
    vm.champions[0].alive = 0;
    try_live(0, &vm, &vm.champions[0]);
    vm.nb_champions = 2;
    vm.champions[0].alive = 1;
    vm.champions[1].nb_champion = 2;
    try_live(1, &vm, &vm.champions[0]);
}
