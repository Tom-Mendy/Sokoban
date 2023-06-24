/*
** EPITECH PROJECT, 2023
** my_str_is_printable
** File description:
** a function that returns 1 if the string passed
** as parameter only contains printable
** characters and 0 otherwise
*/

#include "../include/my_str.h"

int my_str_is_printable(char const *str)
{
    if (!str)
        return -1;
    for (int i = 0; str[i] != '\0'; i += 1){
        if (my_is_printable(str[i]) == 0)
            return 0;
    }
    return 1;
}
