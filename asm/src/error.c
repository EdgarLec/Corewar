/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** error
*/

#include "asm.h"

void verif_label(file_t *file, commands_t *command)
{
    for (int i = 0; command->param_types[i] > 0; i++) {
        if (command->labels[i]) {
            free(command->labels[i]);
            command->labels[i] = 0;
            my_dprintf(2, "asm: %s: Undefined label.\n", file->file_src);
            return set_error(1);
        }
    }
}

int error_in_champ(file_t *file)
{
    list_t *start = file->commands;

    if (error(-1))
        return 1;
    if (!file->found[1])
        my_dprintf(2, "asm, %s, line 1: Warning: No comment specified.\n",
        file->file_src);
    if (!file->found[0])
        return error(1);
    do {
        if (!start || start->data == NULL)
            break;
        verif_label(file, start->data);
        start = start->next;
    } while (start != file->commands && !error(-1));
    return error(-1);
}

void print_error(int error, int line, char *file)
{
    my_dprintf(2, "asm, %s, line %d: %s\n", file, line, error_str[error]);
    set_error(1);
}

int error(int to_set)
{
    static int error_code = 0;

    if (to_set != -1)
        error_code = to_set;
    return error_code;
}

void set_error(int to_set)
{
    error(to_set);
}
