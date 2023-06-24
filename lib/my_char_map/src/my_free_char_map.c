/*
** EPITECH PROJECT, 2023
** create map
** File description:
** create_map
*/

#include "../../../include/my_macro.h"
#include <stdlib.h>

int my_free_char_map(char **map)
{
    if (!map)
        return OK;
    for (int i = 0; map[i]; i += 1){
        free(map[i]);
    }
    free(map);
    return OK;
}
