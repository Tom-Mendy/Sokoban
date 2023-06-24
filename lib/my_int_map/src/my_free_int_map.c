/*
** EPITECH PROJECT, 2023
** free_int_map
** File description:
** free_int_map
*/

#include "../../../include/my_macro.h"
#include <stdlib.h>

int my_free_int_map(int **map)
{
    if (!map)
        return OK;
    for (int i = 0; map[i]; i += 1){
        free(map[i]);
    }
    free(map);
    return OK;
}
