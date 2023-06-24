/*
** EPITECH PROJECT, 2023
** my_str_low_case
** File description:
** function that puts every letter of every word in it in lowercase
*/

int my_str_low_case(char *str)
{
    if (!str)
        return -1;
    for (int i = 0; str[i] != '\0'; i += 1){
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return 0;
}
