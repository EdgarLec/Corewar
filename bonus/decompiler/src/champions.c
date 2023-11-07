/*
** EPITECH PROJECT, 2022
** champions.c
** File description:
** champions
*/

#include "../include/decomp.h"
#include "../include/vm.h"

void init_champion(champion_t *chmp, char *file, long nb, vm_t *vm)
{
    int fd = open(file, O_RDONLY);
    int is_dot_cor;
    char c;

    if (fd < 0)
        supexit(recup(), 84);
    chmp->header = init_head(fd);
    chmp->prog = supaloc(sizeof(char) * endian(chmp->header->prog_size));
    read(fd, chmp->prog, sizeof(char) * endian(chmp->header->prog_size));
    if (0 < read(fd, &c, sizeof(char))) {
        my_dprintf(2, "vm: error bad progsize.\n");
        supexit(recup(), 84);
    }
    char **last_name = my_str_to_word_array(file, "/");
    int len = my_strlen(last_name[len_array(last_name) - 1]);
    if (len < 5)
        is_dot_cor = 0;
    else
        is_dot_cor = (strncmp(last_name[len_array(last_name) - 1] + len - 4, ".cor", 4) == 0);
    char *dest = my_strset(len - is_dot_cor);
    if (is_dot_cor)
        strncpy(dest, last_name[len_array(last_name) - 1], len - is_dot_cor * 3);
    else
        strcpy(dest, last_name[len_array(last_name) - 1]);
    strcat(dest, is_dot_cor ? "s" : ".s");
    chmp->fd = open(dest, O_RDWR | O_CREAT | O_TRUNC, 0644);
    my_free("Pp", last_name, dest);
}

void stock_champions(vm_t *vm, char **av, int ac)
{
    int size = 0;

    for (int i = 1; i < ac; i++)
        if (av[i][0] != '-')
            size++;
    vm->champions = supaloc(sizeof(champion_t) * size);
    vm->nb_champions = 0;
    arg_handling(ac, av, vm);
}
