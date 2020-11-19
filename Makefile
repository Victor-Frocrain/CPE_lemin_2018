##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	sources/parser.c		\
		sources/lemin.c			\
		sources/chain_list.c		\
		sources/link_list.c		\
		sources/my_realloc.c		\
		sources/manage_input.c		\
		sources/display_graph.c		\
		sources/search_path.c		\
		sources/display_move.c		\
		sources/destroy_rsrc.c		\
		sources/parsing_ant.c		\
		sources/parsing_link.c		\
		sources/parsing_room.c		\
		sources/manage_tunnels.c	\

SRC_MAIN=	sources/main.c			\

SRC_TEST=	tests/test_int_parser.c		\
		tests/test_node_parser.c	\
		tests/test_chain_list.c		\
		tests/test_link_list.c		\
		tests/test_link_list2.c		\
		tests/test_parsing_room.c	\
		tests/test_manage_input.c	\
		tests/test_my_realloc.c		\
		tests/test_pathfinding1.c	\

OBJ	=	$(SRC:%.c=%.o) $(SRC_MAIN:%.c=%.o)

NAME	=	lem_in

TEST_NAME=	unit_tests

CFLAGS	=	-I ./include/ -W -Wall -Wextra -Wshadow

CC	=	cc

TEST_FLAGS=	-lcriterion --coverage

LDFLAGS	=	-L lib/ -lmy -lget-next-line -lmy-printf

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	make -C lib/get_next_line
	make -C lib/my_printf
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make -C lib/my clean
	make -C lib/get_next_line clean
	make -C lib/my_printf clean
	$(RM) $(OBJ)
	$(RM) *.gc*

fclean:		clean
	make -C lib/my fclean
	make -C lib/get_next_line fclean
	make -C lib/my_printf fclean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

re:		fclean all

tests_run:
	make -C lib/my/
	make -C lib/my_printf/
	make -C lib/get_next_line/
	$(CC) -o $(TEST_NAME) -I include $(SRC_TEST) $(SRC) $(TEST_FLAGS) $(LDFLAGS)
	./$(TEST_NAME)
	gcovr --exclude tests
