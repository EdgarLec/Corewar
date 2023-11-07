##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

ASM_SRC	=	asm/src/error.c								\
		asm/src/header.c							\
		asm/src/endian.c							\
		asm/src/file_manip.c						\
		asm/src/parsing/line_parse.c				\
		asm/src/parsing/label.c						\
		asm/src/parsing/label_error.c				\
		asm/src/cmd_handler/cmd_handler.c			\
		asm/src/cmd_handler/add_arg.c				\
		asm/src/cmd_handler/type_verifiers.c		\

VM_SRC	=	corewar/src/arena.c							\
		corewar/src/utils.c							\
		corewar/src/champions.c						\
		corewar/src/header.c						\
		corewar/src/get_action.c					\
		corewar/src/print_dump.c					\
		corewar/src/instructions/live.c				\
		corewar/src/instructions/ld.c				\
		corewar/src/instructions/st.c				\
		corewar/src/instructions/fork.c				\
		corewar/src/instructions/add_sub.c			\
		corewar/src/instructions/bitshift.c			\
		corewar/src/instructions/bitshift_exec.c	\
		corewar/src/instructions/aff.c				\
		corewar/src/instructions/sti.c				\
		corewar/src/instructions/zjmp.c				\
		corewar/src/instructions/ldi.c				\
		corewar/src/instructions/lldi.c				\
		corewar/src/arg_handling.c					\
		corewar/src/arg_a_handling.c				\
		corewar/src/arg_n_handling.c				\
		corewar/src/instructions/loops_ld_lld.c		\
		corewar/src/instructions/change_values_forks.c	\
		corewar/src/corewar_loop.c					\

ASM_TEST_SRC	=	tests/asm/arg_tests.c						\
				tests/asm/cmd_tests.c							\
				tests/asm/types_tests.c							\
				tests/asm/line_tests.c							\
				tests/asm/label_err_tests.c						\
				tests/asm/label_tests.c							\
				tests/asm/header_unit_tests.c					\
				tests/asm/file_tests.c							\
				tests/asm/error_unit_tests.c					\
				tests/asm/cmd_err_tests.c						\
				tests/asm/header_tests.c						\
				tests/asm/champ_tests.c							\

VM_TEST_SRC	=	tests/vm/fight_tests.c							\
				tests/vm/dump_tests.c							\
				tests/vm/st_tests.c								\
				tests/vm/sti_tests.c							\
				tests/vm/loop_ld_tests.c						\
				tests/vm/lldi_tests.c							\
				tests/vm/live_tests.c							\
				tests/vm/ldi_tests.c							\
				tests/vm/ld_tests.c								\
				tests/vm/values_fork_tests.c					\
				tests/vm/bitshift_tests.c						\
				tests/vm/add_sub_tests.c						\
				tests/vm/header_tests.c							\
				tests/vm/get_action_tests.c						\
				tests/vm/corewar_loop_tests.c					\
				tests/vm/champions_tests.c						\
				tests/vm/arg_n_handling_tests.c					\
				tests/vm/arg_handling_tests.c					\
				tests/vm/arg_a_handling_tests.c					\

ASM_NAME	=	asm_tests

VM_NAME	=	vm_tests

all:	make_asm make_corewar

make_asm:
	make -C asm

make_corewar:
	make -C corewar

clean:
	make clean -C asm
	make clean -C corewar

fclean: clean
	make push_fclean -C asm
	make push_fclean -C corewar
	find -name "*.c~" -delete
	find -name "*.out" -delete
	find -name "vgcore*" -delete
	find -name "*.gcda" -delete
	find -name "*.gcno" -delete
	rm -f $(ASM_NAME)
	rm -f $(VM_NAME)

re:	fclean all

tests_run:
	find -name "*.gcda" -delete
	find -name "*.gcno" -delete
	rm -f $(ASM_NAME)
	rm -f $(VM_NAME)
	make -C asm/lib/my
	make -C corewar/lib/my
	gcc -o $(ASM_NAME) $(ASM_SRC) $(ASM_TEST_SRC) -Lasm/lib/ -lmy \
	--coverage -lcriterion -I asm/include/
	gcc -o $(VM_NAME) $(VM_SRC) $(VM_TEST_SRC) -Lcorewar/lib/ -lmy \
	--coverage -lcriterion -I corewar/include/
	./$(ASM_NAME)
	./$(VM_NAME)
	gcovr --exclude tests
	gcovr -b --exclude tests

run_doc:
	doxygen Doxyfile
	firefox html/index.html
