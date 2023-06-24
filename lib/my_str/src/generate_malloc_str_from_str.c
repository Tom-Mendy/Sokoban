/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** toto
*/

#include <stdlib.h>
#include "../include/my_str.h"

char *generate_malloc_str_from_str(char const *const str)
{
    char *str_malloc = NULL;
    if (!str)
        return NULL;
    str_malloc = malloc(sizeof(char) * (my_str_len(str) + 1));
    if (!str_malloc)
        return NULL;
    if (my_str_cpy(str_malloc, str) == -1) {
        free(str_malloc);
        return NULL;
    }
    return str_malloc;
}
