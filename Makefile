##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC			=	sokoban.c							\
				check_key_press.c					\
				destroy_fonc.c						\
				display.c							\
				end_condition.c						\
				get_position.c						\
				help.c								\
				little_fonc.c						\
				move_player.c						\
				obtain_map.c						\

DIR_SRC		=	$(addprefix src/, $(SRC))

MAIN_SRC	=	src/main.c						\

TEST		=	\

DIR_TESTS	=	$(addprefix tests/, $(TEST))

OBJ_DIR_SRC	=	$(DIR_SRC:.c=.o)

OBJ_MAIN	=	$(MAIN_SRC:.c=.o)

OBJ			=	$(OBJ_DIR_SRC) $(OBJ_MAIN)

LDLIBS		=	-L lib/							\
				-l my_str						\
				-l my_linked_list				\
				-l my_int						\
				-l my_char_map					\
				-l my_int_map					\
				-l ncurses

CPPFLAGS	=	-I include/						\
				-I lib/my_str/include			\
				-I lib/my_linked_list/include	\
				-I lib/my_int/include			\
				-I lib/my_char_map/include		\
				-I lib/my_int_map/include		\

CFLAGS		=	-Wall -Wextra -ggdb3

NAME		=	my_sokoban

LIBS		=	lib/libmy_str.a					\
				lib/libmy_linked_list.a			\
				lib/libmy_int.a					\
				lib/libmy_char_map.a			\
				lib/libmy_int_map.a				\

all: make_libs $(NAME)

$(NAME):	$(LIBS) $(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDLIBS)

make_libs:
		make -C lib/my_int
		make -C lib/my_str
		make -C lib/my_linked_list
		make -C lib/my_char_map
		make -C lib/my_int_map

clean:
		make clean -C lib/my_int
		make clean -C lib/my_str
		make clean -C lib/my_linked_list
		make clean -C lib/my_char_map
		make clean -C lib/my_int_map
		rm -f $(OBJ)

fclean: clean
		make fclean -C lib/my_int
		make fclean -C lib/my_str
		make fclean -C lib/my_linked_list
		make fclean -C lib/my_char_map
		make fclean -C lib/my_int_map
		rm -rf unit_tests
		rm -rf *.gcov
		rm -f $(NAME)

re:		fclean all

unit_tests:	re
		mkdir unit_tests
		make unit_tests -C lib/my_int
		make unit_tests -C lib/my_str
		gcc -o unit_tests/unit_tests $(DIR_SRC) $(DIR_TESTS)\
		$(CPPFLAGS) $(LDLIBS) --coverage -lcriterion

tests_run:	unit_tests
		make tests_run -C lib/my_int
		make tests_run -C lib/my_str
		./unit_tests/unit_tests

.PHONY: all clean fclean re make_libs tests_run
