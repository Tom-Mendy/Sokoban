/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-sokoban-tom.mendy
** File description:
** get_position_sub
*/

#include "my_sokoban.h"

static void get_positions_player(char ***map, storage_t *storage, int *temp_tab)
{
    if ((*map)[temp_tab[2]][temp_tab[3]] == 'P') {
        (storage->player).x = temp_tab[3];
        (storage->player).y = temp_tab[2];
        (storage->player).start_x = temp_tab[3];
        (storage->player).start_y = temp_tab[2];
        (*map)[temp_tab[2]][temp_tab[3]] = ' ';
    }
}

static void get_positions_sub(char ***map, storage_t *storage, int *temp_tab)
{
    get_positions_player(map, storage, temp_tab);
    if ((*map)[temp_tab[2]][temp_tab[3]] == 'O') {
        (storage->hole[temp_tab[0]]).x = temp_tab[3];
        (storage->hole[temp_tab[0]]).y = temp_tab[2];
        (storage->hole[temp_tab[0]]).start_x = temp_tab[3];
        (storage->hole[temp_tab[0]]).start_y = temp_tab[2];
        temp_tab[0] += 1;
        (*map)[temp_tab[2]][temp_tab[3]] = ' ';
    }
    if ((*map)[temp_tab[2]][temp_tab[3]] == 'X') {
        (storage->box[temp_tab[1]]).x = temp_tab[3];
        (storage->box[temp_tab[1]]).y = temp_tab[2];
        (storage->box[temp_tab[1]]).start_x = temp_tab[3];
        (storage->box[temp_tab[1]]).start_y = temp_tab[2];
        temp_tab[1] += 1;
        (*map)[temp_tab[2]][temp_tab[3]] = ' ';
    }
}

/**
 * int *temp_tab[4];
 * temp_tab[0] = count_hole;
 * temp_tab[1] = count_box;
 * temp_tab[2] = i;
 * temp_tab[3] = j;
 */
void get_positions(char ***map, int *cols_lines, storage_t *storage)
{
    int temp_tab[4];
    temp_tab[0] = 0;
    temp_tab[1] = 0;
    for (int i = 0; i < cols_lines[1]; i += 1) {
        for (int j = 0; j < cols_lines[0]; j += 1) {
            temp_tab[2] = i;
            temp_tab[3] = j;
            get_positions_sub(map, storage, temp_tab);
        }
    }
}
