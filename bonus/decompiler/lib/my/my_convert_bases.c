/*
** EPITECH PROJECT, 2021
** my_convert_bases
** File description:
** funcs that converts to different bases
*/

#include "my.h"
#include "include/my_printf.h"
#include <stdlib.h>

char *my_convert_to_hex(unsigned long long int a)
{
    char *result = malloc(sizeof(char) * 17);
    char numbers[16] = "0123456789abcdef";
    int result_counter = 0;

    if (my_check_convert_dec(a, result) == 1)
        return (NULL);
    while (a > 0) {
        result[result_counter] = numbers[a % 16];
        result[result_counter + 1] = '\0';
        a = a / 16;
        result_counter++;
    }
    my_revstr(result);
    return (result);
}

char *my_convert_to_hex_cap(unsigned long long int a)
{
    char *result = malloc(sizeof(char) * 17);
    char numbers[16] = "0123456789ABCDEF";
    int result_counter = 0;

    if (my_check_convert_dec(a, result) == 1)
        return (NULL);
    while (a > 0) {
        result[result_counter] = numbers[a % 16];
        result[result_counter + 1] = '\0';
        a = a / 16;
        result_counter++;
    }
    my_revstr(result);
    return (result);
}

char *my_convert_to_oct(unsigned long long int a)
{
    char *result = malloc(sizeof(char) * 23);
    char numbers[8] = "01234567";
    int result_counter = 0;

    if (my_check_convert_dec(a, result) == 1)
        return (NULL);
    while (a > 0) {
        result[result_counter] = numbers[a % 8];
        result[result_counter + 1] = '\0';
        a = a / 8;
        result_counter++;
    }
    my_revstr(result);
    return (result);
}

char *my_convert_to_dec(long long int a)
{
    char *result = malloc(sizeof(char) * 20);
    char numbers[10] = "0123456789";
    int is_neg = 0;

    if (my_check_convert_dec_two(result, &a, &is_neg) == 1)
        return (NULL);
    for (int i = 0; a != 0; i++) {
        result[i] = numbers[a % 10];
        result[i + 1] = '\0';
        a = a / 10;
    }
    my_revstr(result);
    if (is_neg == 1)
        result = add_minus_malloc(result);
    return (result);
}

char *my_convert_to_un_dec(unsigned long long int a)
{
    char *result = malloc(sizeof(char) * 21);
    char numbers[10] = "0123456789";

    if (my_check_convert_dec(a, result) == 1)
        return (NULL);
    for (int i = 0; a != 0; i++) {
        result[i] = numbers[a % 10];
        result[i + 1] = '\0';
        a = a / 10;
    }
    my_revstr(result);
    return (result);
}
