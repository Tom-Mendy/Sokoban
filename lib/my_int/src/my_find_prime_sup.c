/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** function that returns the smallest prime number
*/

#include "../include/my_int.h"

int my_find_prime_sup(int nb)
{
    int result = -1;

    if ((nb < -2147483648) || (nb > 2147483647))
        return 0;
    if (nb <= 0)
        nb = 2;
    for (; result == -1; nb += 1){
        if (my_is_prime(nb) == 1)
            result = nb;
    }
    return result;
}
