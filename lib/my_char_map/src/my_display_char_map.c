/*
** EPITECH PROJECT, 2023
** create map
** File description:
** create_map
*/

#include "../../../include/my_macro.h"
#include "../../my_str/include/my_str.h"

int my_display_char_map(char const * const * map)
{
    if (!map)
        return KO;
    for (int i = 0; map[i]; i += 1) {
        if (my_put_str(map[i]) == -1)
            return KO;
        if (my_put_char('\n') == -1)
            return KO;
    }
    return OK;
}
