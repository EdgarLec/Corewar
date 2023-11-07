/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** fork
*/

#include "corewar.h"
#include "vm.h"

int my_lfork(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    (void)buff;
    (void)vm;
    champ->busy = 1000;
    return 0;
}

int my_fork(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    (void)buff;
    (void)vm;
    champ->busy = 800;
    return 0;
}

int exec_my_lfork(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    champion_t *champ_array;
    buffer_t *new_buffer;

    vm->nb_champions++;
    new_buffer = supaloc(sizeof(buffer_t) * vm->nb_champions);
    champ_array = supaloc(sizeof(champion_t) * vm->nb_champions);
    for (int i = 0; i < vm->nb_champions - 1; i++) {
        my_memcpy(&champ_array[i], &vm->champions[i], sizeof(champion_t));
        new_buffer[i] = vm->buffer[i];
    }
    my_memcpy(&champ_array[vm->nb_champions - 1], champ, sizeof(champion_t));
    my_memcpy(&new_buffer[vm->nb_champions - 1], buff, sizeof(buffer_t));
    change_value_my_lfork(buff, vm, champ, champ_array);
    one_free(vm->champions, recup());
    one_free(vm->buffer, recup());
    vm->champions = champ_array;
    vm->buffer = new_buffer;
    my_memset(&vm->buffer[vm->nb_champions - 1], 0 , sizeof(buffer_t));
    vm->buffer[vm->nb_champions - 1].to_do = 1;
    return 0;
}

int exec_my_fork(buffer_t *buff, vm_t *vm, champion_t *champ)
{
    champion_t *champ_array;
    buffer_t *new_buffer;

    vm->nb_champions++;
    new_buffer = supaloc(sizeof(buffer_t) * vm->nb_champions);
    champ_array = supaloc(sizeof(champion_t) * vm->nb_champions);
    for (int i = 0; i < vm->nb_champions - 1; i++) {
        my_memcpy(&champ_array[i], &vm->champions[i], sizeof(champion_t));
        new_buffer[i] = vm->buffer[i];
    }
    my_memcpy(&champ_array[vm->nb_champions - 1], champ, sizeof(champion_t));
    my_memcpy(&new_buffer[vm->nb_champions - 1], buff, sizeof(buffer_t));
    change_value_my_fork(buff, vm, champ, champ_array);
    one_free(vm->champions, recup());
    one_free(vm->buffer, recup());
    vm->champions = champ_array;
    vm->buffer = new_buffer;
    my_memset(&vm->buffer[vm->nb_champions - 1], 0 , sizeof(buffer_t));
    vm->buffer[vm->nb_champions - 1].to_do = 1;
    return 0;
}
