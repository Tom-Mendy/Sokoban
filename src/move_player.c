/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-sokoban-tom.mendy
** File description:
** move_player
*/

#include "my_sokoban.h"

static void move_player_ter(char **map, int i, storage_t *storage,
    int *x_y_variation)
{
    if (map[storage->box[i].y + x_y_variation[1]][storage->box[i].x +
        x_y_variation[0]] == ' ') {
        storage->box[i].y += x_y_variation[1];
        storage->player.y += x_y_variation[1];
        storage->box[i].x += x_y_variation[0];
        storage->player.x += x_y_variation[0];
    }
}

static int move_player_sub(char **map, int *storage_int_tab, storage_t *storage,
    int *x_y_variation)
{
    int present_x = 0;
    for (int i = 0; i < storage_int_tab[2]; i += 1) {
        if (storage->player.y + x_y_variation[1] == storage->box[i].y &&
            storage->box[i].x == storage->player.x + x_y_variation[0]) {
            present_x = 1;
            move_player_ter(map, i, storage, x_y_variation);
        }
    }
    if (present_x == 0) {
        storage->player.y += x_y_variation[1];
        storage->player.x += x_y_variation[0];
    }
    return 0;
}

int move_player(char **map, int *storage_int_tab, storage_t *storage,
    int *x_y_variation)
{
    if (map[storage->player.y + x_y_variation[1]][storage->player.x +
        x_y_variation[0]] != '#') {
        move_player_sub(map, storage_int_tab, storage, x_y_variation);

    }
    return 0;
}
