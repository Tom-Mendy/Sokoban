/*
** EPITECH PROJECT, 2023
** my_str_len
** File description:
** counts and returns the number of characters found in the string
*/

int my_str_len(char const * str)
{
    if (!str)
        return -1;
    int i = 0;
    for (; str[i] != '\0'; i += 1);
    return i;
}
