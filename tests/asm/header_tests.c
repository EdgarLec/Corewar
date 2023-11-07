/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** parse_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(header_tests, test_double_name, .init = redirect_all_stdout)
{
    parse_file("tests/errors/db_name.s");
    cr_assert_eq(error(-1), 1);
}

Test(header_tests, test_no_name, .init = redirect_all_stdout)
{
    parse_file("tests/errors/no_name.s");
    cr_assert_eq(error(-1), 1);
}

Test(header_tests, test_too_much_name, .init = redirect_all_stdout)
{
    parse_file("tests/errors/too_much_name.s");
    cr_assert_eq(error(-1), 1);
}

Test(header_tests, test_double_comment, .init = redirect_all_stdout)
{
    parse_file("tests/errors/db_comment.s");
    cr_assert_eq(error(-1), 1);
}

Test(header_tests, test_no_comment, .init = redirect_all_stdout)
{
    parse_file("tests/errors/no_comment.s");
    cr_assert_eq(error(-1), 1);
}

Test(header_tests, test_too_much_comment, .init = redirect_all_stdout)
{
    parse_file("tests/errors/too_much_comment.s");
    cr_assert_eq(error(-1), 1);
}

