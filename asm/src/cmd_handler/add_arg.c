/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** add_arg
*/

#include "asm.h"

void add_direct(char *arg, commands_t *command, int i)
{
    if (SPECIAL(command, i))
        command->c_byte[i] = 11;
    if (arg[1] != LABEL_CHAR) {
        if (command->c_byte[i] == 11)
            command->params[i] = short_endian(str_to_long(arg + 1));
        else
            command->params[i] = endian(str_to_long(arg + 1));
        return;
    }
    command->params[i] = 0;
    command->labels[i] = my_strdup(arg + 2);
}

void add_indirect(char *arg, commands_t *command, int i)
{
    if (arg[0] != LABEL_CHAR) {
        command->params[i] = short_endian(str_to_long(arg));
        return;
    }
    command->params[i] = 0;
    command->labels[i] = my_strdup(arg + 1);
}

int add_arg(char *arg, char param_octal, commands_t *command, int i)
{
    if ((param_octal & T_REG) == T_REG && verif_type[0](arg)) {
        command->params[i] = str_to_long(arg + 1);
        command->param_types[i] = T_REG;
        command->c_byte[i] = 1;
        return T_REG;
    }
    if ((param_octal & T_DIR) == T_DIR && verif_type[1](arg)) {
        command->param_types[i] = T_DIR;
        command->c_byte[i] = 10;
        add_direct(arg, command, i);
        return T_DIR;
    }
    if ((param_octal & T_IND) == T_IND && verif_type[2](arg)) {
        command->param_types[i] = T_IND;
        command->c_byte[i] = 11;
        add_indirect(arg, command, i);
        return T_IND;
    }
    free(command);
    return !error(1);
}
