##
## EPITECH PROJECT, 2018
## make file
## File description:
## make
##

SRC	=	main_temp.c	\

NAME 	=	temp_test

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(SRC) -I./include/ -L./lib/my -lmy

clean:
	rm -f $(NAME)

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)


re:	fclean all
