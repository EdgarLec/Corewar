/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** after_conversion_processing
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include "include/my_printf.h"
#include "include/my_structs.h"

char *try_malloc_result(const char *string, char *result)
{
    result = malloc(sizeof(char) * my_strlen(string) + 1);

    if (result == NULL)
        return (NULL);
    result[0] = '\0';
    return result;
}
