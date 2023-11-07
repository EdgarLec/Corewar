/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** cmd_tests
*/

#include <criterion/criterion.h>
#include "asm.h"

char **get_args(char *line, char *name);
void init_command(commands_t *new_command, op_t cmd);
int find_args(commands_t *new_command, op_t cmd, char **args);

Test(cmd_tests, test_get_args)
{
    char **args = get_args("    live %234 \t", "live");
    char **null = get_args("    live %234 \t", "hznnzv");

    cr_assert_str_eq(args[0], "%234");
}

Test(cmd_tests, test_init_command)
{
    commands_t *command = malloc(sizeof(commands_t));

    memset(command, 0, sizeof(commands_t));
    init_command(command, op_tab[0]);
    init_command(command, op_tab[8]);
    init_command(command, op_tab[11]);
    init_command(command, op_tab[14]);
    command->instruction = 3;
    command->param_types[0] = T_REG;
    command->param_types[1] = T_IND;
    command->labels[1] = "label";
    init_command(command, op_tab[2]);
    command->instruction = 2;
    init_command(command, op_tab[1]);
    command->instruction = 11;
    command->param_types[2] = T_DIR;
    init_command(command, op_tab[10]);
    cr_assert_eq(command->coding_byte, 120);
    command->param_types[1] = T_IND;
    command->params[1] = -999;
    init_command(command, op_tab[10]);
    command->labels[1] = 0;
    init_command(command, op_tab[10]);
    cr_assert_eq(command->coding_byte, 120);
    command->param_types[1] = T_DIR;
    init_command(command, op_tab[10]);
    cr_assert_eq(command->coding_byte, 104);
}

Test(cmd_tests, test_find_args)
{
    commands_t *command = malloc(sizeof(commands_t));
    char **args = get_args("    ldi %234, r2, r1\t", "ldi");

    find_args(command, op_tab[9], args);
    cr_assert_eq(command->param_types[0], T_DIR);
    cr_assert_eq(command->param_types[1], T_REG);
    cr_assert_eq(command->param_types[2], T_REG);
    cr_assert_eq(command->params[0], short_endian(234));
    cr_assert_eq(command->params[1], 2);
    cr_assert_eq(command->params[2], 1);
    cr_assert_eq(find_args(command, op_tab[9],
    get_args("    ldi %234, r2, %2\t", "ldi")), 1);
    find_args(command, op_tab[10], get_args("    sti r1, %234, %2\t", "sti"));
    find_args(command, op_tab[8], get_args("    zjmp %2\t", "zjmp"));
    find_args(command, op_tab[13], get_args("    lldi %234, r2, %2\t", "lldi"));
    find_args(command, op_tab[0], get_args("    live %234", "live"));
}

Test(cmd_tests, test_cmd_handler)
{
    file_t *file = malloc(sizeof(file_t));

    cmd_handler(file, "starz r1", 1, 10);
}
