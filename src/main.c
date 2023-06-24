/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-sokoban-tom.mendy
** File description:
** main
*/

#include "my_sokoban.h"

int main(const int argc, const char *argv[])
{
    if (argc != 2)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h' && my_str_len(argv[1]) == 2)
        return help();
    return sokoban(argv[1]);
}
