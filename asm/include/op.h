/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-paulin.leclercq
** File description:
** op
*/

/// @file op.h
/// @brief Header file about corewar informations.
///        Details the sytax and content of a champion and its operations.

#ifndef _OP_H_
    #define _OP_H_

/// \brief Maximum number of arguments
    #define MAX_ARGS_NUMBER 4

/// \brief Character to indicate the start of a comment
    #define COMMENT_CHAR '#'
/// \brief Character to indicate the start of a label
    #define LABEL_CHAR ':'
/// \brief Character to indicate the start of a direct argument
    #define DIRECT_CHAR '%'
/// \brief Character to separate arguments
    #define SEPARATOR_CHAR ','

/// \brief Characters that a label can contain
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

/// \brief Command to indicate the champion's name
    #define NAME_CMD_STRING ".name"
/// \brief Command to indicate the champion's comment
    #define COMMENT_CMD_STRING ".comment"

/// \brief Maximum number of registers
    #define REG_NUMBER 16 // r1 <--> rx

typedef char args_type_t;

/// \brief Define for a register argument
    #define T_REG 1
/// \brief Define for a direct argument
    #define T_DIR 2
/// \brief Define for an indirect argument
    #define T_IND 4

/// \brief op_t structure (different operations)
typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;

/// \brief Number of bytes for an indirect
    #define IND_SIZE 2
/// \brief Number of bytes for a direct
    #define DIR_SIZE 4
/// \brief Number of bytes for a register
    #define REG_SIZE 1

/// \brief Maximum size of the champion's name
    #define PROG_NAME_LENGTH 128
/// \brief Maximum size of the champion's comment
    #define COMMENT_LENGTH 2048
/// \brief Hexadecimal number to write at the start of the .cor file
    #define COREWAR_EXEC_MAGIC 0xea83f3

/// \brief Header_t structure
///        (contains the major informations about the champion)
typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

/// \brief Array of every possible operations
///        (see op_t structure for more details)
static const op_t op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
    "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
    "ou (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
    "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
    "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
    "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
    "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
};

#endif
