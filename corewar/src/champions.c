/*
** EPITECH PROJECT, 2022
** champions.c
** File description:
** champions
*/

#include "../include/corewar.h"
#include "../include/vm.h"

void check_is_inf(int i, int j)
{
    long temp;
    vm_t *vm = get_vm(false);
    champion_t temp_chmp;

    if (vm->id_chmp[i] > vm->id_chmp[j]) {
        temp_chmp = vm->champions[i];
        temp = vm->id_chmp[i];
        vm->champions[i] = vm->champions[j];
        vm->id_chmp[i] = vm->id_chmp[j];
        vm->champions[j] = temp_chmp;
        vm->id_chmp[j] = temp;
    }
}

void fix_chmp_order(void)
{
    vm_t *vm = get_vm(false);

    for (int i = 0; i < vm->nb_champions - 1; i++)
        for (int j = i + 1; j < vm->nb_champions; j++)
            check_is_inf(i, j);
}

void put_in_arena(champion_t *chmp, vm_t *vm, long i)
{
    long index_in_arena = chmp->index;

    if (chmp->header->prog_name == NULL || chmp->header->comment == NULL ||
    endian(chmp->header->prog_size) == 0 || endian(chmp->header->prog_size) >
    (MEM_SIZE / vm->nb_champions))
        supexit(recup(), 84);
    if (chmp->index == -1)
        index_in_arena = (i - 1) * (MEM_SIZE / vm->nb_champions);
    chmp->pc = (int)index_in_arena;
    chmp->index = index_in_arena;
    for (int j = 0; j < endian(chmp->header->prog_size); j++) {
        if (vm->arena[index_in_arena % MEM_SIZE] != 0) {
            my_putstr("Overlap detected\n");
            supexit(recup(), 84);
        }
        vm->arena[index_in_arena % MEM_SIZE] = chmp->prog[j];
        index_in_arena++;
    }

}

void init_champion(champion_t *chmp, char *file, long nb)
{
    int fd = open(file, O_RDONLY);
    char c;
    chmp->pc = 0;
    if (fd < 0)
        supexit(recup(), 84);
    for (int i = 0; i < REG_NUMBER; chmp->reg[i] = 0, i++);
    chmp->reg[0] = endian(nb);
    chmp->nb_champion = nb;
    chmp->carry = 0;
    chmp->busy = 0;
    chmp->alive = 1;
    chmp->live = 0;
    chmp->index = -1;
    chmp->header = init_head(fd);
    chmp->prog = supaloc(sizeof(char) * endian(chmp->header->prog_size));
    if (endian(chmp->header->prog_size) != read(fd, chmp->prog, sizeof(char) *
    endian(chmp->header->prog_size)) || 0 < read(fd, &c, sizeof(char))) {
        my_dprintf(2, "vm: error bad progsize.\n");
        supexit(recup(), 84);
    }
}

void stock_champions(vm_t *vm, char **av, int ac)
{
    for (int i = 0; i != 4; i++)
        vm->id_chmp[i] = 0;
    vm->champions = supaloc(sizeof(champion_t) * 4);
    vm->nb_champions = 0;
    arg_handling(ac, av, vm);
}
