/*
** EPITECH PROJECT, 2022
** B-CPE-210-LIL-2-1-stumper2-edgar.lecuyer
** File description:
** functions
*/

#ifndef SUPALOC_H
    #define SUPALOC_H

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

typedef struct loc_t {
    struct loc_t *next;
    void *data;
} loc_t;

loc_t **recup(void);

/// \brief Free all the mallocs.
///
/// \param list The linked list to free.
///
void supfree(loc_t **list);

/// \brief Free all the mallocs and exit i.
///
/// \param list The linked list to free.
///
/// \param i The exit code.
void supexit(loc_t **loc_list, int i);

/// \brief malloc and place the pointer in a linked list.
///
void *supaloc(size_t size);


/// \brief free one element of the linked list.
///
void one_free(void *data, loc_t **loc_list);

void frexit(void *data, int i);

char *realoc_sp(char *str, size_t size);

int arrlen(char **arr);

#endif
