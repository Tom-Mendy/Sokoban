/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-sokoban-tom.mendy
** File description:
** help
*/

#include <unistd.h>

int help(void)
{
    write(1,"USAGE\n", 6);
    write(1,"\t./my_sokoban map\n", 18);
    write(1,"DESCRIPTION\n", 12);
    write(1,"\tmap file representing the warehouse map, containing '#' \
for walls,\n\t'P' for the player, 'X' for boxes and 'O' for storage locations.\
\n", 135);
    return 0;
}
