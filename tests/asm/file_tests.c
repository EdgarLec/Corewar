/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** file_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"

void redirect_all_stdout(void);

Test(file_tests, test_free_command, .init = redirect_all_stdout)
{
    commands_t *command = malloc(sizeof(commands_t));

    my_memset(command, 0, sizeof(commands_t));
    command->str = my_strdup("ceciestunestring");
    command->labels[0] = my_strdup("ceciestunlabel");
    free_command(command);
}

Test(file_tests, test_free_file, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));

    my_memset(file, 0, sizeof(file_t));
    file->commands = malloc(sizeof(list_t));
    file->fd = fopen("Makefile", "r");
    free_file(file);
}

Test(file_tests, test_write_and_free, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));

    my_memset(file, 0, sizeof(file_t));
    system("chmod 000 tests/champions/cant_open.s");
    file->dest = my_strdup("tests/champions/cant_open.s");
    file->commands = malloc(sizeof(list_t));
    file->fd = fopen("Makefile", "r");
    write_and_free(file);
    system("chmod 644 tests/champions/cant_open.s");
}
