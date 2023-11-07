/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** asm
*/

/// @file asm.h
/// @brief Header file for the asm. Contains all the prototypes,
///        macros, arrays and structures needed for the asm.

#ifndef ASM_H_
    #define ASM_H_

    #include <wait.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <errno.h>
    #include <string.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include "my.h"
    #include "op.h"

/// \brief Number of different commands
    #define NB_CMD 18

/// \brief Macro to get the coding byte according to the argument type
    #define C_BYTE(type) (type == T_REG ? 1 : type == T_DIR ? 10 : 11)

/// \brief Macro to tell if the coding byte is to write or not
    #define WR_BYTE(code) (code != 1 && code != 9 && code != 12 && code != 15)

/// \brief Size of the argument according to its type
    #define ARG_SIZE(type) (type == 11 ? IND_SIZE : type == 10 ? DIR_SIZE : 1)

/// \brief Tells if the size of the 'i' argument of the 'cmd' command
///        is special or not
    #define SPECIAL(cmd, i) (cmd->param_types[i] == T_DIR && (command->\
instruction == 9 || command->instruction == 12 || command->instruction == 15 \
|| ((command->instruction == 10 || command->instruction == 14) && i < 2) \
|| (command->instruction == 11 && i > 0)))

/// \brief Array of every error message
__attribute__((unused)) static const char *error_str[] = {
    0, "Invalid instruction.", "Syntax error.", "The program name is too long.",
    "The name can only be defined once.", "No name specified.",
    "No comment specified.", "The comment is too long.",
    "The comment can only be defined once.",
    "Too many arguments given to the instruction.",
    "The argument given to the instruction is invalid."
};

/// \brief Structure which contains all the infos needed for a command
typedef struct commands_s {
    char *str;
    char instruction;
    char coding_byte;
    char c_byte[4];
    int params[MAX_ARGS_NUMBER];
    char param_types[MAX_ARGS_NUMBER];
    char *labels[MAX_ARGS_NUMBER];
} commands_t;

/// \brief Main structure of the asm
typedef struct file_s {
    header_t *header;
    list_t *commands;
    list_t *labels;
    int found[2];
    char *file_src;
    char *buffer;
    char *dest;
    FILE *fd;
} file_t;

/// \brief Array which contains all the command names
__attribute__((unused)) static const char *cmd_names[NB_CMD] = {
    "live", "ld", "st", "add", "sub", "and", "or", "xor", "zjmp", "ldi",
    "sti", "fork", "lld", "lldi", "lfork", "aff", ".name", ".comment"
};

////////////////////////////////////////////////////////////
/// \brief Setter of the champion's name.
///
/// \param file File_t structure.
///
/// \param line String which contains the .name instruction.
///
/// \param nb Number of the line.
///
////////////////////////////////////////////////////////////
void name_setter(file_t *file, char *line, int nb);

////////////////////////////////////////////////////////////
/// \brief Setter of the champion's comment.
///
/// \param file File_t structure.
///
/// \param line String which contains the .comment instruction.
///
/// \param nb Number of the line.
///
////////////////////////////////////////////////////////////
void comment_setter(file_t *file, char *line, int nb);

/// \brief Array of function pointers to the name and comment setters
__attribute__((unused)) static void (*const cmd_setters[NB_CMD])
(file_t *file, char *line, int nb) = {
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, name_setter, comment_setter,
};

////////////////////////////////////////////////////////////
/// \brief Verifier for a register.
///
/// \param param String which contains the parameter to verify.
///
/// \return On sucess, return 1. On error, return 0.
///
////////////////////////////////////////////////////////////
int is_reg(char *param);

////////////////////////////////////////////////////////////
/// \brief Verifier for a direct.
///
/// \param param String which contains the parameter to verify.
///
/// \return On sucess, return 1. On error, return 0.
///
////////////////////////////////////////////////////////////
int is_direct(char *param);

////////////////////////////////////////////////////////////
/// \brief Verifier for an indirect.
///
/// \param param String which contains the parameter to verify.
///
/// \return On sucess, return 1. On error, return 0.
///
////////////////////////////////////////////////////////////
int is_indirect(char *param);

/// \brief Array of function pointers to the types verifiers
__attribute__((unused)) static int (*const verif_type[3])(char *arg) = {
    is_reg, is_direct, is_indirect
};

// Other prototypes

////////////////////////////////////////////////////////////
/// \brief Open 'filename' and store the fd in file.
///
/// \param filename The file to open.
/// \param file     The file_t structure in which to store the file descriptor.
///
/// \return On sucess, return 1. On error, return 0 and print error massage.
///
////////////////////////////////////////////////////////////
int check_open(char *filename, file_t *file);

////////////////////////////////////////////////////////////
/// \brief Write the header and every command stored in 'file' and free 'file'.
///
/// \param file The file_t structure to write and free.
///
////////////////////////////////////////////////////////////
void write_and_free(file_t *file);

////////////////////////////////////////////////////////////
/// \brief Global programm error status (like errno).
///
/// \param to_set New value of the variable 'error' (-1 to do nothing).
///
/// \return Return the new value of the variable 'error'.
///
////////////////////////////////////////////////////////////
int error(int to_set);

////////////////////////////////////////////////////////////
/// \brief Setter of the global programm error status (like errno).
///
/// \param to_set New value of the variable 'error' (-1 to do nothing).
///
////////////////////////////////////////////////////////////
void set_error(int to_set);

////////////////////////////////////////////////////////////
/// \brief Reverse the endianess of an int.
///
/// \param nb Number to reverse.
///
/// \return Return the reversed number.
///
////////////////////////////////////////////////////////////
int endian(int nb);

////////////////////////////////////////////////////////////
/// \brief Reverse the endianess of a short.
///
/// \param nb Number to reverse.
///
/// \return Return the reversed number.
///
////////////////////////////////////////////////////////////
short short_endian(short nb);

////////////////////////////////////////////////////////////
/// \brief Compile a .cor file ('filename') into a .s file.
///
/// \param filename File to compile.
///
////////////////////////////////////////////////////////////
void parse_file(char *filename);

////////////////////////////////////////////////////////////
/// \brief Add a command to the file_t structure if it's valid.
///
/// \param file File_t structre to which add the command.
///
/// \param line String which contains the instruction and its arguments.
///
/// \param nb Number of the line.
///
/// \param type Code of the instruction (see op_tab in op.h).
///
////////////////////////////////////////////////////////////
void cmd_handler(file_t *file, char *line, int nb, int type);

////////////////////////////////////////////////////////////
/// \brief Add an argument to a command.
///
/// \param arg String which contains the argument to add.
///
/// \param param_octal Possible types of argument (see op_tab in op.h).
///
/// \param command The commadn to which add the argument.
///
/// \param i Argument number inside the command.
///
/// \return Return the size of the argument added (0 if error).
///
////////////////////////////////////////////////////////////
int add_arg(char *arg, char param_octal, commands_t *command, int i);

////////////////////////////////////////////////////////////
/// \brief Add a label to the file_t structure if it's correct and
///        removing the label from the given string.
///
/// \param file File_t structure to which add the label.
///
/// \param line Pointer to the string containing the label.
///
/// \return On sucess, return 1. On error, return 0 and print error massage.
///
////////////////////////////////////////////////////////////
int add_label(file_t *file, char **line);

////////////////////////////////////////////////////////////
/// \brief Get the adress of the command or label given in.
///
/// \param file File_t structure to which add the label.
///
/// \param line Pointer to the string containing the label.
///
/// \return On sucess, return 1. On error, return 0 and print error massage.
///
////////////////////////////////////////////////////////////
int get_label_adress(file_t *file, list_t *stop);

////////////////////////////////////////////////////////////
/// \brief Get the adress of the command or label given in.
///
/// \param file File_t structure to which add the label.
///
/// \param line Pointer to the string containing the label.
///
/// \return On sucess, return 1. On error, return 0 and print error massage.
///
////////////////////////////////////////////////////////////
void label_loop(file_t *file);

////////////////////////////////////////////////////////////
/// \brief Destroyer of the file_t structure.
///
/// \param file File_t structure to free.
///
////////////////////////////////////////////////////////////
void free_file(file_t *file);

////////////////////////////////////////////////////////////
/// \brief Destroyer of the file_t structure.
///
/// \param error Error id (which string to pick from 'error_str' in asm.h).
///
/// \param line Line where the error occured.
///
/// \param file File in which the error occured.
///
////////////////////////////////////////////////////////////
void print_error(int error, int line, char *file);

////////////////////////////////////////////////////////////
/// \brief Check all the possible errors in a champion.
///
/// \param file File_t structure which contains all the champions.
///
/// \return On sucess, return 0. On error, return 1 and set 'error' to 1.
///
////////////////////////////////////////////////////////////
int error_in_champ(file_t *file);

////////////////////////////////////////////////////////////
/// \brief Check if a line contains a label and if it's valid or not.
///
/// \param file File_t structure.
///
/// \param line Line in which to search the label.
///
/// \return On sucess, return the start index of the label. On error, return -1.
///
////////////////////////////////////////////////////////////
int check_label(file_t *file, char *line);

////////////////////////////////////////////////////////////
/// \brief Check if there is multiple definitions of the same label.
///
/// \param file File_t structure which contains all the labels.
///
/// \param str String of the label to search.
///
/// \return On sucess, return 0. On error, return 1 and set 'error' to 1.
///
////////////////////////////////////////////////////////////
int label_error(file_t *file, char *str);

////////////////////////////////////////////////////////////
/// \brief Destroyer of a command_t structure.
///        This function can be specified in the 'remove_node' function.
///
/// \param arg Pointer to a command_t structure.
///
////////////////////////////////////////////////////////////
void free_command(void *arg);

#endif
