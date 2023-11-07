/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** line_tests
*/

#include <criterion/criterion.h>
#include "asm.h"

void redirect_all_stdout(void);
void set_prog_size(file_t *file);
char **clean_line(file_t *file);
int parse_line(file_t *file, int i);

Test(line_tests, test_direct_type, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));

    my_memset(file, 0, sizeof(file_t));
    file->header = malloc(sizeof(header_t));
    my_memset(file->header, 0, sizeof(header_t));
    file->header->magic = endian(COREWAR_EXEC_MAGIC);
    cr_assert_eq(check_open("tests/champions/pdd.s", file), 0);
    system("mv tests/champions/pdd.s tests/champions/pd");
    cr_assert_eq(check_open("tests/champions/pd", file), 0);
    system("mv tests/champions/pd tests/champions/pdd.s");
    cr_assert_eq(check_open("tests/champions/pd.s", file), 1);
}

Test(line_tests, test_prog_size)
{
    file_t *file = malloc(sizeof(file_t));

    my_memset(file, 0, sizeof(file_t));
    file->header = malloc(sizeof(header_t));
    my_memset(file->header, 0, sizeof(header_t));
    file->header->magic = endian(COREWAR_EXEC_MAGIC);
    set_prog_size(file);
    file->commands = malloc(sizeof(list_t *));
    my_memset(file->commands, 0, sizeof(list_t));
    set_prog_size(file);
    free(file->commands);
    file->commands = 0;
    cmd_handler(file, "ldi %234, r2, %2", 0, 10);
}

Test(line_tests, test_clean_line)
{
    file_t *file = malloc(sizeof(file_t));
    char **cleaned;

    my_memset(file, 0, sizeof(file_t));
    file->buffer = my_strdup("    live %234 \t #just a comment");
    cleaned = clean_line(file);
    cr_assert_str_eq(cleaned[0], "live");
    cr_assert_str_eq(cleaned[1], "%234");
}

Test(line_tests, test_parse_line, .init = redirect_all_stdout)
{
    file_t *file = malloc(sizeof(file_t));
    char **cleaned;

    my_memset(file, 0, sizeof(file_t));
    file->header = malloc(sizeof(header_t));
    my_memset(file->header, 0, sizeof(header_t));
    file->header->magic = endian(COREWAR_EXEC_MAGIC);
    check_open("tests/champions/pdd.s", file);
    file->buffer = my_strdup("ùùùù");
    parse_line(file, 0);
}

Test(line_tests, test_parse_file, .init = redirect_all_stdout)
{
    system("chmod 000 tests/champions/abel.s");
    parse_file("tests/champions/abel.s");
    system("chmod 644 tests/champions/abel.s");
    fopen("tests/champions/empty.s", "r");
    parse_file("tests/champions/empty.s");
}
