/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** gat_action_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);
int exeption_param(buffer_t *buffer, int coo[2]);
int place_param(char *arena, buffer_t *buffer, int coo[2], int pc);
int get_param(char *arena, buffer_t *buffer, int pc);

Test(gat_action_tests, test_exeption_param, .init = redirect_all_stdout)
{
    buffer_t buff;
    int coo[2] = {0, 0};

    memset(&buff, 0, sizeof(buffer_t));
    buff.action = 0x0b;
    cr_assert_eq(exeption_param(&buff, coo), 0);
    coo[0] = 1;
    cr_assert_eq(exeption_param(&buff, coo), 0);
    coo[1] = 1;
    cr_assert_eq(exeption_param(&buff, coo), 2);
    buff.action == 0x0a;
    coo[0] = 0;
    cr_assert_eq(exeption_param(&buff, coo), 0);
    coo[0] = 1;
    coo[1] = 0;
    cr_assert_eq(exeption_param(&buff, coo), 0);
    coo[1] = 1;
    cr_assert_eq(exeption_param(&buff, coo), 2);
    buff.action == 0x0e;
    coo[0] = 0;
    cr_assert_eq(exeption_param(&buff, coo), 0);
    coo[0] = 1;
    coo[1] = 0;
    cr_assert_eq(exeption_param(&buff, coo), 0);
    coo[1] = 1;
    cr_assert_eq(exeption_param(&buff, coo), 2);
}

Test(gat_action_tests, test_place_param, .init = redirect_all_stdout)
{
    buffer_t buff;
    int coo[2] = {0, 10};

    memset(&buff, 0, sizeof(buffer_t));
    place_param(0, &buff, coo, 0);
}

Test(gat_action_tests, test_get_param, .init = redirect_all_stdout)
{
    buffer_t buff;
    char *arena = my_strset(MEM_SIZE + 1);

    memset(&buff, 0, sizeof(buffer_t));
    buff.coding_byte = 0b01010101;
    get_param(arena, &buff, 0);
}
