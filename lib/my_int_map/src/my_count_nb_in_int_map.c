/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** my_count_nb_in_int_map
*/

static int my_count_nb_in_int_map_sub(int const * const * const map,
int const i, int *count_char, int const c)
{
    if (!map || !*map | !count_char)
        return -1;
    for (int j = 0; map[i][j] != -1; j += 1) {
        if (map[i][j] == c)
            *count_char += 1;
    }
    return 0;
}

int my_count_nb_in_int_map(int const * const * const map, int const c)
{
    int count_char = 0;

    if (!map || !*map)
        return -1;
    for (int i = 0; map[i]; i += 1) {
        if (my_count_nb_in_int_map_sub(map, i, &count_char, c) == -1)
            return -1;
    }
    return count_char;
}
