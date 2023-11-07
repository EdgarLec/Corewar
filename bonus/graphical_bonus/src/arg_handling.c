/*
** EPITECH PROJECT, 2022
** arg_handling.c
** File description:
** arg handling
*/

#include "../include/corewar.h"

void init_and_update_id_and_reg(char *const *av, const short *nb_chmp,
const int *i)
{
    init_champion(&get_vm(false)->champions[(*nb_chmp)], av[(*i)],
    get_vm(false)->id_chmp[(*nb_chmp)]);
    get_vm(false)->champions[(*nb_chmp)].nb_champion =
    get_vm(false)->id_chmp[(*nb_chmp)];
    get_vm(false)->champions[(*nb_chmp)].reg[0] =
    endian(get_vm(false)->id_chmp[(*nb_chmp)]);
    get_vm(false)->nb_champions++;
}

void flags(int ac, char *const *av, short *nb_chmp, int *i)
{
    if (av[(*i)][1] == 'n' && my_strlen(av[(*i)]) == 2) {
        n_first_flag(ac, av, nb_chmp, i);
        return;
    } else if (av[(*i)][1] == 'a' && my_strlen(av[(*i)]) == 2) {
        a_first_flag(ac, av, nb_chmp, i);
        return;
    }
    if (my_strcmp(av[(*i)], "-dump") == 0) {
        get_vm(false)->nb_cycle_dump = str_to_long(av[(*i) + 1]);
        (*i) += 1;
    } else
        supexit(recup(), 84);
}

bool check_id_already_claim(vm_t *vm, short id, int nb_chmp)
{
    for (int i = 0; i < nb_chmp; i++) {
        if (vm->id_chmp[i] == id) {
            return true;
        }
    }
    return false;
}

void set_new_chmp_id(vm_t *vm, short nb_chmp)
{
    short new_id_chmp = 1;

    for (int i = 0; i != nb_chmp; i++) {
        if (vm->id_chmp[i])
            continue;
        if (check_id_already_claim(vm, new_id_chmp, nb_chmp)) {
            new_id_chmp++;
            i--;
        } else {
            vm->id_chmp[i] = new_id_chmp;
            vm->champions[i].nb_champion = new_id_chmp;
            vm->champions[i].reg[0] = endian(new_id_chmp);
            new_id_chmp++;
        }
    }
}

void arg_handling(int ac, char **av, vm_t *vm)
{
    short nb_chmp = 0;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-') {
            flags(ac, av, &nb_chmp, &i);
        } else {
            init_champion(&vm->champions[nb_chmp], av[i],
            vm->id_chmp[nb_chmp]);
            vm->nb_champions++;
            nb_chmp++;
        }
    }
    set_new_chmp_id(vm, nb_chmp);
    for (int i = 0; i != vm->nb_champions; i++)
        put_in_arena(&vm->champions[i], vm, vm->id_chmp[i]);
    if (nb_chmp < 2) {
        my_dprintf(2, """Usage: ./corewar [-g] [-dump cycle_nb] [[-a """
        """load_addr] [-n prog_nb] prog.cor] ...\n""");
        supexit(recup(), 84);
    }
}
