##
## EPITECH PROJECT, 2018
## bootstrap my hunter | Makefile
## File description:
## Makefile
##

NAME	=	my_sokoban

SRC	=	        main.c     		\
				load_file.c		\
				my_sokoban.c	\
				key_event.c		\
				verif_map.c		\
				free_func.c		\
				copy_map.c		\
				move_player.c	\
				display.c		\
				detect_loose.c	\

OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):
		gcc -g3 -o $(NAME) $(SRC) -I./ -lncurses


clean :
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
