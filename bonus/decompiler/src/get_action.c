/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "decomp.h"
#include "op.h"

int exeption_param(char *arena, buffer_t *buffer, int coo[2], int pc)
{
    int nb_param = coo[0];
    int type = coo[1];

    if ((buffer->action == 0x0b && type != 0 && nb_param != 0) ||
    ((buffer->action == 0x0a || buffer->action == 0x0e) &&
    nb_param < 2 && type != 0))
        return IND_SIZE;
    return 0;
}

int place_param(char *arena, buffer_t *buffer, int coo[2], int pc)
{
    int nb_param = coo[0];
    int type = coo[1];
    char *tmp = (char *)&buffer->ind[nb_param];

    if (type == 2 || exeption_param(arena, buffer, coo, pc)) {
        for (int h = 0; h < IND_SIZE; h++)
            my_memcpy(tmp + h, arena + (pc + h) % MEM_SIZE, 1);
        return IND_SIZE;
    }
    if (type == 1) {
        tmp = (char *)&buffer->dir[nb_param];
        for (int h = 0; h < DIR_SIZE; h++)
            my_memcpy(tmp + h, arena + (pc + h) % MEM_SIZE, 1);
        return DIR_SIZE;
    } else if (type == 0) {
        my_memcpy(&buffer->reg[nb_param], arena + pc % MEM_SIZE, 1);
        return 1;
    }
    return 0;
}

int add_param(char *arena, buffer_t *buffer, int nb_param, int pc)
{
    char *str[3] = {"\0\1", "\1\0", "\1\1"};

    for (int type = 0; type < 3; type++) {
        if (buffer->c_byte[nb_param * 2] == str[type][0] &&
        buffer->c_byte[nb_param * 2 + 1] == str[type][1])
            return place_param(arena, buffer, (int[2]){nb_param, type}, pc);
    }
    return 0;
}

int get_param(char *arena, buffer_t *buffer, int pc)
{
    int size = 0;
    int tmp = 0;

    for (int i = 0; i < 4; i++) {
        tmp = add_param(arena, buffer, i, pc + size);
        if (tmp == 0)
            return size;
        size += tmp;
    }
    buffer->size = size + 2;
    return size;
}

int get_action(char *arena, buffer_t *buffer, int pc)
{
    int start = pc;
    my_memset(buffer, 0, sizeof(buffer_t));
    my_memcpy(&buffer->action, arena + pc % MEM_SIZE, 1);
    pc += 1;
    if (buffer->action == 0x01) {
        my_memcpy(buffer->dir, arena + pc % MEM_SIZE, DIR_SIZE);
        buffer->size = 5;
        return DIR_SIZE + 1;
    }
    if (buffer->action == 0x09 || buffer->action == 0x0c ||
    buffer->action == 0x0f) {
        my_memcpy(buffer->ind, arena + pc % MEM_SIZE, IND_SIZE);
        buffer->size = 3;
        return 3;
    }
    my_memcpy(&buffer->coding_byte, arena + pc % MEM_SIZE, 1);
    coding_byte(buffer->coding_byte, buffer->c_byte);
    buffer->size = (get_param(arena, buffer, (pc + 1) % MEM_SIZE) + 2) %
    MEM_SIZE;
    return buffer->size;
}
// 990
