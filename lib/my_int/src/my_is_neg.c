/*
** EPITECH PROJECT, 2023
** my_is_neg
** File description:
** display positive or negative
*/

#include "../../my_str/include/my_str.h"

int my_is_neg(int n)
{
    if (n >= 0){
        if (my_put_char('P') == -1)
            return -1;
    } else {
        if (my_put_char('N') == -1)
            return -1;
    }
    return 0;
}
