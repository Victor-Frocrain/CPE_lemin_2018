/*
** EPITECH PROJECT, 2019
** parser.c
** File description:
** parser.c
*/

#include "lemin.h"

bool is_int(char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (false);
    return (true);
}

bool is_node_value_correct(chain_list_t *chain_list, int x, int y, char *id)
{
    for (list_t *list = chain_list->node_start; list;
    list = list->node_next) {
        if (list && list->id && id && my_strcmp(list->id, id)) {
            my_puterror("Error: This id is already used\n");
            return (false);
        }
        if (list && list->x == x && list->y == y) {
            my_puterror("Error: This position is already used\n");
            return (false);
        }
    }
    return (true);
}

bool is_input_correct(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == ' ' && str[i - 1] && str[i - 1] != ' ' && str[i + 1]) {
            str[i] = 0;
            count++;
        }
    if (count != 2) {
        my_puterror("Error: the input is incorrect should \
have 3 arguments\n");
        return (false);
    }
    return (true);
}

bool is_node(char *str, chain_list_t *chain_list)
{
    int *pos = malloc(sizeof(int) * 2);

    if (!is_input_correct(str))
        return (false);
    for (int i = 0, j = my_strlen(str); i < 2 && pos; i++,
    j += my_strlen(str + j + 1) + 1) {
        if (is_int(str + j + 1))
            pos[i] = my_getnbr(str + j + 1);
        else {
            my_puterror("Error: the two last value of a room need to be int\n");
            return (false);
        }
    }
    if (!pos || !is_node_value_correct(chain_list, pos[0], pos[1], str))
        return (false);
    free(pos);
    return (true);
}
