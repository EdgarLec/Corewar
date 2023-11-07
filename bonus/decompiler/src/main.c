/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "decomp.h"
#include "op.h"

int special_action(buffer_t *command, int i, int type, int action)
{
    if (i > 0 && action == 11 && type == 2)
        return 1;
    if (i < 2 && (action == 10 || action == 14) && type == 2)
        return 1;
    return 0;
}

int get_arg(buffer_t *command, int i, int fd, int action)
{
    int tab[4] = {0xC0, 0x30, 0x0C, 0x03};
    int type = (command->coding_byte & tab[i]) >> (6 - (2 * i));

    if (special_action(command, i, type, action)) {
        write(fd, "%", 1);
        return short_endian(command->ind[i]);
    }
    if (type == 1) {
        dprintf(fd, "r");
        return command->reg[i];
    }
    if (type == 2) {
        write(fd, "%", 1);
        return endian(command->dir[i]);
    }
    if (type == 3)
        return short_endian(command->ind[i]);
    return 0;
}

void write_champ(vm_t *vm, int i)
{
    list_t *start = vm->champions[i].commands;
    buffer_t *command;
    int arg = 0;

    do {
        if (!start || start->data == NULL)
            break;
        command = start->data;
        if (command->action < 1 || command->action > 16) {
            dprintf(vm->champions[i].fd, "ERROR\n");
            start = start->next;
            continue;
        }
        dprintf(vm->champions[i].fd, "\t%s ", cmd_names[command->action - 1]);
        for (int j = 0; j < op_tab[command->action - 1].nbr_args; j++) {
            if (command->action != 1 && command->action != 9 &&
            command->action != 12 && command->action != 15)
                arg = get_arg(command, j, vm->champions[i].fd, command->action);
            else {
                write(vm->champions[i].fd, "%", 1);
                arg = command->action == 1 ? endian(command->dir[j]) : short_endian(command->ind[j]);
            }
            dprintf(vm->champions[i].fd, "%i",arg);
            if (j + 1 < op_tab[command->action - 1].nbr_args)
                dprintf(vm->champions[i].fd, ", ");
        }
        dprintf(vm->champions[i].fd, "\n");
        start = start->next;
    } while (start != vm->champions[i].commands);
}

void write_header(vm_t *vm, int i)
{
    champion_t *champ = &vm->champions[i];

    dprintf(champ->fd, "\t.name \"%s\"\n", champ->header->prog_name);
    dprintf(champ->fd, "\t.comment \"%s\"\n\n", champ->header->comment);
}

void decomp_champ(vm_t *vm, int i)
{
    int size = endian(vm->champions[i].header->prog_size);
    int fd = 0;

    while (vm->champions[i].pc < size) {
        buffer_t *new_buff = malloc(sizeof(buffer_t));
        append_node(&vm->champions[i].commands, new_buff);
        vm->champions[i].pc += get_action(vm->champions[i].prog,
        vm->champions[i].commands->prev->data, vm->champions[i].pc);
    }
    write_header(vm, i);
    write_champ(vm, i);
}

int main(int ac, char **av)
{
    vm_t *vm = get_vm(true);

    stock_champions(vm, av, ac);
    vm->buffer = supaloc(sizeof(buffer_t) * vm->nb_champions);
    for (int i = 0; i < vm->nb_champions; i++)
        memset(&vm->buffer[i], 0, sizeof(buffer_t));
    for (int i = 0; i < vm->nb_champions; i++)
        decomp_champ(vm, i);
    supexit(recup(), 0);
}
