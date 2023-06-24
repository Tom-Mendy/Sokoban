/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-sokoban-tom.mendy
** File description:
** end_condition
*/

#include "my_sokoban.h"

static void count_box_on_hole_fonc(storage_t storage, int *count_box_on_hole,
int i, int j)
{
    if (storage.box[i].x == storage.hole[j].x && storage.box[i].y ==
        storage.hole[j].y) {
        *count_box_on_hole += 1;
    }
}

static int count_locked_box_fonc(storage_t storage, char **map, int i)
{
    int tab_coordonate[8] = {1, 0, 0, -1, -1, 0, 0, 1};
    int tab_result[4] = {0, 0, 0, 0};
    for (int k = 0; k < 4; k += 1) {
        if ((map[storage.box[i].y + tab_coordonate[k * 2 + 1]]
        [storage.box[i].x + tab_coordonate[k * 2]]) == '#'){
            tab_result[k] = 1;
        }
    }
    if ((tab_result[0] == 1 && tab_result[1] == 1) || (tab_result[1] == 1 &&
    tab_result[2] == 1) || (tab_result[2] == 1 && tab_result[3] == 1) ||
    (tab_result[3] == 1 && tab_result[0] == 1))
        return 1;
    return 0;
}

int end_fonc(storage_t storage, char **map, int *storage_int_tab)
{
    int count_box_on_hole = 0;
    int count_box_lock = 0;
    for (int i = 0; i < storage_int_tab[2]; i += 1) {
        for (int j = 0; j < storage_int_tab[2]; j += 1) {
            count_box_on_hole_fonc(storage, &count_box_on_hole, i, j);
        }
    }
    if (storage_int_tab[2] == count_box_on_hole)
        return 0;
    for (int i = 0; i < storage_int_tab[2]; i += 1) {
        count_box_lock += count_locked_box_fonc(storage, map, i);
    }
    if (storage_int_tab[2] == count_box_lock)
        return 1;
    return -1;
}
