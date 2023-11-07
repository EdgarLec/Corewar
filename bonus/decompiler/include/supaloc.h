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

void supfree(loc_t **list);

void supexit(loc_t **loc_list, int i);

void *supaloc(size_t size);

void one_free(void *data, loc_t **loc_list);

void frexit(void *data, int i);

char *realoc_sp(char *str, size_t size);

int arrlen(char **arr);

#endif
