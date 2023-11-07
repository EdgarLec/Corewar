/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** type_verifiers
*/

#include "asm.h"

int is_direct(char *param)
{
    int label = 0;

    if (my_strlen(param) < 2 || param[0] != DIRECT_CHAR)
        return 0;
    label = param[1] == LABEL_CHAR;
    for (int i = label + 1; param[i]; i++) {
        if (param[i] == '-' && i == label + 1)
            i++;
        if (!is_in_str(param[i], LABEL_CHARS))
            return 0;
        if (!label && !is_in_str(param[i], "0123456789"))
            return 0;
    }
    return 1;
}

int is_indirect(char *param)
{
    int label = param[0] == LABEL_CHAR;

    if (my_strlen(param) < 1 || param[0] == DIRECT_CHAR)
        return 0;
    for (int i = label; param[i]; i++) {
        if (param[i] == '-' && i == label)
            i++;
        if (!is_in_str(param[i], LABEL_CHARS))
            return 0;
        if (!label && !is_in_str(param[i], "0123456789"))
            return 0;
    }
    return 1;
}

int is_reg(char *param)
{
    int nb;

    if (my_strlen(param) > 3)
        return 0;
    nb = str_to_long(param + 1);
    if (param[0] != 'r' || nb > REG_NUMBER || nb < 1)
        return 0;
    return 1;
}
