/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** line_parse
*/

#include "asm.h"

int check_open(char *filename, file_t *file)
{
    int len = my_strlen(filename);
    char **last_name;
    int is_dot_s;

    file->file_src = filename;
    file->fd = fopen(filename, "r");
    if (file->fd == NULL) {
        my_dprintf(2, "asm: error while opening: %s.\n", filename);
        return error(1);
    }
    last_name = my_str_to_word_array(filename, "/");
    len = my_strlen(last_name[len_array(last_name) - 1]);
    is_dot_s = (my_strncmp(last_name[len_array(last_name) - 1] + len - 2,
    ".s", 2) == 0);
    file->dest = my_strset(len - is_dot_s + 5);
    my_strncpy(file->dest, last_name[len_array(last_name) - 1], len - is_dot_s);
    my_strcat(file->dest, is_dot_s ? "cor" : ".cor");
    my_free("P", last_name);
    return 0;
}

void set_prog_size(file_t *file)
{
    list_t *start = file->commands;
    commands_t *command;
    int prog_size = 0;

    do {
        if (!start || start->data == NULL)
            break;
        command = start->data;
        prog_size += command->instruction != 0;
        prog_size += command->coding_byte != 0;
        for (int i = 0; command->param_types[i] > 0; i++)
            prog_size += ARG_SIZE(command->c_byte[i]);
        start = start->next;
    } while (start != file->commands);
    file->header->prog_size = endian(prog_size);
}

char **clean_line(file_t *file)
{
    char *new_line;
    char *new_line2;

    for (int i = 0; file->buffer[i]; i++) {
        if (file->buffer[i] == COMMENT_CHAR) {
            new_line = my_strset(i + 2);
            my_strncpy(new_line, file->buffer, i);
            free(file->buffer);
            file->buffer = new_line;
            break;
        }
    }
    for (; file->buffer[0] == ' ' || file->buffer[0] == '\t';) {
        new_line2 = my_strdup(file->buffer + 1);
        free(file->buffer);
        file->buffer = new_line2;
    }
    return my_str_to_word_array(file->buffer, " \t");
}

int parse_line(file_t *file, int i)
{
    int type = -1;
    char **split = clean_line(file);

    for (int j = 0; cmd_names[j] && type == -1; j++)
        type = split[0] && !my_strcmp(split[0], cmd_names[j]) ? j : type;
    my_free("P", split);
    if (type == -1) {
        if (add_label(file, &file->buffer))
            return parse_line(file, i);
        if (!is_empty(file->buffer))
            print_error(1, i + 1, file->file_src);
    } else if (type < 16)
        cmd_handler(file, file->buffer, i, type);
    else
        cmd_setters[type](file, file->buffer, i);
    return error(-1);
}

void parse_file(char *filename)
{
    size_t buff_size = 0;
    file_t *file = malloc(sizeof(file_t));

    my_memset(file, 0, sizeof(file_t));
    file->header = malloc(sizeof(header_t));
    my_memset(file->header, 0, sizeof(header_t));
    file->header->magic = endian(COREWAR_EXEC_MAGIC);
    if (check_open(filename, file))
        return my_free("pp", file->header, file);
    for (int i = 0, size = 1; size > 0 && !error(-1); buff_size = 0, i++) {
        size = getline(&file->buffer, &buff_size, file->fd);
        size > 0 && file->buffer[size - 1] == '\n' ?
        file->buffer[size - 1] = '\0' : 0;
        if (size > 0 && parse_line(file, i))
            return;
        file->buffer ? free(file->buffer) : 0;
    }
    label_loop(file);
    set_prog_size(file);
    !error_in_champ(file) ? write_and_free(file) : free_file(file);
}
