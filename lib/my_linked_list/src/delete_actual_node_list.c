/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-tom.mendy
** File description:
** delete_actual_node_list
*/

#include "../../../include/my_macro.h"
#include "../include/my_linked_list.h"
#include <stdlib.h>

int delete_actual_node_list(elt_t *list)
{
    elt_t *prev_node = NULL;
    elt_t *next_node = NULL;

    if (!list)
        return KO;
    prev_node = list->prev;
    next_node = list->next;
    prev_node->next = list->next;
    next_node->prev = list->prev;
    free(list);
    return OK;
}
