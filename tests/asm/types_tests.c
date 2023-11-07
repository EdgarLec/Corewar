/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** types_tests
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(types_tests, test_direct_type)
{
    cr_assert_eq(is_direct("%1"), 1);
    cr_assert_eq(is_direct("%-24"), 1);
    cr_assert_eq(is_direct("%:label"), 1);
    cr_assert_eq(is_direct("%-2-4"), 0);
    cr_assert_eq(is_direct("1"), 0);
    cr_assert_eq(is_direct("r1"), 0);
}

Test(types_tests, test_indirect_type)
{
    cr_assert_eq(is_indirect("1"), 1);
    cr_assert_eq(is_indirect("-24"), 1);
    cr_assert_eq(is_indirect(":label"), 1);
    cr_assert_eq(is_indirect("-2-4"), 0);
    cr_assert_eq(is_indirect(""), 0);
    cr_assert_eq(is_indirect("%2"), 0);
    cr_assert_eq(is_indirect("r1"), 0);
}

Test(types_tests, test_register_type)
{
    cr_assert_eq(is_reg("r1"), 1);
    cr_assert_eq(is_reg("1"), 0);
    cr_assert_eq(is_reg("u1"), 0);
    cr_assert_eq(is_reg("r-1"), 0);
    cr_assert_eq(is_reg("r20"), 0);
    cr_assert_eq(is_reg("notaregister"), 0);
}
