/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** my_dprintf
*/

#include "my.h"

void dprintf_switch(int fd, char c, va_list list)
{
    char *tmp;

    switch (c) {
        case 's':
            tmp = va_arg(list, char *);
            write(fd, tmp, my_strlen(tmp));
            break;
        case 'd':
            my_put_nbr_fd(va_arg(list, int), fd);
            break;
        case 'i':
            my_put_nbr_fd(va_arg(list, int), fd);
            break;
        default:
            break;
    }
}

void my_dprintf(int fd, char *str, ...)
{
    va_list list;

    va_start(list, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] != '%') {
            write(fd, &str[i], 1);
            continue;
        }
        i++;
        if (str[i])
            dprintf_switch(fd, str[i], list);
    }
    va_end(list);
}
