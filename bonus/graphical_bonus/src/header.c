/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** main
*/

#include "corewar.h"
#include "op.h"

header_t *init_head(int fd)
{
    header_t *head = supaloc(sizeof(header_t));

    if (sizeof(header_t) != read(fd, head, sizeof(header_t))) {
        my_dprintf(2, "vm: error while reading header.\n");
        supexit(recup(), 84);
    }
    if (endian(head->magic) != COREWAR_EXEC_MAGIC) {
        my_dprintf(2, "vm: error bad Magic exec.\n");
        supexit(recup(), 84);
    }
    return head;
}
