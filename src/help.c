/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-sokoban-tom.mendy
** File description:
** help
*/

#include "../include/my_sokoban.h"

int help(void)
{
    if (my_put_str("USAGE\n") == -1)
        return 84;
    if (my_put_str("\t./my_sokoban map\n") == -1)
        return 84;
    if (my_put_str("DESCRIPTION\n") == -1)
        return 84;
    if (my_put_str("\tmap file representing the warehouse map, containing '#' \
for walls,\n") == -1)
        return 84;
    if (my_put_str("\t'P' for the player, 'X' for boxes and 'O' for storage \
locations.\n") == -1)
        return 84;
    if (my_put_str("KEYMAP\n") == -1)
        return 84;
    if (my_put_str("\t←↑↓→ to move the P\n") == -1)
        return 84;
    if (my_put_str("\tSPACE to reset the map to original state\n") == -1)
        return 84;
    return 0;
}
