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
				-l ncurses

CPPFLAGS	=	-I include/						\
				-I lib/my_str/include			\

CFLAGS		=	-Wall -Wextra -ggdb3

NAME		=	my_sokoban

LIBS		=	lib/libmy_str.a					\

all: make_libs $(NAME)

$(NAME):	$(LIBS) $(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDLIBS)

make_libs:
		make -C lib/my_str

clean:
		make clean -C lib/my_str
		rm -f $(OBJ)

fclean: clean
		make fclean -C lib/my_str
		rm -rf unit_tests
		rm -rf *.gcov
		rm -f $(NAME)

re:		fclean all

unit_tests:	re
		mkdir unit_tests
		make unit_tests -C lib/my_str
		gcc -o unit_tests/unit_tests $(DIR_SRC) $(DIR_TESTS)\
		$(CPPFLAGS) $(LDLIBS) --coverage -lcriterion

tests_run:	unit_tests
		make tests_run -C lib/my_str
		./unit_tests/unit_tests

.PHONY: all clean fclean re make_libs tests_run
