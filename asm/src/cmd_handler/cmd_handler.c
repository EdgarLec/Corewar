/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** cmd_handler
*/

#include "asm.h"

char **get_args(char *line, char *name)
{
    int index = my_strstr(line, name);

    if (index == -1)
        return NULL;
    index += my_strlen(name);
    return my_str_to_word_array(line + index, ", \t");
}

void init_command(commands_t *new_command, op_t cmd)
{
    char tmp = 0;
    int tab[4] = {0xC0, 0x30, 0x0C, 0x03};

    new_command->coding_byte = 0;
    if (cmd.code == 1 || cmd.code == 9 || cmd.code == 12 || cmd.code == 15)
        return;
    for (int i = 0; i < cmd.nbr_args; i++) {
        tmp = C_BYTE(new_command->param_types[i]);
        tmp <<= (6 - (i * 2));
        tmp &= tab[i];
        new_command->coding_byte |= tmp;
    }
}

int find_args(commands_t *new_command, op_t cmd, char **args)
{
    my_memset(new_command, 0, sizeof(commands_t));
    new_command->instruction = cmd.code;
    for (int i = 0, type = 0; (char)i < cmd.nbr_args; i++) {
        type = add_arg(args[i], cmd.type[i], new_command, i);
        if (!type)
            return 1;
    }
    my_free("P", args);
    return 0;
}

void cmd_handler(file_t *file, char *line, int nb, int type)
{
    op_t cmd = op_tab[type];
    commands_t *new_command = malloc(sizeof(commands_t));
    char **args = get_args(line, cmd.mnemonique);

    if (args == NULL)
        return free(new_command);
    if (len_array(args) != cmd.nbr_args) {
        print_error(9, nb + 1, file->file_src);
        my_free("pP", new_command, args);
        return set_error(1);
    }
    if (find_args(new_command, cmd, args))
        return print_error(10, nb + 1, file->file_src);
    init_command(new_command, cmd);
    append_node(&file->commands, new_command);
}
