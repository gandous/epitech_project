##
## EPITECH PROJECT, 2018
## bootstrap my hunter | Makefile
## File description:
## Makefile
##

NAME	=	my_runner

SRC	=	        main.c\
				runner.c\
				window_manager.c\
				game_loop.c\
				analyse_event.c\
				print.c\
				load_map_src/load_map.c\
				create_data_src/create_const.c\
				create_data_src/create_sprite.c\
				create_data_src/lib_func.c\
				create_data_src/create_txt.c\
				game_gestion/manage_bg.c\
				game_gestion/manage_perso.c\
				game_gestion/manage_sprite.c\
				game_gestion/display_sprite.c\
				game_gestion/free_game_data.c\
				game_gestion/manage_map.c\
				game_gestion/update_map.c\
				game_gestion/ground_lvl.c\
				game_gestion/detect_wall.c\
				game_gestion/score.c\
				game_gestion/map_texture.c\
				game_gestion/calc_jump.c\
				end_menu/end_menu.c\
				end_menu/end_menu_event.c\
				end_menu/end_animation.c\
				start_menu/start_menu.c\
				start_menu/start_menu_event.c


OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-I./include -g

all:			$(NAME)

$(NAME):	$(OBJ)
		gcc -c $(SRC) $(CFLAGS)
		gcc -lm -o $(NAME) $(CFLAGS) -l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio -lm $(OBJ)
		rm $(OBJ)

clean :
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
