/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** header
*/

#include "asm.h"

int name_error(file_t *file, char **split, int len, int nb)
{
    if (len > 2) {
        print_error(2, nb + 1, file->file_src);
        my_free("P", split);
        return error(1);
    }
    if (split[1] && my_strlen(split[1]) > PROG_NAME_LENGTH) {
        print_error(3, nb + 1, file->file_src);
        my_free("P", split);
        return error(1);
    }
    if (file->found[0]) {
        print_error(4, nb + 1, file->file_src);
        my_free("P", split);
        return error(1);
    }
    return 0;
}

void name_setter(file_t *file, char *line, int nb)
{
    char **split = my_str_to_word_array(line, "\"");
    int len = len_array(split);
    int nb_quotes = 0;

    for (int i = 0; line[i]; i++) {
        if (line[i] == '"')
            nb_quotes++;
    }
    if (nb_quotes != 2 || name_error(file, split, len, nb)) {
        if (nb_quotes != 2) {
            print_error(2, nb + 1, file->file_src);
            my_free("P", split);
        }
        return set_error(1);
    }
    file->found[0] = 1;
    if (split[1])
        my_strcpy(file->header->prog_name, split[1]);
    my_free("P", split);
}

int comment_error(file_t *file, char **split, int len, int nb)
{
    if (len > 2) {
        print_error(2, nb + 1, file->file_src);
        my_free("P", split);
        return error(1);
    }
    if (split[1] && my_strlen(split[1]) > COMMENT_LENGTH) {
        print_error(7, nb + 1, file->file_src);
        my_free("P", split);
        return error(1);
    }
    if (file->found[1]) {
        print_error(8, nb + 1, file->file_src);
        my_free("P", split);
        return error(1);
    }
    return 0;
}

void comment_setter(file_t *file, char *line, int nb)
{
    char **split = my_str_to_word_array(line, "\"");
    int len = len_array(split);
    int nb_quotes = 0;

    for (int i = 0; line[i]; i++) {
        if (line[i] == '"')
            nb_quotes++;
    }
    if (nb_quotes != 2 || comment_error(file, split, len, nb)) {
        if (nb_quotes != 2) {
            print_error(2, nb + 1, file->file_src);
            my_free("P", split);
        }
        return set_error(1);
    }
    file->found[1] = 1;
    if (split[1])
        my_strcpy(file->header->comment, split[1]);
    my_free("P", split);
}
