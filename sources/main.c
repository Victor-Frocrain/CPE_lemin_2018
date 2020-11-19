/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "lemin.h"

int main(int ac, char **av)
{
    if (ac != 1 || av[1])
        return (MY_ERROR);
    return (lemin());
}
