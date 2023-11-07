/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** arg_n_handling_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);

Test(arg_n_handling_tests, check_second_arg_with_n_tests,
.init = redirect_all_stdout, .exit_code = 84)
{
    char *av[] = {"-azer", NULL};
    int i = 0;

    check_second_arg_with_n(0, av, 0, &i);
}

Test(arg_n_handling_tests, check_second_arg_with_n_tests2,
.init = redirect_all_stdout, .exit_code = 84)
{
    char *av[] = {"-e", NULL};
    int i = 0;

    check_second_arg_with_n(0, av, 0, &i);
}

Test(arg_n_handling_tests, n_second_flag_tests,
.init = redirect_all_stdout, .exit_code = 84)
{
    char *av[] = {"-e", NULL};
    int i = 1;

    n_second_flag(0, av, 0, &i);
}

Test(arg_n_handling_tests, n_second_flag_tests2,
.init = redirect_all_stdout, .exit_code = 84)
{
    vm_t *vm = get_vm(true);
    char *av[] = {"-n", "0", NULL};
    int i = 1;

    memset(vm, 0, sizeof(vm_t));
    n_second_flag(3, av, 0, &i);
}

Test(arg_n_handling_tests, n_second_flag_tests3,
.init = redirect_all_stdout, .exit_code = 84)
{
    vm_t *vm = get_vm(true);
    char **av = my_str_to_word_array("-n 2", " ");
    int i = 0;
    short nb = 0;

    memset(vm, 0, sizeof(vm_t));
    n_second_flag(3, av, &nb, &i);
}

Test(arg_n_handling_tests, n_first_flag_tests,
.init = redirect_all_stdout, .exit_code = 84)
{
    vm_t *vm = get_vm(true);
    char **av = my_str_to_word_array("-n 2", " ");
    int i = 0;
    short nb = 0;

    memset(vm, 0, sizeof(vm_t));
    n_first_flag(0, av, &nb, &i);
}

Test(arg_n_handling_tests, n_first_flag_tests2,
.init = redirect_all_stdout, .exit_code = 84)
{
    vm_t *vm = get_vm(true);
    char **av = my_str_to_word_array("azeae", " ");
    int i = 0;
    short nb = 0;

    memset(vm, 0, sizeof(vm_t));
    n_first_flag(2, av, &nb, &i);
}

Test(arg_n_handling_tests, n_first_flag_tests3,
.init = redirect_all_stdout, .exit_code = 84)
{
    vm_t *vm = get_vm(true);
    char *av[] = {"-n", "0", NULL};
    int i = 0;
    short nb = 0;

    memset(vm, 0, sizeof(vm_t));
    n_first_flag(3, av, &nb, &i);
}

Test(arg_n_handling_tests, n_first_flag_tests4,
.init = redirect_all_stdout, .exit_code = 84)
{
    vm_t *vm = get_vm(true);
    char *av[] = {"-n", "5", NULL};
    int i = 0;
    short nb = 0;

    memset(vm, 0, sizeof(vm_t));
    n_first_flag(3, av, &nb, &i);
}

Test(arg_n_handling_tests, n_first_flag_tests5,
.init = redirect_all_stdout, .exit_code = 84)
{
    vm_t *vm = get_vm(true);
    char **av = my_str_to_word_array("-n 2", " ");
    int i = 0;
    short nb = 0;

    memset(vm, 0, sizeof(vm_t));
    n_first_flag(3, av, &nb, &i);
}

Test(arg_n_handling_tests, n_first_flag_tests6,
.init = redirect_all_stdout, .exit_code = 84)
{
    vm_t *vm = get_vm(true);
    char **av = my_str_to_word_array("-n 2", " ");
    int i = 0;
    short nb = 0;

    memset(vm, 0, sizeof(vm_t));
    n_first_flag(2, av, &nb, &i);
}
