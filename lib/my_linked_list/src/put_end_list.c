/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-tom.mendy
** File description:
** put_end_list
*/

#include <stdlib.h>
#include "../include/my_linked_list.h"
#include "../../../include/my_macro.h"

static int append_to_list(elt_t *node, list_type_t value)
{
    if (!node)
        return KO;
    while (node->next) {
        node = node->next;
    }
    node->next = malloc(sizeof(elt_t));
    if (!node->next)
        return KO;
    node->next->data = value;
    node->next->next = NULL;
    node->next->prev = node;
    return OK;
}

int put_end_list(elt_t **list, list_type_t value)
{
    elt_t *node = NULL;

    if (!list)
        return KO;
    node = *list;
    if (node) {
        if (append_to_list(node, value) == 84)
            return KO;
    } else {
        (*list) = malloc(sizeof(elt_t));
        if (!(*list))
            return KO;
        (*list)->data = value;
        (*list)->next = NULL;
        (*list)->prev = NULL;
    }
    return OK;
}
