##
## EPITECH PROJECT, 2018
## navy
## File description:
## Makefile
#

SRC	=	main.c			\
		navy.c			\
		error_gestion.c		\
		is_navy_file.c		\
		is_nbr.c		\
		is_alpha.c		\
		mputstr.c		\
		mputnbr.c		\
		mgetnbr.c		\
		connection.c		\
		sig_counter.c		\
		load_boat_pos.c		\
		place_boat.c		\
		print.c			\
		get_input.c		\
		update_map.c		\
		gameloop.c		\
		generate_adv_map.c	\
		verif_win.c		\
		share_pos.c		\
		set_sigaction.c		\
		turn.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -g

NAME	=	navy

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -c $(SRC) $(CFLAGS)
		gcc -o $(NAME) $(CFLAGS) $(OBJ)
		rm $(OBJ)

clean :
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
