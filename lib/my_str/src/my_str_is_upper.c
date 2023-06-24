/*
** EPITECH PROJECT, 2023
** my_str_is_upper
** File description:
** function that returns 1 if the string passed
** as parameter only contains upper case alphabet
*/

#include "../include/my_str.h"

int my_str_is_upper(char const *str)
{
    if (!str)
        return -1;
    for (int i = 0; str[i] != '\0'; i += 1){
        if (my_is_upper(str[i]) == 0)
            return 0;
    }
    return 1;
}
