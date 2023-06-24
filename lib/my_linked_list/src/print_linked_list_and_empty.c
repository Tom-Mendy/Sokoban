/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-myls-tom.mendy
** File description:
** print_linked_list_and_empty
*/

#include <stdlib.h>
#include "../include/my_linked_list.h"
#include "../../my_str/include/my_str.h"
#include "../../my_int/include/my_int.h"
#include "../../../include/my_macro.h"

int print_linked_list_and_empty(elt_t **list)
{
    int i = 0;

    if (!list)
        return KO;
    for (; *list; i += 1) {
        if (my_put_nbr((*list)->data) == -1)
            return KO;
        if (my_put_str("  ") == -1)
            return KO;
        elt_t *temp = *list;
        *list = (*list)->next;
        free(temp);
    }
    if (i > 0)
        if (my_put_char('\n') == -1)
            return KO;;
    return OK;
}
