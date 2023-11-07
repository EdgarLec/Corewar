/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** champ_tests
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(champ_tests, test_diff_pdd)
{
    parse_file("tests/champions/pdd.s");
    cr_assert_eq(system("diff pdd.cor tests/result/pdd.cor"), 0);
    system("rm -f pdd.cor");
}

Test(champ_tests, test_diff_bill)
{
    parse_file("tests/champions/bill.s");
    cr_assert_eq(system("diff bill.cor tests/result/bill.cor"), 0);
    system("rm -f bill.cor");
}

Test(champ_tests, test_diff_tyron)
{
    parse_file("tests/champions/tyron.s");
    cr_assert_eq(system("diff tyron.cor tests/result/tyron.cor"), 0);
    system("rm -f tyron.cor");
}

Test(champ_tests, test_diff_abel)
{
    parse_file("tests/champions/abel.s");
    cr_assert_eq(system("diff abel.cor tests/result/abel.cor"), 0);
    system("rm -f abel.cor");
}

Test(champ_tests, test_diff_loose)
{
    parse_file("tests/champions/loose.s");
    cr_assert_eq(system("diff loose.cor tests/result/loose.cor"), 0);
    system("rm -f loose.cor");
}
