/*
** EPITECH PROJECT, 2023
** create map
** File description:
** display_int_map
*/

#include "../../../include/my_macro.h"
#include "../../my_int/include/my_int.h"
#include "../../my_str/include/my_str.h"

int display_int_map_sub(int const * const * const map, int i)
{
    for (int j = 0; map[i][j] != -1; j += 1) {
        if (my_put_nbr(map[i][j]) == -1)
            return KO;
    }
    return OK;
}

int my_display_int_map(int const * const * const map)
{
    if (!map)
        return KO;
    for (int i = 0; map[i]; i += 1) {
        if (display_int_map_sub(map, i) == KO)
            return KO;
        if (my_put_char('\n') == -1)
            return KO;
    }
    return OK;
}
