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
				window_man.c	\
				game_loop.c		\
				display_map.c	\
				color_manager.c	\
				start_screen.c	\
				create_menu.c	\
				game_menu.c		\
				detect_loose.c	\
				play_menu.c		\
				gestion_save.c	\
				end_game_menu.c\
				popup_maneger.c	\

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
