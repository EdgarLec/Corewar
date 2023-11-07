/*
** EPITECH PROJECT, 2022
** arg_n_handling.c
** File description:
** arg n handling
*/

#include "corewar.h"

void check_second_arg_with_n(int ac, char *const *av, const short *nb_chmp,
int *i)
{
    if (av[(*i)][0] == '-') {
        if (av[(*i)][1] == 'a' && my_strlen(av[(*i)]) == 2)
            a_second_flag(ac, av, nb_chmp, i);
        else
            supexit(recup(), 84);
    } else
        init_and_update_id_and_reg(av, nb_chmp, i);
}

void n_second_flag(int ac, char *const *av, const short *nb_chmp, int *i)
{
    (*i)++;
    if ((*i) < ac && av[(*i)] != NULL)
        get_vm(false)->id_chmp[(*nb_chmp)] = str_to_long(av[(*i)]);
    else
        supexit(recup(), 84);
    if (get_vm(false)->id_chmp[(*nb_chmp)] > 4 ||
    get_vm(false)->id_chmp[(*nb_chmp)] < 1) {
        my_putstr("Enter a number between 1 and 4.\n");
        supexit(recup(), 84);
    }
    (*i)++;
    if ((*i) < ac && av[(*i)] != NULL)
        init_and_update_id_and_reg(av, nb_chmp, i);
    else
        supexit(recup(), 84);
    (*i) -= 2;
}

void n_first_flag(int ac, char *const *av, short *nb_chmp, int *i)
{
    (*i)++;
    if ((*i) < ac && av[(*i)] != NULL)
        get_vm(false)->id_chmp[(*nb_chmp)] = str_to_long(av[(*i)]);
    else
        supexit(recup(), 84);
    if (get_vm(false)->id_chmp[(*nb_chmp)] > 4 ||
    get_vm(false)->id_chmp[(*nb_chmp)] < 1) {
        my_putstr("Enter a number between 1 and 4.\n");
        supexit(recup(), 84);
    }
    (*i)++;
    if ((*i) < ac && av[(*i)] != NULL)
        check_second_arg_with_n(ac, av, nb_chmp, i);
    else
        supexit(recup(), 84);
    (*nb_chmp)++;
}
