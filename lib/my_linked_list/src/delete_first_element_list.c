/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-tom.mendy
** File description:
** delete_first_element_list
*/

#include <stdlib.h>
#include "../include/my_linked_list.h"
#include "../../../include/my_macro.h"

int delete_first_element_list(elt_t **list)
{
    elt_t *e1 = NULL;
    elt_t *e2 = NULL;

    if (!list)
        return KO;
    e1 = *list;
    e2 = e1->next;
    free(e1);
    *list = e2;
    if (e2 != NULL)
        e2->prev = NULL;
    return OK;
}
