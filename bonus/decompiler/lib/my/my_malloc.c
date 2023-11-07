/*
** EPITECH PROJECT, 2021
** my_memset.c
** File description:
** my_malloc
*/

#include <stdlib.h>
#include <unistd.h>

void *my_malloc(size_t __size)
{
    void *ptr = malloc(__size);

    if (!ptr) {
        write(2, "Invalid malloc()\n", 17);
        exit(84);
    }
    return ptr;
}

int **my_dbintarrayset(int len_malloc)
{
    int **str = my_malloc(sizeof(int *) * len_malloc);

    if (str == 0) {
        write(2, "Invalid malloc()\n", 17);
        exit(84);
    }
    for (int i = 0; i < len_malloc; str[i] = 0, i++);
    return str;
}

int *my_intarrayset(int len_malloc)
{
    int *str = my_malloc(sizeof(int) * len_malloc);

    if (str == 0) {
        write(2, "Invalid malloc()\n", 17);
        exit(84);
    }
    for (int i = 0; i < len_malloc; str[i] = 0, i++);
    return str;
}

char **my_dbstrset(int len_malloc)
{
    char **str = my_malloc(sizeof(char *) * len_malloc);

    if (str == 0) {
        write(2, "Invalid malloc()\n", 17);
        exit(84);
    }
    for (int i = 0; i < len_malloc; str[i] = 0, i++);
    return str;
}

char *my_strset(int len_malloc)
{
    char *str = my_malloc(sizeof(char) * len_malloc);

    if (str == 0) {
        write(2, "Invalid malloc()\n", 17);
        exit(84);
    }
    for (int i = 0; i < len_malloc; str[i] = 0, i++);
    return str;
}
