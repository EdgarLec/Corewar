/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>
    #include <stdlib.h>
    #include <unistd.h>

typedef struct linked_list {
    void *data;
    struct linked_list *next;
    struct linked_list *prev;
} list_t;

typedef struct specifier {
    char *str;
    char *length;
    char spec_char;
    int nb_spc;
    int is_plus;
    int is_minus;
    int is_hashtag;
    int is_zero;
    int width;
    int prec;
} l_spec;

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
char my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
char * const *my_show_word_array(char * const *tab);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char **my_str_to_word_array(char const *str, char *delimiters);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
int my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char *my_strdup(char const *src);
char *my_str_replace(char *str, char *str_to_put
, int start, int nb_to_replace);
char *my_str_move(char *str, int new_start);
int count_zero(char *nb);
int my_printf(char const *str, ...);
int is_in_str(char to_find, char const *str);
void special_cases(l_spec *spec);
int str_switch(l_spec *spec, va_list list_arg);
int my_put_unsigned_nbr(unsigned int nb);
char *change_base_ten(char *str, char *base);
char *ope(char *nb1, char *nb2);
void add_end_nbr_neg(int i, char **result, int size, char *tab);
char *infinsub(char *frst, char *sec, char c);
char *display(char *result, int isneg, int i);
char *my_putnbr_base(char *nbr, char *base, char minus);
char *divbistro(char *nb1, char *nb2);
char *modbistro(char *nb1, char *nb2);
char *infinmult(char *nb1, char *nb2);
int my_non_putstr(char const *str);
int my_is_alphanum(char const str);
long long my_len_nbr(long long nb);
void my_free(char *to_free, ...);
char *my_strset(int len_malloc);
char **my_dbstrset(int len_malloc);
int *my_intarrayset(int len_malloc);
int **my_dbintarrayset(int len_malloc);
int add_width(char *str, int start, l_spec *spec);
void sign_oct_hex(l_spec *spec, char *nb);
void un_sign(l_spec *spec, unsigned int nb);
void width_char_str(l_spec *spec, char *str);
char *my_char_to_str(char charac);
char *long_to_str(long long nb);
void width_pointer(l_spec *spec, char *str);
int add_length(char *str, int start, l_spec *spec);
int add_prec(char *str, int start, l_spec *spec);
void add_flags(char *str, int start, l_spec *spec);
long long int str_to_long(char const *str);
int find_str(char *to_find, char *src);
int len_array(char * const *tab);
char *my_nstrcat(int nb, int len, ...);
int my_nstrlen(int nb, ...);
int my_is_snake_case(char *str);
int my_puterror(char const *str);
char *my_strndup(char const *src, int nb);
char *str_erase(char *src, int start, int size);
int is_empty(char *str);
void *my_malloc(size_t __size);
void append_node(list_t **begin, void *data);
void remove_node(list_t **begin, int index, void (*free_func)(void *));
void *my_memset(void *dest, int val, size_t len);
int my_put_nbr_fd(int nb, int fd);
int my_dprintf(int fd, char const *str, ...);
int my_getnbr(char const *string);

#endif
