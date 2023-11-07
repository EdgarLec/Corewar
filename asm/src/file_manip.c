/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** file_manip
*/

#include "asm.h"

void free_command(void *arg)
{
    commands_t *command = arg;

    if (command->str)
        free(command->str);
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (command->labels[i])
            free(command->labels[i]);
    }
    free(command);
}

void free_file(file_t *file)
{
    if (file->header)
        free(file->header);
    if (file->commands)
        free(file->commands);
    if (file->dest)
        free(file->dest);
    fclose(file->fd);
    free(file);
}

void write_cmds(file_t *file, int fd)
{
    commands_t *command = file->commands->data;

    write(fd, &command->instruction, sizeof(char));
    if (WR_BYTE(command->instruction))
        write(fd, &command->coding_byte, sizeof(char));
    for (int i = 0, size = 0; command->param_types[i] > 0; i++) {
        size = ARG_SIZE(command->c_byte[i]);
        write(fd, &command->params[i], size);
    }
    remove_node(&file->commands, 0, free_command);
}

void write_and_free(file_t *file)
{
    int fd = open(file->dest, O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        my_dprintf(2, "asm: error while opening: %s.\n", file->dest);
        free_file(file);
        return set_error(1);
    }
    write(fd, file->header, sizeof(header_t));
    while (file->commands)
        write_cmds(file, fd);
    free_file(file);
}
