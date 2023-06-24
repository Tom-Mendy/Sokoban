/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-sokoban-tom.mendy
** File description:
** obtain_map
*/

#include "my_sokoban.h"

static int check_buffer(char const *const buffer, int *nb_pos_box)
{
    int i = 0;
    int count_player = 0;
    int count_o = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] != '#' && buffer[i] != 'P' && buffer[i] != 'X' &&
            buffer[i] != 'O' && buffer[i] != ' ' && buffer[i] != '\n')
            return 84;
        if (buffer[i] == 'P')
            count_player += 1;
        if (buffer[i] == 'O')
            count_o += 1;
        if (buffer[i] == 'X')
            *nb_pos_box += 1;
        i += 1;
    }
    if ((count_player != 1) || (*nb_pos_box != count_o))
        return 84;
    return 0;
}

static void get_clos_lines(char const *const buffer, int *cols_lines)
{
    int i = 0;
    int index_max = 0;
    while (buffer[i] != '\0') {
        if ((buffer[i] == '\n') && (i - index_max > cols_lines[0])) {
            cols_lines[0] = i - index_max;
        }
        if (buffer[i] == '\n') {
            cols_lines[1] += 1;
            index_max = i;
        }
        i += 1;
    }
}

static void fill_map_sub(char ***map, char const *const buffer, int *storage)
{
    if (buffer[storage[1]] == '\n')
        storage[0] = 1;
    if (storage[0] == 0) {
        (*map)[storage[2]][storage[3]] = buffer[storage[1]];
        storage[1] += 1;
    } else
        (*map)[storage[2]][storage[3]] = '\0';
}

/*
int storage[4]
storage[0] = bool_backslash_n
storage[1] = index_buffer
storage[2] = i
storage[3] = j
*/
static int fill_map(char ***map, char const *const buffer, int const *const
cols_lines)
{
    int storage[4] = { 0 };
    (*map) = malloc(sizeof(char *) * cols_lines[1]);
    if ((*map) == NULL)
        return 84;
    for (int i = 0; i < cols_lines[1]; i += 1) {
        (*map)[i] = malloc(sizeof(char) * cols_lines[0]);
        if ((*map) == NULL)
            return 84;
        storage[0] = 0;
        for (int j = 0; j < (cols_lines[0] - 1); j += 1) {
            storage[2] = i;
            storage[3] = j;
            fill_map_sub(map, buffer, storage);
        }
        (*map)[i][cols_lines[0] - 1] = '\0';
        storage[1] += 1;
    }
    return 0;
}

int catch_map(char ***map, int *cols_lines, char const * const map_filename,
int *nb_pos_box)
{
    int fd = open(map_filename, O_RDONLY);
    if (fd == -1)
        return 84;
    struct stat s;
    stat(map_filename, &s);
    if ((s.st_mode & S_IFMT) != S_IFREG)
        return 84;
    char *buffer = malloc(sizeof(char) * s.st_size + 1);
    if (!buffer)
        return 84;
    read(fd, buffer, s.st_size);
    buffer[s.st_size] = '\0';
    if (check_buffer(buffer, nb_pos_box) == 84){return 84;}
    get_clos_lines(buffer, cols_lines);
    fill_map(map, buffer, cols_lines);
    free(buffer);
    return 0;
}
