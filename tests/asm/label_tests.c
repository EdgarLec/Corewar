/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** label_tests
*/

#include <criterion/criterion.h>
#include "asm.h"

void redirect_all_stdout(void);
void set_label(file_t *file, commands_t *label);
void add_label_adress(file_t *file, list_t *cmd, int i, commands_t *label);

Test(label_tests, test_add_label_adress, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));
    commands_t *cmd = malloc(sizeof(commands_t));
    commands_t *label = malloc(sizeof(commands_t));

    memset(file, 0, sizeof(file_t));
    memset(cmd, 0, sizeof(commands_t));
    memset(label, 0, sizeof(commands_t));
    file->commands = malloc(sizeof(list_t));
    file->commands->data = cmd;
    cmd->labels[0] = my_strdup("label");
    cmd->instruction = 2;
    cmd->param_types[0] = T_DIR;
    label->params[0] = 0;
    add_label_adress(file, file->commands, 0, label);
    cmd->param_types[0] = T_IND;
    add_label_adress(file, file->commands, 0, label);
    cmd->instruction = 3;
    add_label_adress(file, file->commands, 0, label);
    cmd->c_byte[0] = 10;
    add_label_adress(file, file->commands, 0, label);
}

Test(label_tests, test_set_label, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));

    memset(file, 0, sizeof(file_t));
    set_label(file, NULL);
    file->commands = malloc(sizeof(list_t));
    set_label(file, NULL);
}

Test(label_tests, test_get_label_adress, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));

    memset(file, 0, sizeof(file_t));
    cr_assert_eq(get_label_adress(file, (list_t *)file), 0);
    file->commands = malloc(sizeof(list_t));
    cr_assert_eq(get_label_adress(file, (list_t *)file), 0);
}

Test(label_tests, test_add_label, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));
    char *str = my_strdup(":");

    memset(file, 0, sizeof(file_t));
    cr_assert_eq(add_label(file, &str), 1);
}
