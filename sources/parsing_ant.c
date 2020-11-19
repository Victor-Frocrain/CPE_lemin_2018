/*
** EPITECH PROJECT, 2019
** parsing_ant.c
** File description:
** parsing_ant.c
*/

#include "lemin.h"

bool get_nb_ant(ant_t *ant)
{
    char *str = manage_input(true, false, false);

    ant->nb_ant = -1;
    if (str && is_int(str)) {
        ant->nb_ant = my_getnbr(str);
        if (ant->nb_ant <= 0)
            my_puterror("Error: The number of ants need to be > 0\n");
        else
            return (false);
    } else if (str)
        my_puterror("Error: The number of ants need to be an int\n");
    return (true);
}
