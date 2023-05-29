##
## EPITECH PROJECT, 2018
## bootstrap my hunter | Makefile
## File description:
## Makefile
##

NAME	=	my_hunter

SRC	=	        main.c     			\
				anim.c				\
				create_sprite.c		\
				window_manager.c	\
				create_const.c		\
				time_gestion.c		\
				sprite_gestion.c	\
				manage_mouse.c		\
				sprite_gestion_2.c	\
				ball_gestion.c		\
				text_gestion.c		\
				sound_gestion.c		\
				game_main.c			\
				dog_gestion.c		\
				sprite_anim.c		\
				sprite_speed.c		\

OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):	$(OBJ)
		gcc -c $(SRC)
		gcc -lm -g3 -o $(NAME) -I./ -l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio $(OBJ)
		rm $(OBJ)

clean :
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
