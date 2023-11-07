/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** champions_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void);
void check_is_inf(int i, int j);

Test(champions_tests, check_is_inf_tests, .init = redirect_all_stdout)
{
    vm_t *vm = get_vm(true);

    memset(vm, 0, sizeof(vm_t));
    vm->id_chmp[0] = 1;
    vm->champions = malloc(sizeof(champion_t) * 3);
    check_is_inf(0, 1);
}

Test(champions_tests, put_in_arena_tests, .init = redirect_all_stdout,
.exit_code = 84)
{
    vm_t vm;
    champion_t *champ = malloc(sizeof(champion_t));

    memset(&vm, 0, sizeof(vm_t));
    memset(champ, 0, sizeof(champion_t));
    champ->header = malloc(sizeof(header_t));
    memset(champ->header, 0, sizeof(header_t));
    champ->header->prog_size = endian(99999999);
    vm.nb_champions = 1;
    put_in_arena(champ, &vm, 0);
}

Test(champions_tests, init_champion_tests, .init = redirect_all_stdout,
.exit_code = 84)
{
    int fd = open("tests/errors/too_small.cor", O_RDWR);
    champion_t *champ = malloc(sizeof(champion_t));
    header_t header;

    memset(&header, 0, sizeof(header_t));
    my_strcpy(header.prog_name, "Abel");
    my_strcpy(header.comment, "L'amer noir.");
    header.magic = endian(COREWAR_EXEC_MAGIC);
    header.prog_size = endian(10);
    write(fd, &header, sizeof(header_t));
    close(fd);
    memset(champ, 0, sizeof(champion_t));
    init_champion(champ, "tests/errors/too_small.cor", 0);
}

Test(champions_tests, init_champion_tests2, .init = redirect_all_stdout,
.exit_code = 84)
{
    int fd = open("tests/errors/too_big.cor", O_RDWR);
    champion_t *champ = malloc(sizeof(champion_t));
    header_t header;

    memset(&header, 0, sizeof(header_t));
    my_strcpy(header.prog_name, "Abel");
    my_strcpy(header.comment, "L'amer noir.");
    header.magic = endian(COREWAR_EXEC_MAGIC);
    header.prog_size = endian(100000000);
    write(fd, &header, sizeof(header_t));
    close(fd);
    memset(champ, 0, sizeof(champion_t));
    init_champion(champ, "tests/errors/too_big.cor", 0);
}
