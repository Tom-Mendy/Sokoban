/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** my_int_line_len
*/

int my_int_line_len(int const * const int_line)
{
    int i = 0;

    if (!int_line)
        return -1;
    for (; int_line[i] != -1; i++);
    return i;
}
