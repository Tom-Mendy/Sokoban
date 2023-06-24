/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** test_my_load_file_in_memory
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_str.h"

void redirect_my_load_file_in_memory_stdout(void)
{
    cr_redirect_stdout();
}

Test(my_load_file_in_memory, null_filename) {
    char *result = my_load_file_in_memory(NULL);
    cr_assert_null(result, "Expected NULL but got %s", result);
}

Test(my_load_file_in_memory, non_existent_file) {
    char *result = my_load_file_in_memory("non-existent-file.txt");
    cr_assert_null(result, "Expected NULL but got %s", result);
}

Test(my_load_file_in_memory, file) {
    char *result = my_load_file_in_memory("Makefile");
    cr_assert_not_null(result, "Expected non-NULL but got NULL");
}
