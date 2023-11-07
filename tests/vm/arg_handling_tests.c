/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** arg_handling_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);
void flags(int ac, char *const *av, short *nb_chmp, int *i);

Test(arg_handling_tests, flags_tests, .init = redirect_all_stdout,
.exit_code = 84)
{
    vm_t *vm = get_vm(true);
    char **av = my_str_to_word_array("-na 2", " ");
    int i = 0;
    short nb = 0;

    memset(vm, 0, sizeof(vm_t));
    flags(3, av, &nb, &i);
}

Test(arg_handling_tests, flags_tests2, .init = redirect_all_stdout,
.exit_code = 84)
{
    vm_t *vm = get_vm(true);
    char **av = my_str_to_word_array("-aaaa 2", " ");
    int i = 0;
    short nb = 0;

    memset(vm, 0, sizeof(vm_t));
    flags(3, av, &nb, &i);
}
