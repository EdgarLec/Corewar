/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** arg_tests
*/

#include <criterion/criterion.h>
#include "asm.h"

void add_direct(char *arg, commands_t *command, int i);
void add_indirect(char *arg, commands_t *command, int i);

void test_special_direct(void)
{
    commands_t *command = malloc(sizeof(commands_t));

    memset(command, 0, sizeof(commands_t));
    command->param_types[0] = T_DIR;
    command->param_types[1] = T_DIR;
    command->param_types[2] = T_IND;
    command->instruction = 9;
    add_direct("%:test", command, 0);
    command->instruction = 12;
    add_direct("%:test", command, 0);
    command->instruction = 15;
    add_direct("%:test", command, 0);
    command->param_types[2] = T_DIR;
    command->instruction = 10;
    add_direct("%:test", command, 0);
    add_direct("%:test", command, 2);
    command->instruction = 14;
    add_direct("%:test", command, 0);
    command->instruction = 11;
    add_direct("%:test", command, 0);
    add_direct("%:test", command, 2);
}

Test(arg_tests, test_add_arg_direct)
{
    commands_t *command = malloc(sizeof(commands_t));

    memset(command, 0, sizeof(commands_t));
    command->instruction = 3;
    add_direct("%12", command, 0);
    cr_assert_eq(command->params[0], endian(12));
    add_direct("%:test", command, 0);
    cr_assert_eq(command->params[0], 0);
    cr_assert_str_eq(command->labels[0], "test");
    command->instruction = 2;
    add_direct("%:test", command, 0);
    command->instruction = 11;
    add_direct("%12", command, 0);
    cr_assert_eq(command->params[0], endian(12));
    command->instruction = 15;
    add_direct("%12", command, 0);
    cr_assert_eq(command->params[0], endian(12));
    test_special_direct();
}

Test(arg_tests, test_add_arg_indirect)
{
    commands_t *command = malloc(sizeof(commands_t));

    memset(command, 0, sizeof(commands_t));
    command->instruction = 1;
    add_indirect("12", command, 0);
    cr_assert_eq(command->params[0], short_endian(12));
    add_indirect(":test", command, 0);
    cr_assert_eq(command->params[0], 0);
    cr_assert_str_eq(command->labels[0], "test");
    command->instruction = 11;
    add_indirect(":test", command, 0);
}

Test(arg_tests, test_add_arg)
{
    commands_t *command = malloc(sizeof(commands_t));

    memset(command, 0, sizeof(commands_t));
    command->instruction = 1;
    add_arg("r1", T_REG, command, 0);
    cr_assert_eq(command->params[0], 1);
    cr_assert_eq(command->param_types[0], T_REG);
    add_arg("%12", T_DIR, command, 0);
    cr_assert_eq(command->params[0], endian(12));
    cr_assert_eq(command->param_types[0], T_DIR);
    add_arg(":test", T_IND, command, 0);
    cr_assert_eq(command->params[0], 0);
    cr_assert_eq(command->param_types[0], T_IND);
    cr_assert_str_eq(command->labels[0], "test");
}

Test(arg_tests, test_err_add_arg)
{
    commands_t *command = malloc(sizeof(commands_t));

    memset(command, 0, sizeof(commands_t));
    command->instruction = 1;
    add_arg("%12", T_REG, command, 0);
    cr_assert_eq(error(-1), 1);
    error(0);
    command = malloc(sizeof(commands_t));
    memset(command, 0, sizeof(commands_t));
    command->instruction = 1;
    add_arg("12", T_DIR, command, 0);
    cr_assert_eq(error(-1), 1);
    error(0);
    command = malloc(sizeof(commands_t));
    memset(command, 0, sizeof(commands_t));
    command->instruction = 1;
    add_arg("r2", T_IND, command, 0);
    cr_assert_eq(error(-1), 1);
    error(0);
}
