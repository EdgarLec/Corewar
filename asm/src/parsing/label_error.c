/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** label_error
*/

#include "asm.h"

int label_error(file_t *file, char *str)
{
    list_t *start = file->labels;
    commands_t *label;

    do {
        if (!start || start->data == NULL)
            break;
        label = start->data;
        if (!my_strcmp(str, label->str))
            return error(1);
        start = start->next;
    } while (start != file->labels);
    return 0;
}

int check_label(file_t *file, char *line)
{
    int end = -2;
    char *label;

    for (int i = 0; line[i]; i++) {
        if (line[i] == LABEL_CHAR) {
            end = i;
            break;
        }
    }
    for (int i = 0; i < end; i++) {
        if (!is_in_str(line[i], LABEL_CHARS))
            return -1;
    }
    if (end >= 0) {
        label = my_strndup(line, end);
        if (label_error(file, label))
            end = -1;
        free(label);
    }
    return end;
}
