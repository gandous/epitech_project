##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## bistro-matic bonus
##

SRC	=	~/.mp4/bonus.mp4

CFLAGS	=	-f --no-osd

NAME	=	calc

all:	$(NAME)

$(NAME):
	make re -C../lib/my
	make fclean -C../lib/my
	@vlc $(CFLAGS) $(SRC)

clean:
	@echo "Le ménage est fait!"

fclean:
	@echo "C'est super propre!!"

re:	fclean all

.PHONY:	all clean fclean re
