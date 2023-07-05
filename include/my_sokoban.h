/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-sokoban-tom.mendy
** File description:
** my_sokoban
*/

#ifndef MY_SOKOBAN_H_
    #define MY_SOKOBAN_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <ncurses.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/syscall.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include "../lib/my_str/include/my_str.h"
    #include "../lib/my_str/include/spliter.h"
    typedef struct position{
        int x;
        int y;
        int start_x;
        int start_y;
    }position_t;
    typedef struct storage{
        position_t player;
        position_t *box;
        position_t *hole;
    }storage_t;
    int sokoban(char const * const map_filename);
    int catch_map(char ***map, int *cols_lines, char const * const \
    map_filename, int *nb_pos_box);
    void display_map(char **map, storage_t *storage, WINDOW **mainwin,\
    int *temp_tab);
    int argc_from_argv(char const *const *const argv);
    void destroy_fonc(char ***map, storage_t *storage, int *storage_int_tab);
    int move_player(char **map, int *storage_int_tab, storage_t *storage,\
    int *x_y_variation);
    void check_key_press(char **map, int *storage_int_tab, \
    storage_t *storage, int ch);
    void get_positions(char ***map, int *cols_lines, storage_t *storage);
    int end_fonc(storage_t storage, char **map, int *storage_int_tab);
    int help(void);
#endif /* !MY_SOKOBAN_H_ */
