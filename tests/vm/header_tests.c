/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** header_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);

Test(header_tests, init_head_size_tests, .init = redirect_all_stdout,
.exit_code = 84)
{
    init_head(-1);
}

Test(header_tests, init_head_exec_tests, .init = redirect_all_stdout,
.exit_code = 84)
{
    int fd = open("/dev/urandom", O_RDONLY);

    init_head(fd);
    close(fd);
}
