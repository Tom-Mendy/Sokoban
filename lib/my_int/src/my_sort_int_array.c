/*
** EPITECH PROJECT, 2023
** my_sort_int_array
** File description:
** sorts an integer array in ascending order
*/

#include "../../../include/my_macro.h"
#include <stdlib.h>

static int final(int * array, int * i, int * j)
{
    int temp = 0;

    if (!array || !i || !j)
        return KO;
    if (array[*i] > array[*j + *i]){
        temp = array[*i];
        array[*i] = array[*j + *i];
        array[*j + *i] = temp;
    }
    return OK;
}

static int sub_loop(int * array, int *i, int size)
{
    if (!array || !i)
        return KO;
    for (int j = 1; j < size - *i; j += 1){
        if (final(array, i, &j) == KO)
            return KO;
    }
    return OK;
}

int my_sort_int_array(int * array, int size)
{
    if (size < 1 || array == NULL)
        return -1;
    for (int i = 0; i < size - 1; i += 1){
        if (sub_loop(array, &i, size) == KO)
            return KO;
    }
    return OK;
}
