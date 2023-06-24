/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-sokoban-tom.mendy
** File description:
** destroy
*/

#include "my_sokoban.h"

void destroy_fonc(char ***map, storage_t *storage, int *storage_int_tab)
{
    for (int i = 0; i < storage_int_tab[1]; i += 1)
        free((*map)[i]);
    free(*map);
    free((*storage).hole);
    free((*storage).box);
}
