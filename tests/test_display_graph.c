/*
** EPITECH PROJECT, 2019
** tests_display_graph.c
** File description:
** tests_display_graph.c
*/

#include "lemin.h"

Test(display_graph, display_tunnels, .init = redirect_all_std)
{
    char **tunnels = malloc(sizeof(char *));

    tunnels[0] = malloc(sizeof(char));
    display_tunnels(tunnels);
    cr_assert_stderr_eq_str("");
}
