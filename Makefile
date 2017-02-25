##
## Makefile for  in /home/joubert/delivery/raytracer1
## 
## Made by Joubert Miguel
## Login   <miguel.joubert@epitech.eu>
## 
## Started on  Sat Feb 25 15:34:07 2017 Joubert Miguel
## Last update Sat Feb 25 15:35:55 2017 Joubert Miguel
##

CC	=	gcc

BUG	=	gcc -g3

NAME	=	raytracer1

SRC	=	src/*.c

LIB	=	-lc_graph_prog -lm

CFLAGS	=	-W -Wall -Wextra -pedantic

RM	=	rm -fr

all	:	$(NAME)

$(NAME)	:

		$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(LIB)

debug :
		$(BUG) -o $(NAME) $(SRC) $(CFLAGS) $(LIB)

clean	:

		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all
