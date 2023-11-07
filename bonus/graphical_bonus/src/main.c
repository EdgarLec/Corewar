/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "corewar.h"
#include "op.h"

void exec_action(vm_t *vm, champion_t *champ, buffer_t *buffer)
{
    int (*action[16])(buffer_t *, vm_t *, champion_t*) = {exec_live, exec_ld,
    exec_st, exec_add_bit, exec_sub_bit, exec_and_bit, exec_or_bit,
    exec_xor_bit, exec_zjmp, exec_ldi, exec_sti, exec_my_fork, exec_lld,
    exec_lldi, exec_my_lfork, exec_aff};

    if (buffer->to_do != 1 || buffer->action < 1 || buffer->action > 0x10)
        return;
    action[buffer->action - 1](buffer, vm, champ);
}

void verif_action(vm_t *vm, champion_t *champ, buffer_t *buffer)
{
    int (*action[16])(buffer_t *, vm_t *, champion_t*) = {live, my_ld, my_st,
    add_bit, sub_bit, and_bit, or_bit, xor_bit, zjmp, ldi, sti, my_fork, lld,
    lldi, my_lfork, aff};

    if (buffer->action < 1 || buffer->action > 0x10) {
        buffer->to_do = 0;
        champ->pc -= buffer->size - 1;
        return;
    }
    if (action[buffer->action - 1](buffer, vm, champ) == 1) {
        buffer->to_do = 0;
        champ->pc -= buffer->size - 1;
    } else {
        buffer->to_do = 1;
        champ->busy--;
    }
}

int champ_loop(int i, vm_t *vm, buffer_t *buffer)
{
    if (vm->champions[i].alive == 0)
        return 1;
    vm->champions[i].pc %= MEM_SIZE;
    if (vm->champions[i].busy <= 0) {
        if (buffer->to_do == 1) {
            exec_action(vm, &vm->champions[i], buffer);
            buffer = &vm->buffer[i];
            buffer->to_do = 0;
        } else {
            vm->champions[i].pc += get_action(vm->arena, buffer
            , vm->champions[i].pc);
            verif_action(vm, &vm->champions[i], buffer);
        }
    }
    vm->champions[i].busy--;
    return 0;
}

void corewar_loop(vm_t *vm, int nb_champs, WINDOW *ncurses)
{
    for (int count_cycle = 0, alive = nb_champs; !try_print_dump(vm);
         vm->cycle_counter++) {
        if (refresh_ncurses(ncurses, vm, 0) == 1) {
            vm->cycle_counter--;
            continue;
        }
        for (int i = 0; i < vm->nb_champions; i++)
            champ_loop(i, vm, &vm->buffer[i]);
        if (count_cycle > vm->cycle_to_die) {
            alive = check_champs_alive(vm, nb_champs);
            count_cycle %= vm->cycle_to_die;
        }
        if (alive <= 1)
            break;
        count_cycle++;
        if (vm->nb_live >= NBR_LIVE) {
            vm->nb_live = 0;
            vm->cycle_to_die -= CYCLE_DELTA;
        }
    }
}

int main(int ac, char **av)
{
    vm_t *vm = get_vm(true);
    int nb_start_champ;
    WINDOW *ncurses = NULL;

    init_vm_values(vm);
    stock_champions(vm, av, ac);
    fix_chmp_order();
    vm->buffer = supaloc(sizeof(buffer_t) * vm->nb_champions);
    for (int i = 0; i < vm->nb_champions;
         vm->buffer[i].action = 0, vm->buffer[i].to_do = 0, i++);
    nb_start_champ = vm->nb_champions;
    ncurses = init_ncurses(vm);
    corewar_loop(vm, nb_start_champ, ncurses);
    process_end_ncurses(ncurses, vm);
    my_dprintf(1, "Le joueur %i (%s) a gagné.\n",
    vm->last_alive + 1, vm->champions[vm->last_alive].header->prog_name);
    supexit(recup(), 0);
}
