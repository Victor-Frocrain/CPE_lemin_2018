/*
** EPITECH PROJECT, 2019
** parsing_room.c
** File description:
** parsing_room.c
*/

#include "lemin.h"

bool is_get_map_state_changed(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ')
            return (false);
        if (str[i] == '-' && (str[i + 1] || i > 0))
            return (true);
    }
    return (false);
}

bool get_room(ant_t *ant)
{
    bool is_start = false;
    bool is_end = false;
    char *str = manage_input(false, is_start, is_end);
    bool is_error = false;

    for (; str && !is_error && !is_get_map_state_changed(str);
    free(str), str = manage_input(false, is_start, is_end)) {
        if (str && !is_start && !is_error && my_strcmp(str, "##start")) {
            is_error = fill_first_node(ant->chain_list);
            is_start = true;
        } else if (str && !is_end && !is_error && my_strcmp(str, "##end")) {
            is_error = fill_last_node(ant->chain_list);
            is_end = true;
        } else if (str && !is_error)
            is_error = fill_node(ant->chain_list, str);
    }
    if (!is_start || !is_end)
        return (true);
    if (!is_error)
        ant->first_link = str;
    return (is_error);
}
