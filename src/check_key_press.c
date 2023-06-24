/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-sokoban-tom.mendy
** File description:
** check_key_press
*/

#include "my_sokoban.h"

static void reset_value(storage_t *storage, int *storage_int_tab)
{
    (storage->player).x = (storage->player).start_x;
    (storage->player).y = (storage->player).start_y;
    for (int i = 0; i < storage_int_tab[2]; i += 1) {
        (storage->hole[i]).x = (storage->hole[i]).start_x;
        (storage->hole[i]).y = (storage->hole[i]).start_y;
    }
    for (int i = 0; i < storage_int_tab[2]; i += 1) {
        (storage->box[i]).x = (storage->box[i]).start_x;
        (storage->box[i]).y = (storage->box[i]).start_y;
    }
}

static void check_key_press_sub(char **map, int *storage_int_tab, \
    storage_t *storage, int ch)
{
    int tmp[2];
    switch (ch) {
    case KEY_LEFT:
        tmp[0] = -1;
        tmp[1] = 0;
        move_player(map, storage_int_tab, storage, tmp);
        break;
    case KEY_RIGHT:
        tmp[0] = 1;
        tmp[1] = 0;
        move_player(map, storage_int_tab, storage, tmp);
        break;
    case ' ':
        reset_value(storage, storage_int_tab);
    }
}

void check_key_press(char **map, int *storage_int_tab, \
    storage_t *storage, int ch)
{
    int tmp[2];
    switch (ch) {
    case KEY_UP:
        tmp[0] = 0;
        tmp[1] = -1;
        move_player(map, storage_int_tab, storage, tmp);
        break;
    case KEY_DOWN:
        tmp[0] = 0;
        tmp[1] = 1;
        move_player(map, storage_int_tab, storage, tmp);
        break;
    default:
        check_key_press_sub(map, storage_int_tab, storage, ch);
    }
}
