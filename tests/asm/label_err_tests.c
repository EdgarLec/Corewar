/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** label_err_tests
*/

#include <criterion/criterion.h>
#include "asm.h"

void redirect_all_stdout(void);

Test(label_err_tests, test_label_error, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));
    char *line = my_strdup("label:");

    my_memset(file, 0, sizeof(file_t));
    cr_assert_eq(label_error(file, "label"), 0);
    file->labels = malloc(sizeof(list_t));
    cr_assert_eq(label_error(file, "label"), 0);
    free(file->labels);
    file->labels = 0;
    add_label(file, &line);
    cr_assert_eq(label_error(file, "label"), 1);
}

Test(label_err_tests, test_check_label, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));
    char *line = my_strdup("label:");

    my_memset(file, 0, sizeof(file_t));
    cr_assert_eq(check_label(file, "labelù:"), -1);
    add_label(file, &line);
    cr_assert_eq(check_label(file, "label:"), -1);
}
