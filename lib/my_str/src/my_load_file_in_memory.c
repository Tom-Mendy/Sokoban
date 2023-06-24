/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** my_load_file_in_memory
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my_str.h"
#include "../../../include/my_macro.h"

static void add_fragment_to_end_str_sub(char **str_base, char *fragment, int
nb_to_copy, int len_str)
{
    for (int i = 0; i < nb_to_copy; i += 1) {
        (*str_base)[len_str + i] = fragment[i];
    }
    (*str_base)[len_str + nb_to_copy] = '\0';
}

static int add_str_to_end_str(char **str_base, char *fragment, int nb_to_copy)
{
    int len_str = 0;
    char *save_str = NULL;

    if (!str_base || !(*str_base) || !fragment || nb_to_copy < 0)
        return KO;
    len_str = my_str_len((*str_base));
    if (len_str == -1)
        len_str = 0;
    save_str = malloc(sizeof(char) * (len_str + 1));
    if (!save_str)
        return KO;
    my_str_cpy(save_str, (*str_base));
    free((*str_base));
    (*str_base) = malloc(sizeof(char) * (len_str + nb_to_copy + 1));
    if (!(*str_base))
        return KO;
    my_str_cpy((*str_base), save_str);
    add_fragment_to_end_str_sub(str_base, fragment, nb_to_copy, len_str);
    free(save_str);
    return OK;
}

static int if_error_close_fd(void *function, void *value, int *fd)
{
    if (function == value) {
        return KO;
        close((*fd));
    }
    return OK;
}

int my_load_file_in_memory_sub(int *nread, char *buffer, char **result_str,
int *fd)
{
    if (!nread || !buffer || !result_str || !fd)
        return KO;
    if ((*nread) == -1) {
        close((*fd));
        return KO;
    }
    if (add_str_to_end_str(result_str, buffer, (*nread)) == KO) {
        close((*fd));
        return KO;
    }
    return OK;
}

char *my_load_file_in_memory(const char *filename)
{
    int fd = 0;
    if (!filename)
        return NULL;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return NULL;
    char *result_str = malloc(sizeof(char) * (1));
    if (if_error_close_fd(result_str, NULL, &fd))
        return NULL;
    result_str[0] = '\0';
    int nread = 1;
    char buffer[100];
    while ((nread = read(fd, buffer, 100)) != 0) {
        if (my_load_file_in_memory_sub(&nread, buffer, &result_str, &fd) == 84)
            return NULL;
    }
    close(fd);
    return result_str;
}
