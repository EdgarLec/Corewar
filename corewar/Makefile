##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	src/main.c							\
		src/arena.c							\
		src/utils.c							\
		src/champions.c						\
		src/header.c						\
		src/get_action.c					\
		src/print_dump.c					\
		src/instructions/live.c				\
		src/instructions/ld.c				\
		src/instructions/st.c				\
		src/instructions/fork.c				\
		src/instructions/add_sub.c			\
		src/instructions/bitshift.c			\
		src/instructions/bitshift_exec.c	\
		src/instructions/aff.c				\
		src/instructions/sti.c				\
		src/instructions/zjmp.c				\
		src/instructions/ldi.c				\
		src/instructions/lldi.c				\
		src/arg_handling.c					\
		src/arg_a_handling.c				\
		src/arg_n_handling.c				\
		src/instructions/loops_ld_lld.c		\
		src/instructions/change_values_forks.c	\
		src/corewar_loop.c					\

NAME	=	corewar

OBJ	=	$(SRC:.c=.o)

CFLAGS	+= -I include/ -Wall -Wextra

MY	=	my.h

all:	exec_lib $(NAME)

exec_lib:
	make -C lib/my/

clean:
	rm -f $(OBJ)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -Llib/ -lmy -Wall -Wextra

fclean: clean
	rm -f $(NAME)
	rm -f *.c~
	rm -f *.out
	rm -f vgcore*
	rm -f *.gcda
	rm -f *.gcno
	rm -f corewar_tests*

lib_fclean:
	make fclean -C lib/my/

push_fclean: fclean lib_fclean

re:	fclean all

tests_run: exec_lib
	gcc -o corewar_tests $(SRC) tests/*.c -Llib/ -lmy --coverage -lcriterion
	./corewar_tests
	gcovr --exclude tests
	gcovr -b --exclude tests
