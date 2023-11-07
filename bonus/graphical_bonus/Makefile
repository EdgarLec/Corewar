##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	src/main.c				\
		src/arena.c							\
		src/utils.c							\
		src/supaloc.c						\
		src/secaloc.c						\
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
		src/ncurses_handling/init_ncurses.c		\
		src/ncurses_handling/refresh_ncurses.c		\
		src/ncurses_handling/print_arena.c		\
		src/ncurses_handling/print_texts.c		\
		src/ncurses_handling/fill_map_belongings.c		\
		src/ncurses_handling/set_get_colors_ncurses.c		\
		src/ncurses_handling/init_vm_values.c		\
		src/ncurses_handling/process_end_ncurses.c		\
		src/ncurses_handling/print_back_canvas_arena.c		\

NAME	=	corewar

OBJ	=	$(SRC:.c=.o)

CFLAGS				+= -I include/ -g

MY	=	my.h

all:	exec_lib $(NAME)

exec_lib:
	make -C ../../corewar/lib/my/

clean:
	rm -f $(OBJ)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g -L../../corewar/lib/ -lmy -lncurses -Wall -Wextra

fclean:
	make clean
	rm -f $(NAME)
	rm -f *.c~
	rm -f *.out
	rm -f vgcore*
	rm -f *.gcda
	rm -f *.gcno
	rm -f corewar_tests*

lib_fclean:
	make fclean -C ../../corewar/lib/my/

re:
	make fclean
	make all
