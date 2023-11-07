##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	src/main.c							\
		src/arena.c							\
		src/utils.c							\
		src/supaloc.c						\
		src/secaloc.c						\
		src/champions.c						\
		src/header.c						\
		src/get_action.c					\
		src/arg_handling.c					\

NAME	=	decompiler

OBJ	=	$(SRC:.c=.o)

CFLAGS	+= -I include/ -g

MY	=	my.h

all:	exec_lib $(NAME)

exec_lib:
	make -C lib/my/

clean:
	rm -f $(OBJ)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g -Llib/ -lmy -Wall -Wextra

fclean: clean lib_fclean
	rm -f $(NAME)
	rm -f *.c~
	rm -f *.out
	rm -f vgcore*
	rm -f *.gcda
	rm -f *.gcno
	rm -f corewar_tests*

lib_fclean:
	make fclean -C lib/my/

push_fclean: fclean

re:	fclean all

tests_run: exec_lib
	gcc -o corewar_tests $(SRC) tests/*.c -Llib/ -lmy --coverage -lcriterion
	./corewar_tests
	gcovr --exclude tests
	gcovr -b --exclude tests
