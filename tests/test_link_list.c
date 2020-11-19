/*
** EPITECH PROJECT, 2019
** tests_link_list.c
** File description:
** tests_link_list.c
*/

#include "lemin.h"

Test(link_list, redefined_list, .init = redirect_all_std)
{
    list_t *list = malloc(sizeof(list_t));
    list_t *next_list = malloc(sizeof(list_t));

    list->next = malloc(sizeof(list_t *) * 3);
    for (int i = 0; i < 2; i++) {
        list->next[i] = malloc(sizeof(list_t));
        list->next[i]->id = "5";
        list->next[i]->x = 5 + i;
        list->next[i]->y = 2 + i;
    }
    list->next[2] = NULL;
    cr_assert(!redefined_list(list, 3, next_list));
    free(list);
    free(next_list);
}

Test(link_list, add_next_already_linked, .init = redirect_all_std)
{
    list_t *list = malloc(sizeof(list_t));
    list_t *list2 = malloc(sizeof(list_t));

    list->next = malloc(sizeof(list_t *) * 2);
    list->nb_link = 1;
    list->id = "2";
    list2->id = "4";
    list->next[0] = list2;
    list->next[1] = NULL;
    cr_assert(add_next(list, list2));
    cr_assert_stderr_eq_str("Error: the two rooms are already linked\n");
    free(list);
    free(list->next);
    free(list2);
}

Test(link_list, add_next_doesnt_linked, .init = redirect_all_std)
{
    list_t *list = malloc(sizeof(list_t));
    list_t *list2 = malloc(sizeof(list_t));
    list_t *list3 = malloc(sizeof(list_t));

    list->next = malloc(sizeof(list_t *) * 2);
    list->nb_link = 1;
    list->id = "2";
    list2->id = "4";
    list->next[0] = list3;
    list->next[1] = NULL;
    cr_assert(!add_next(list, list2));
    free(list);
    free(list->next);
    free(list2);
    free(list3);
}

Test(link_list, hadnt_link_next, .init = redirect_all_std)
{
    list_t *list = malloc(sizeof(list_t));
    list_t *list2 = malloc(sizeof(list_t));

    list->nb_link = 0;
    list->id = "2";
    list2->id = "4";
    cr_assert(!is_list_next(list, list2));
    cr_assert_eq(list->nb_link, 1);
    cr_assert_str_eq(list->next[0]->id, "4");
    free(list);
    free(list2);
}

Test(link_list, had_link_next, .init = redirect_all_std)
{
    list_t *list = malloc(sizeof(list_t));
    list_t *list2 = malloc(sizeof(list_t));
    list_t *list3 = malloc(sizeof(list_t));

    list->next = malloc(sizeof(list_t *) * 2);
    list->next[0] = list3;
    list->next[1] = NULL;
    list->nb_link = 1;
    list->id = "2";
    list2->id = "6";
    list3->id = "4";
    cr_assert(!is_list_next(list, list2));
    cr_assert_eq(list->nb_link, 2);
    cr_assert_str_eq(list->next[0]->id, "4");
    cr_assert_str_eq(list->next[1]->id, "6");
    free(list);
    free(list2);
}
