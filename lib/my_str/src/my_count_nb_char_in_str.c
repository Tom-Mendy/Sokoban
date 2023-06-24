/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** my_count_nb_char_in_str
*/

#include <stdlib.h>

int my_count_nb_char_in_str(char *str, char spe_char)
{
    int nb_word = 0;
    if (!str)
        return -1;
    for (int k = 0; str[k + 1] != '\0'; k += 1){
        if (str[k] == spe_char && str[k + 1] != spe_char)
            nb_word += 1;
    }
    return nb_word;
}
