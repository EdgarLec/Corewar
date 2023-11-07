/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** label
*/

#include "asm.h"

void add_label_adress(file_t *file, list_t *cmd, int i, commands_t *label)
{
    commands_t *command = cmd->data;
    int cmd_adress = file->commands->data == command ? 0 :
    get_label_adress(file, cmd);
    int label_adress = label->params[0] - cmd_adress;

    free(command->labels[i]);
    command->labels[i] = 0;
    command->params[i] = command->c_byte[i] == 10 ?
    endian(label_adress) : short_endian(label_adress);
}

void set_label(file_t *file, commands_t *label)
{
    list_t *start = file->commands;
    commands_t *command;

    do {
        if (!start || start->data == NULL)
            break;
        command = start->data;
        for (int i = 0; command->param_types[i] > 0; i++)
            command->labels[i] && !my_strcmp(command->labels[i], label->str) ?
            add_label_adress(file, start, i, label) : 0;
        start = start->next;
    } while (start != file->commands);
}

void label_loop(file_t *file)
{
    commands_t *command;

    while (file->labels) {
        command = file->labels->data;
        set_label(file, command);
        remove_node(&file->labels, 0, free_command);
    }
}

int get_label_adress(file_t *file, list_t *stop)
{
    list_t *start = file->commands;
    commands_t *command;
    int label_adress = 0;

    for (int i = 0; i == 0 || start != stop; start = start->next, i++) {
        if (!start || start->data == NULL)
            break;
        command = start->data;
        label_adress += command->instruction != 0;
        label_adress += command->coding_byte != 0;
        for (int i = 0; command->param_types[i] > 0; i++)
            label_adress += ARG_SIZE(command->c_byte[i]);
    }
    return label_adress;
}

int add_label(file_t *file, char **line)
{
    int is_label = check_label(file, *line);
    char *line_cpy = *line;
    commands_t *new_command;

    if (is_label < 0)
        return 0;
    new_command = malloc(sizeof(commands_t));
    my_memset(new_command, 0, sizeof(commands_t));
    if (is_label > 0)
        new_command->str = my_strndup(*line, is_label);
    *line = my_strdup(*line + is_label + 1);
    if (is_label > 0) {
        new_command->params[0] = get_label_adress(file, file->commands);
        append_node(&file->labels, new_command);
    } else {
        error(1);
        free(new_command);
    }
    free(line_cpy);
    return 1;
}
