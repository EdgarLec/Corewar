/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** header_unit_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"

void redirect_all_stdout(void);
int name_error(file_t *file, char **split, int len, int nb);
int comment_error(file_t *file, char **split, int len, int nb);

Test(header_unit_tests, test_name_error, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));
    char **split = my_str_to_word_array("split aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"""
    """aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"""
    """aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", " ");
    char **split2 = my_str_to_word_array("split", " ");

    my_memset(file, 0, sizeof(file_t));
    file->file_src = "oui";
    cr_assert_eq(name_error(file, split, 0, 0), 1);
    cr_assert_eq(name_error(file, split2, 0, 0), 0);
}

Test(header_unit_tests, test_name_setter, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));

    my_memset(file, 0, sizeof(file_t));
    file->file_src = "oui";
    name_setter(file, ".name \"\"", 0);
}

Test(header_unit_tests, test_comment_error, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));
    char **split = my_str_to_word_array("split a", " ");
    char *str = """aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"""
    """aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"""
    """aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa""";
    char **split2 = my_str_to_word_array("split", " ");

    my_memset(file, 0, sizeof(file_t));
    file->file_src = "oui";
    split[1] = malloc(sizeof(char) * 4100);
    for (int i = 0; i < 30; i++)
        my_strcat(split[1], str);
    cr_assert_eq(comment_error(file, split, 0, 0), 1);
    cr_assert_eq(comment_error(file, split2, 0, 0), 0);
}

Test(header_unit_tests, test_comment_setter, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));

    my_memset(file, 0, sizeof(file_t));
    file->file_src = "oui";
    comment_setter(file, ".comment \"\"", 0);
}
