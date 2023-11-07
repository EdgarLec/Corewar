/*
** EPITECH PROJECT, 2022
** arg_a_handling.c
** File description:
** arg a handling
*/

#include "corewar.h"

void a_second_flag(int ac, char *const *av, const short *nb_chmp, int *i)
{
    (*i) += 2;
    if ((*i) < ac && av[(*i)] != NULL)
        init_and_update_id_and_reg(av, nb_chmp, i);
    else
        supexit(recup(), 84);
    if (av[(*i) - 1] != NULL)
        get_vm(false)->champions[(*nb_chmp)].index = str_to_long(av[(*i) - 1]);
    else
        supexit(recup(), 84);
    if (get_vm(false)->champions[(*nb_chmp)].index < 0 ||
    get_vm(false)->champions[(*nb_chmp)].index > 5497835164270591) {
        my_putstr("Enter a valid memory offset.\n");
        supexit(recup(), 84);
    }
}

void check_second_arg_with_a(int ac, char *const *av, const short *nb_chmp,
int *i)
{
    if (av[(*i)][0] == '-') {
        if (av[(*i)][1] == 'n' && my_strlen(av[(*i)]) == 2)
            n_second_flag(ac, av, nb_chmp, i);
        else
            supexit(recup(), 84);
    } else
        init_and_update_id_and_reg(av, nb_chmp, i);
}

void a_first_flag(int ac, char *const *av, short *nb_chmp, int *i)
{
    (*i) += 2;
    if ((*i) < ac && av[(*i)] != NULL)
        check_second_arg_with_a(ac, av, nb_chmp, i);
    else
        supexit(recup(), 84);
    if (av[(*i) - 1] != NULL)
        get_vm(false)->champions[(*nb_chmp)].index = str_to_long(av[(*i) - 1]);
    else
        supexit(recup(), 84);
    if (get_vm(false)->champions[(*nb_chmp)].index < 0 ||
    get_vm(false)->champions[(*nb_chmp)].index > 5497835164270591) {
        my_putstr("Enter a valid memory offset.\n");
        supexit(recup(), 84);
    }
    (*nb_chmp)++;
}
