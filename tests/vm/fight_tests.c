/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** fight_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

void tmp_main(int ac, char **av)
{
    vm_t *vm = get_vm(true);
    int nb_start_champ;

    vm->arena = init_arena();
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->nb_live = 0;
    vm->cycle_counter = 0;
    vm->nb_cycle_dump = -1;
    for (int i = 0; i != 4; i++)
        vm->id_chmp[i] = 0;
    stock_champions(vm, av, ac);
    fix_chmp_order();
    vm->buffer = supaloc(sizeof(buffer_t) * vm->nb_champions);
    for (int i = 0; i < vm->nb_champions;
    vm->buffer[i].action = 0, vm->buffer[i].to_do = 0, i++);
    nb_start_champ = vm->nb_champions;
    corewar_loop(vm, nb_start_champ);
}

Test(fight_tests, champion_battles, .init = redirect_all_stdout)
{
    char **fight1 = my_str_to_word_array
    ("""./corewar -dump 2000 tests/result/pdd.cor"""
    """ bonus/tests_champ/results/42.cor""", " ");
    char **fight2 = my_str_to_word_array("""./corewar -n 1 bonus/tests_champ/"""
    """results/_.cor -a 4000 bonus/tests_champ/results/loose.cor""", " ");

    tmp_main(5, fight1);
    tmp_main(7, fight2);
}

Test(fight_tests, error_input1, .init = redirect_all_stdout, .exit_code = 84)
{
    char **fight = my_str_to_word_array
    ("""./corewar -dump -2 tests/result/pdd.cor"""
    """ bonus/tests_champ/results/42.cor""", " ");

    tmp_main(5, fight);
}

Test(fight_tests, error_input2, .init = redirect_all_stdout, .exit_code = 84)
{
    char **fight = my_str_to_word_array("""./corewar -a 0 bonus/tests_champ/"""
    """results/_.cor -a 0 bonus/tests_champ/results/loose.cor""", " ");

    tmp_main(7, fight);
}

Test(fight_tests, error_input3, .init = redirect_all_stdout, .exit_code = 84)
{
    char **fight = my_str_to_word_array("""./corewar -n 7 bonus/tests_champ/"""
    """results/_.cor -a 0 bonus/tests_champ/results/loose.cor""", " ");

    tmp_main(7, fight);
}

Test(fight_tests, error_input4, .init = redirect_all_stdout)
{
    char **fight = my_str_to_word_array("""./corewar -n 1 -a 2000 """
    """bonus/tests_champ/"""
    """results/_.cor bonus/tests_champ/results/loose.cor""", " ");

    tmp_main(7, fight);
}

Test(fight_tests, error_input5, .init = redirect_all_stdout, .exit_code = 84)
{
    char **fight = my_str_to_word_array("""./corewar """
    """bonus/tests_champ/"""
    """results/_.cor bonus/tests_champ/results/loose.cor -n 1 -a 2000 """, " ");

    tmp_main(7, fight);
}

Test(fight_tests, error_input6, .init = redirect_all_stdout, .exit_code = 84)
{
    char **fight = my_str_to_word_array("""./corewar """
    """bonus/tests_champ/"""
    """results/_.cor bonus/tests_champ/results/loose.cor -a 2000 -n 1 """, " ");

    tmp_main(7, fight);
}

Test(fight_tests, error_input7, .init = redirect_all_stdout, .exit_code = 84)
{
    char **fight = my_str_to_word_array("""./corewar -a 2000 -n 1 """
    """bonus/tests_champ/"""
    """results/_.cor bonus/tests_champ/results/loose.cor""", " ");

    tmp_main(7, fight);
}

Test(fight_tests, error_input8, .init = redirect_all_stdout, .exit_code = 84)
{
    char **fight = my_str_to_word_array("""./corewar -a -2000 -n 1 """
    """bonus/tests_champ/"""
    """results/_.cor bonus/tests_champ/results/loose.cor""", " ");

    tmp_main(7, fight);
}

Test(fight_tests, error_input9, .init = redirect_all_stdout, .exit_code = 84)
{
    char **fight = my_str_to_word_array("""./corewar -n 1 """
    """bonus/tests_champ/"""
    """results/_.cor -a 0 bonus/tests_champ/results/loose.cor""", " ");

    tmp_main(7, fight);
}

Test(fight_tests, error_input10, .init = redirect_all_stdout, .exit_code = 84)
{
    char **fight = my_str_to_word_array("""./corewar -n 1 -a -1 """
    """bonus/tests_champ/"""
    """results/_.cor -a 0 bonus/tests_champ/results/loose.cor""", " ");

    tmp_main(7, fight);
}

Test(fight_tests, error_input11, .init = redirect_all_stdout, .exit_code = 84)
{
    char **fight = my_str_to_word_array("""./corewar -a 0 -g e """
    """bonus/tests_champ/"""
    """results/_.cor -a 0 bonus/tests_champ/results/loose.cor""", " ");

    tmp_main(7, fight);
}

Test(fight_tests, error_input12, .init = redirect_all_stdout, .exit_code = 84)
{
    char **fight = my_str_to_word_array("""./corewar -a 0 -n 0 """
    """bonus/tests_champ/"""
    """results/_.cor -a 0 bonus/tests_champ/results/loose.cor""", " ");

    tmp_main(9, fight);
}

Test(fight_tests, error_input13, .init = redirect_all_stdout, .exit_code = 84)
{
    char **fight = my_str_to_word_array("""./corewar -a 0 -n 6 """
    """bonus/tests_champ/"""
    """results/_.cor -a 0 bonus/tests_champ/results/loose.cor""", " ");

    tmp_main(9, fight);
}

Test(fight_tests, usage_test, .init = redirect_all_stdout, .exit_code = 84)
{
    char **fight = my_str_to_word_array("./corewar", " ");

    tmp_main(1, fight);
}
