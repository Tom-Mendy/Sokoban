/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-tom.mendy
** File description:
** get_list_size
*/

#include <stdlib.h>
#include "../include/my_linked_list.h"

int get_list_size(elt_t * list)
{
    elt_t *node = list;
    int count = 0;

    for (; node; node = node->next){
        count += 1;
    }
    return count;
}
