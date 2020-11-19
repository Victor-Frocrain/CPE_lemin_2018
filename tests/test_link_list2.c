/*
** EPITECH PROJECT, 2019
** tests_link_list.c
** File description:
** tests_link_list.c
*/

#include "lemin.h"

Test(link_list, link_list_same_id, .init = redirect_all_std)
{
    list_t *list = malloc(sizeof(list_t));
    list_t *list2 = malloc(sizeof(list_t));
    chain_list_t *chain_list = malloc(sizeof(chain_list_t));

    list->id = "3";
    list2->id = "3";
    chain_list->node_start = list;
    list->node_next = list2;
    cr_assert(link_list(chain_list, "3", "3"));
    cr_assert_stderr_eq_str("Error: you can't link a room to herself\n");
    free(list);
    free(list2);
    free(chain_list);
}

Test(link_list, link_list, .init = redirect_all_std)
{
    list_t *list = malloc(sizeof(list_t));
    list_t *list2 = malloc(sizeof(list_t));
    chain_list_t *chain_list = malloc(sizeof(chain_list_t));

    list->id = "3";
    list2->id = "4";
    chain_list->end = list2;
    chain_list->node_start = list;
    list->node_next = list2;
    list2->node_next = NULL;
    cr_assert(!link_list(chain_list, "3", "4"));
    free(list);
    free(list2);
    free(chain_list);
}

Test(link_list, find_id_in_chain_list, .init = redirect_all_std)
{
    list_t *list = malloc(sizeof(list_t));
    list_t *list2 = malloc(sizeof(list_t));
    chain_list_t *chain_list = malloc(sizeof(chain_list_t));
    list_t *new_list;

    list->id = "3";
    list2->id = "4";
    chain_list->node_start = list;
    list->node_next = list2;
    list2->node_next = NULL;
    new_list = find_id_in_chain_list(chain_list, "3");
    cr_assert_str_eq(new_list->id, list->id);
    new_list = find_id_in_chain_list(chain_list, "4");
    cr_assert_str_eq(new_list->id, list2->id);
    free(list);
    free(list2);
    free(chain_list);
}

Test(link_list, didnt_found_the_id, .init = redirect_all_std)
{
    list_t *list = malloc(sizeof(list_t));
    list_t *list2 = malloc(sizeof(list_t));
    chain_list_t *chain_list = malloc(sizeof(chain_list_t));

    list->id = "1";
    list2->id = "4";
    chain_list->end = list2;
    chain_list->node_start = list;
    list->node_next = list2;
    list2->node_next = NULL;
    cr_assert(link_list(chain_list, "3", "4"));
    cr_assert_stderr_eq_str("Error: didn't found the id: 3\n");
    free(list);
    free(list2);
    free(chain_list);
}
