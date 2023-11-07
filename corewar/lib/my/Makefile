##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	my_putchar.c			\
		my_isneg.c				\
		my_put_nbr.c			\
		my_swap.c				\
		my_putstr.c				\
		my_strlen.c				\
		str_to_long.c			\
		my_sort_int_array.c		\
		my_compute_power_rec.c	\
		my_compute_square_root.c\
		my_is_prime.c			\
		my_find_prime_sup.c		\
		my_strcpy.c				\
		my_strncpy.c			\
		my_revstr.c				\
		my_strstr.c				\
		my_strcmp.c				\
		my_strncmp.c			\
		my_strupcase.c			\
		my_strlowcase.c			\
		my_strcapitalize.c		\
		my_str_isalpha.c		\
		my_str_isnum.c			\
		my_str_islower.c		\
		my_str_isupper.c		\
		my_str_isprintable.c	\
		my_strcat.c				\
		my_strncat.c			\
		my_show_word_array.c	\
		my_str_to_word_array.c	\
		my_str_replace.c		\
		my_str_move.c			\
		my_count_zero.c			\
		my_strdup.c				\
		my_is_in_str.c			\
		my_put_unsigned_nbr.c	\
		my_to_base_ten.c		\
		dec_to_base.c			\
		infindiv.c				\
		infinmod.c				\
		infinadd.c				\
		sub.c					\
		sub2.c					\
		my_non_putstr.c			\
		my_is_alphanum.c		\
		my_len_nbr.c			\
		my_memset.c				\
		my_free.c				\
		my_char_to_str.c		\
		long_to_str.c			\
		my_find_str.c			\
		my_nstrcat.c			\
		my_is_snake_case.c		\
		str_erase.c				\
		is_str_empty.c			\
		lists.c					\
		after_conversion_processing.c \
		field_flags_handling_funcs.c \
		field_handling_part_one.c \
		field_handling_part_two.c \
		my_convert_bases.c \
		my_printf.c \
		my_printf_funcs1.c \
		my_printf_funcs2.c \
		my_printf_funcs3.c \
		my_printf_setup_specs.c \
		my_printf_setup_specs_checks.c \
		precision_flags_handling.c \
		precision_flags_three.c \
		precision_flags_two.c \
		try_get_star_printf.c \
		my_convert_base_two.c \
		try_malloc_result.c \
		my_getnbr.c \
		my_malloc.c \
		secaloc.c	\
		supaloc.c

NAME	=	libmy.a

OBJ	=	$(SRC:.c=.o)

MY	=	my.h

all:	$(NAME)

clean:
	rm -f *.o

$(NAME):	$(OBJ)
	cp $(MY) ../../include/
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..

fclean: clean
	rm -f ../$(NAME)
	rm -f $(NAME)
	rm -f ../../include/$(MY)

re:	fclean all
