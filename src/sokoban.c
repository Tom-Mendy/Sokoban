/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-bssokoban-tom.mendy
** File description:
** popup
*/

#include "../include/my_sokoban.h"

static int loop(WINDOW **mainwin, char **map, int *storage_int_tab, \
    storage_t *storage)
{
    int ch;
    int result = 0;
    while ((result = end_fonc(*storage, map, storage_int_tab)) == -1) {
        ch = getch();
        if (COLS >= storage_int_tab[0] && LINES >= storage_int_tab[1])
            check_key_press(map, storage_int_tab, storage, ch);
        clear();
        display_map(map, storage, mainwin, storage_int_tab);
    }
    return result;
}

static int init_ncurses(WINDOW **mainwin)
{
    if ((*mainwin = initscr()) == NULL) {
        write(2, "Error initialising ncurses.\n", 29);
        return 84;
    }
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    return 0;
}

static int return_fonc(int result)
{
    if (result == 1)
        return 1;
    usleep(5);
    return 0;
}

int sokoban(char const * const map_filename)
{
    char **map = NULL;
    int storage_int_tab[3] = { 0 };
    storage_t storage;
    if (catch_map(&map, storage_int_tab, map_filename, &storage_int_tab[2]) == 84)
        return 84;
    storage.hole = malloc(sizeof(position_t) * storage_int_tab[2]);
    storage.box = malloc(sizeof(position_t) * storage_int_tab[2]);
    get_positions(&map, storage_int_tab, &storage);
    WINDOW *mainwin;
    if (init_ncurses(&mainwin) == 84)
        return 84;
    display_map(map, &storage, (&mainwin), storage_int_tab);
    int result = loop(&mainwin, map, storage_int_tab, &storage);
    delwin(mainwin);
    endwin();
    refresh();
    destroy_fonc(&map, &storage, storage_int_tab);
    return return_fonc(result);
}
