/*
** EPITECH PROJECT, 2021
** my_printf_h
** File description:
** contains every prototypes needed for my_printf
*/

#ifndef MY_PRINTF_H

    #define MY_PRINTF_H
    #include <stdarg.h>
    #include "my_structs.h"

int my_print_int(va_list, mod_specs *specs);
int my_print_octal(va_list, mod_specs *specs);
int my_print_dec(va_list, mod_specs *specs);
int my_print_hex(va_list, mod_specs *specs);
int my_print_hex_cap(va_list, mod_specs *specs);
int my_print_char(va_list, mod_specs *specs);
int my_print_str(va_list, mod_specs *specs);
int my_print_void(va_list, mod_specs *specs);
int my_print_mod(va_list, mod_specs *specs);
int my_print_bin(va_list, mod_specs *specs);
int my_print_non_alpha(va_list, mod_specs *specs);
char *my_convert_to_hex(unsigned long long int);
char *my_convert_to_oct(unsigned long long int);
char *my_convert_to_hex_cap(unsigned long long int);
char *my_convert_to_dec(long long int);
unsigned long long int my_convert_unsigned_int(va_list, mod_specs);
char *add_minus_malloc(char *);
char *my_convert_to_un_dec(unsigned long long int);
int process_after_conversion(char *, mod_specs *);
int get_size_of_flags(mod_specs *);
int is_dieze_flag(mod_specs *);
int is_space_flag(mod_specs *);
int is_plus_flag(mod_specs *);
char *move_to_right(char *);
long long int convert_to_size_t(va_list, mod_specs *);
long long int convert_to_ptrdiff_t(va_list, mod_specs *);
long long int check_double_length_mod(va_list, mod_specs *);
long long int get_right_int_length(va_list, mod_specs *);
long long int convert_to_char_length(va_list, mod_specs *);
long long int convert_to_short(va_list, mod_specs *);
long long int convert_to_long(va_list, mod_specs *);
int add_0x_beg_string(char *, mod_specs *, char *);
void add_char_to_beg_string(char *, char);
int add_space_or_sign_for_p(char *, char *, mod_specs *);
int add_space_or_sign_beg_string(char *, char *, mod_specs *);
int add_precision_zeros(char *, char *, mod_specs *, int);
void add_precision_flags_nbr(char *, char *, mod_specs *);
void add_precision_flag_str(char *, char *, mod_specs *);
int update_specs(char const *, int *, mod_specs *, va_list args);
int get_mod_specs(char const *, int, mod_specs *, va_list args);
int set_reset_struct(mod_specs *specs, int fd);
int check_for_dollar(const char *, int *, mod_specs *);
int check_for_flags(char const *, int *, mod_specs *);
int check_for_field(const char *, int *, mod_specs *, va_list args);
int check_for_precision(const char *, int *, mod_specs *, va_list args);
int check_for_len_modifiers(const char *, int *, mod_specs *);
char *add_zeros_or_spaces_field(char *, char *, mod_specs *, int);
int check_if_octal_or_hex(mod_specs *, char *);
int try_get_star_field(const char *str, int *i, mod_specs *, va_list);
int try_get_star_prec(const char *str, int *i, mod_specs *, va_list);
char *try_malloc_result(const char *string, char *result);
int my_check_convert_dec(unsigned long long int a, char *result);
int my_check_convert_dec_two(char *result, long long int *a, int *is_neg);
int try_free_mod_specs(mod_specs *specs);

#endif /* MY_PRINTF_H */
