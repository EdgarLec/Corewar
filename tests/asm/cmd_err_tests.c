/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** cmd_err_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"

void redirect_all_stdout(void);

Test(cmd_err_tests, missing_param, .init = redirect_all_stdout)
{
    parse_file("tests/errors/missing_param.s");
    cr_assert_eq(error(-1), 1);
}

Test(cmd_err_tests, too_much_param, .init = redirect_all_stdout)
{
    parse_file("tests/errors/too_much_param.s");
    cr_assert_eq(error(-1), 1);
}

Test(cmd_err_tests, wrong_param1, .init = redirect_all_stdout)
{
    parse_file("tests/errors/wrong_param1.s");
    cr_assert_eq(error(-1), 1);
}

Test(cmd_err_tests, wrong_param2, .init = redirect_all_stdout)
{
    parse_file("tests/errors/wrong_param2.s");
    cr_assert_eq(error(-1), 1);
}

Test(cmd_err_tests, wrong_param3, .init = redirect_all_stdout)
{
    parse_file("tests/errors/wrong_param3.s");
    cr_assert_eq(error(-1), 1);
}
