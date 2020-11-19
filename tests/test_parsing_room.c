/*
** EPITECH PROJECT, 2019
** tests_parsing_room
** File description:
** tests_parsing_room
*/

#include "lemin.h"

Test(parsing_room, is_get_map_state_changed_link, .init = redirect_all_std)
{
    char *str = my_strcpy("2-5");

    cr_assert(is_get_map_state_changed(str));
    free(str);
}

Test(parsing_room, is_get_map_state_changed_not_link, .init = redirect_all_std)
{
    char *str = my_strcpy("2 2 5");

    cr_assert(!is_get_map_state_changed(str));
    free(str);
}
