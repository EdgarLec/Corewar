/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** error_unit_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"

void redirect_all_stdout(void);
void verif_label(file_t *file, commands_t *command);

Test(error_unit_tests, test_verif_label, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));
    commands_t *command = malloc(sizeof(commands_t));

    my_memset(file, 0, sizeof(file_t));
    my_memset(command, 0, sizeof(commands_t));
    file->file_src = "src";
    command->param_types[0] = T_IND;
    command->labels[0] = my_strdup("label");
    verif_label(file, command);
}

Test(error_unit_tests, test_err_in_champ, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));
    commands_t *command = malloc(sizeof(commands_t));

    my_memset(file, 0, sizeof(file_t));
    error(0);
    file->file_src = "src";
    error_in_champ(file);
    error(0);
    file->found[0] = 1;
    error_in_champ(file);
    file->found[1] = 1;
    error(0);
    error_in_champ(file);
    file->commands = malloc(sizeof(file_t));
    error_in_champ(file);
    command->param_types[0] = T_IND;
    command->labels[0] = my_strdup("label");
    file->commands->data = command;
    error_in_champ(file);
}
