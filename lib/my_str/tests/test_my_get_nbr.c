/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** test_my_get_nbr
*/

#include <criterion/criterion.h>
#include "my_str.h"

int my_get_nbr(char const *str);

Test(my_get_nbr, string_starts_with_letter_and_continues_with_number) {
    cr_assert_eq(my_get_nbr("a123"), 0);
}

Test(my_get_nbr, number_with_positive_sign) {
    cr_assert_eq(my_get_nbr("+123"), 123);
}

Test(my_get_nbr, number_with_negative_sign) {
    cr_assert_eq(my_get_nbr("-123"), -123);
}
