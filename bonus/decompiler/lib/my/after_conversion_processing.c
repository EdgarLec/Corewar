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

int get_size_of_flags(mod_specs *specs)
{
    int size = 0;

    for (int i = 0; i < my_strlen(specs->flags_flags); i++) {
        if (specs->flags_flags[i] == '#' && (specs->conv_specifier == 'x' ||
        specs->conv_specifier == 'X'))
            size = 2;
        if ((specs->flags_flags[i] == ' ' || specs->flags_flags[i] == '+')
        && (specs->conv_specifier == 'd' || specs->conv_specifier == 'i'
        || specs->conv_specifier == 'p'))
            size = 1;
    }
    return (size);
}

static int get_size_of_result(char *result, mod_specs *specs)
{
    int size;

    if (specs->field_field >= specs->precision_precision +
    get_size_of_flags(specs) &&
    specs->field_field >= my_strlen(result) + get_size_of_flags(specs))
        size = specs->field_field;
    else if (specs->precision_precision >= my_strlen(result) +
    get_size_of_flags(specs))
        size = specs->precision_precision;
    else
        size = my_strlen(result) + get_size_of_flags(specs);
    return (size);
}

static char *precision_process(char *a, mod_specs *specs, int size)
{
    char *result = malloc(sizeof(char) * size + 1);

    if (result == NULL)
        return (NULL);
    if (!(specs->conv_specifier == 's' || specs->conv_specifier == 'S' ||
    specs->conv_specifier == 'c'))
        add_precision_flags_nbr(result, a, specs);
    else if (specs->conv_specifier == 'c') {
        result[0] = a[0];
        result[1] = a[1];
    } else
        add_precision_flag_str(result, a, specs);
    if (specs->conv_specifier != 's')
        free(a);
    return (result);
}

static char *field_process(char *result, mod_specs *specs, int size)
{
    char *a = my_strdup(result);

    if (specs->field == 1 && specs->field_field > specs->precision_precision)
        result = add_zeros_or_spaces_field(result, a, specs, size);
    free(a);
    return (result);
}

int process_after_conversion(char *result, mod_specs *specs)
{
    int size;

    if (result == NULL)
        return (1);
    size = get_size_of_result(result, specs);
    result = precision_process(result, specs, size);
    if (result == NULL)
        return (1);
    result = field_process(result, specs, size);
    result[size] = '\0';
    write(specs->fd, result, my_strlen(result));
    free(result);
    return (0);
}
