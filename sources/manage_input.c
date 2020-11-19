/*
** EPITECH PROJECT, 2019
** manage_input.c
** File description:
** manage_input.c
*/

#include "lemin.h"

char *remove_space(char *str, int ref)
{
    char *new_str = malloc(sizeof(char) * my_strlen(str));
    int j = 0;

    for (int i = 0; str && str[i]; i++) {
        if (i != ref)
            new_str[j++] = str[i];
        else if (str[i] == '#') {
            new_str[j++] = 0;
        }
    }
    new_str[j] = 0;
    free(str);
    return (new_str);
}

bool is_useless_char(char *str, int i)
{
    if (str[i] == '#' && i > 1)
        return (true);
    if (str[i] && (str[i] == ' ' || str[i] == '\t')
        && ((str[i + 1] && (str[i + 1] == ' ' ||
        str[i + 1] == '\t' || str[i + 1] == '#'))
        || !str[i + 1] || i == 0))
        return (true);
    return (false);
}

char *manage_input(bool isnt_room, bool is_start, bool is_end)
{
    char *str = get_next_line(0);

    while (str && str[0] && str[0] == '#' && (isnt_room ||
    (!isnt_room && !(my_strcmp(str, "##start") && !is_start) &&
    !(my_strcmp(str, "##end") && !is_end)))) {
        free(str);
        str = get_next_line(0);
    }
    for (int i = 0; str && str[i]; i++)
        if (is_useless_char(str, i))
            str = remove_space(str, i--);
    return (str);
}
