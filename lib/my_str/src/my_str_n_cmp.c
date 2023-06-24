/*
** EPITECH PROJECT, 2023
** my_str_n_cmp
** File description:
** function compares the two strings s1 and s2
*/

int my_str_n_cmp(char const *s1, char const *s2, int n)
{
    if (!s1 || !s2)
        return -1;
    for (int i = 0; (s1[i] != '\0' || s2[i] != '\0') && n > i; i += 1){
        if (s1[i] - s2[i] != 0)
            return 1;
    }
    return 0;
}
