/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-sokoban-tom.mendy
** File description:
** little_fonc
*/

#include "my_sokoban.h"

int argc_from_argv(char const *const *const argv)
{
    int i = 0;
    while (argv[i] != NULL)
        i += 1;
    return i;
}
