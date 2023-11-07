/*
** EPITECH PROJECT, 2022
** live.c
** File description:
** live
*/

#include "../../include/corewar.h"

void kill_champ(vm_t *vm, int champ_id)
{
    for (int i = 0; i < vm->nb_champions; i++) {
        if (vm->champions[i].nb_champion == champ_id
        && vm->champions[i].live > 0)
            return;
    }
    for (int i = 0; i < vm->nb_champions; i++) {
        if (vm->champions[i].nb_champion == champ_id)
            vm->champions[i].alive = 0;
    }
}

int check_champs_alive(vm_t *vm, int nb_champs)
{
    int alive = 0;

    for (int i = 0; i < vm->nb_champions; i++) {
        if (vm->champions[i].alive == 1 && vm->champions[i].live == 0)
            kill_champ(vm, vm->champions[i].nb_champion);
        vm->champions[i].live = 0;
    }
    for (int i = 0; i < nb_champs; i++) {
        if (vm->champions[i].alive == 1)
            alive++;
    }
    return alive;
}

int try_live(int id_champ, vm_t *vm, champion_t *champ)
{
    int found = 0;

    if (id_champ < 0 || !champ->alive)
        return 0;
    for (int i = 0; i < vm->nb_champions; i++) {
        if (vm->champions[i].nb_champion - 1 == id_champ
        && vm->champions[i].alive) {
            found = 1;
            vm->champions[i].live = true;
        }
    }
    return found;
}

int live(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    (void)buff;
    (void)vm;
    champ->busy = 10;

    return 0;
}

int exec_live(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    int id_champ = endian(buff->dir[0]) - 1;

    if (!try_live(id_champ, vm, champ))
        return 1;
    vm->nb_live++;
    vm->last_alive = id_champ;
    return 0;
}
