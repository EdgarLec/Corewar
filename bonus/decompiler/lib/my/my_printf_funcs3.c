/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf funcs
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include "include/my_printf.h"
#include "include/my_structs.h"

int check_if_octal_or_hex(mod_specs *specs, char *a)
{
    if (is_dieze_flag(specs) == 0 || !(specs->conv_specifier == 'x' ||
    specs->conv_specifier == 'X' || specs->conv_specifier == 'o'))
        return (0);
    if (specs->conv_specifier == 'o' && a[0] == '0')
        return (0);
    return (1);
}

static char *add_char_to_str(char *a, char b)
{
    char *result;

    if (a == NULL)
        return (NULL);
    result = malloc(sizeof(char) * my_strlen(a) + 2);
    if (result == NULL)
        return (NULL);
    for (int i = 0; i < my_strlen(a); i++)
        result[i] = a[i];
    result[my_strlen(a)] = b;
    result[my_strlen(a) + 1] = '\0';
    free(a);
    return (result);
}

static char *add_zeros_oct(char *arg, char *result)
{
    int i;
    char *b = my_strdup(arg);
    int len_after_zeros;

    for (i = 1; arg[i] != '\0'; i++);
    arg[0] = '\\';
    arg[1] = '\0';
    for (int y = 1; y < 4 - i; y++) {
        arg[y] = '0';
        arg[y + 1] = '\0';
    }
    len_after_zeros = my_strlen(arg);
    for (int y = len_after_zeros; y < 4; y++) {
        arg[y] = b[y - len_after_zeros];
    }
    arg[4] = '\0';
    for (int a = 0; a < 4; a++)
        result = add_char_to_str(result, arg[a]);
    return (result);
}

int my_print_non_alpha(va_list args, mod_specs *specs)
{
    char *string, *converted, *result;

    string = va_arg(args, char *);
    result = NULL;
    result = try_malloc_result(string, result);
    if (result == NULL)
        return (1);
    if (specs->len_modifiers[0] == 'l' || specs->len_modifiers[0] == 'q' ||
    specs->len_modifiers[0] == 'j' || specs->len_modifiers[0] == 'z' ||
    specs->len_modifiers[0] == 'Z' || specs->len_modifiers[0] == 't')
        return (0);
    for (int i = 0; i < my_strlen(string); i++) {
        if (string[i] < 32 || string[i] >= 127) {
            converted = my_convert_to_oct(string[i]);
            result = add_zeros_oct(converted, result);
        } else
            result = add_char_to_str(result, string[i]);
    }
    process_after_conversion(result, specs);
    return (0);
}

char *add_minus_malloc(char *arg)
{
    char *arg3;

    arg3 = malloc(sizeof(char) * my_strlen(arg) + 2);
    if (arg3 == NULL)
        return (NULL);
    arg3 = my_strcpy(arg3, arg);
    my_revstr(arg3);
    arg3[my_strlen(arg)] = '-';
    arg3[my_strlen(arg) + 1] = '\0';
    my_revstr(arg3);
    arg = arg3;
    return (arg);
}
