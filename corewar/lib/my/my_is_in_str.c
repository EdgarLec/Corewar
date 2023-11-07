/*
** EPITECH PROJECT, 2021
** my_is_in_str.c
** File description:
** my_is_in_str
*/

int is_in_str(char to_find, char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (to_find == str[i])
            return 1;
    }
    return 0;
}
