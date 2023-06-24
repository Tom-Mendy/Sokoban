/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-sokoban-tom.mendy
** File description:
** display
*/

#include "my_sokoban.h"

void display_map(char **map, storage_t *storage, WINDOW **mainwin, \
    int *storage_int_tab)
{
    if (COLS < storage_int_tab[0] || LINES < storage_int_tab[1])
        mvwaddstr(*mainwin, 0, 0, "window too small");
    else {
        for (int i = 0; i < storage_int_tab[1]; i += 1)
            mvwaddstr(*mainwin, i, 0, map[i]);
        for (int i = 0; i < storage_int_tab[2]; i += 1)
            mvwaddstr(*mainwin, storage->hole[i].y, storage->hole[i].x, "O");
        for (int i = 0; i < storage_int_tab[2]; i += 1)
            mvwaddstr(*mainwin, storage->box[i].y, storage->box[i].x, "X");
        mvwaddstr(*mainwin, storage->player.y, storage->player.x, "P");
    }
    wrefresh(*mainwin);
    refresh();
}
