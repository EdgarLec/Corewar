/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my_printf.h"
#include "include/my_structs.h"

int print_param(va_list args, mod_specs *specs)
{
    char *flag_list = "diouxXcsp%bS";
    int conv_number = 0;
    int result = 0;
    int(*fun_ptr_arr[])(va_list args, mod_specs *specs) =
    {my_print_int, my_print_int, my_print_octal, my_print_dec,
    my_print_hex, my_print_hex_cap, my_print_char, my_print_str,
    my_print_void, my_print_mod, my_print_bin, my_print_non_alpha};

    for (; flag_list[conv_number] != specs->conv_specifier; conv_number++);
    result = (*fun_ptr_arr[conv_number])(args, specs);
    if (result == 1)
        return (1);
    return (0);
}

int print_modulo(va_list args, mod_specs *specs)
{
    if (specs->mod_length == -1)
        return (0);
    if (specs->conv_s == 0) {
        my_putchar('%');
        return (0);
    }
    if (print_param(args, specs) == 1) {
        specs->mod_length = -1;
        return (0);
    }
    return (specs->mod_length);
}

int print_check_string(const char *str, va_list args, int fd)
{
    int i = 0;
    mod_specs specs;

    specs.mod_length = 0;
    while (str[i] != '\0') {
        if (specs.mod_length == -1) {
            try_free_mod_specs(&specs);
            return (1);
        }
        if (str[i] == '%') {
            set_reset_struct(&specs, fd);
            specs.mod_length = get_mod_specs(str, i, &specs, args);
            i += print_modulo(args, &specs);
            try_free_mod_specs(&specs);
        } else
            write(fd, &str[i], 1);
        i++;
    }
    return (0);
}

int my_dprintf(int fd, const char *str, ...)
{
    va_list args;

    va_start(args, str);
    print_check_string(str, args, fd);
    return (0);
}

int my_printf(const char *str, ...)
{
    va_list args;

    va_start(args, str);
    print_check_string(str, args, 1);
    return (0);
}
