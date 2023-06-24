/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** my_load_file_in_array
*/

#include <stdlib.h>
#include "../include/my_str.h"
#include "../include/spliter.h"

char **my_load_file_in_array(const char *filename)
{
    if (!filename)
        return NULL;
    char *str = my_load_file_in_memory(filename);
    if (str == NULL)
        return NULL;
    char **array = spliter(str, "\n");
    free(str);
    return array;
}
