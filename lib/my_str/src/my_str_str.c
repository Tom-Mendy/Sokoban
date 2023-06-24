/*
** EPITECH PROJECT, 2023
** my_str_str
** File description:
** function finds the first occurrence of the substring
*/

#include <stdlib.h>
#include "../../my_str/include/my_str.h"

char *my_str_str(char *str, char const *to_find)
{
    int len_find = 0;
    int len = 0;

    if (!str || !to_find)
        return NULL;
    len_find = my_str_len(to_find);
    len = my_str_len(str) - len_find;
    for (int i = 0; i <= len; i += 1){
        if (my_str_n_cmp(&str[i], to_find, len_find) == 0){
            return &str[i];
        }
    }
    return str;
}
