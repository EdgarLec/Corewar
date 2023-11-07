##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	src/main.c								\
		src/error.c								\
		src/header.c							\
		src/endian.c							\
		src/file_manip.c						\
		src/parsing/line_parse.c				\
		src/parsing/label.c						\
		src/parsing/label_error.c				\
		src/cmd_handler/cmd_handler.c			\
		src/cmd_handler/add_arg.c				\
		src/cmd_handler/type_verifiers.c		\

NAME	=	asm

OBJ	=	$(SRC:.c=.o)

CFLAGS += -I include/ -Wall -Wextra

MY	=	my.h

all:	exec_lib $(NAME)

exec_lib:
	make -C lib/my/

clean:
	rm -f $(OBJ)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -Llib/ -lmy

fclean: clean
	rm -f $(NAME)
	rm -f *.c~
	rm -f *.out
	rm -f vgcore*
	rm -f *.gcda
	rm -f *.gcno

lib_fclean:
	make fclean -C lib/my/

push_fclean: fclean lib_fclean

re:	fclean all

tests_run:
	make -C ../tests/asm/
