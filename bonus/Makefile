##
## Makefile for  in /home/joubert/delivery/raytracer1
## 
## Made by Joubert Miguel
## Login   <miguel.joubert@epitech.eu>
## 
## Started on  Sat Feb 25 15:34:07 2017 Joubert Miguel
## Last update Mon Mar 20 02:09:24 2017 Joubert Miguel
##

CC	=	gcc

BUG	=	gcc -g3

NAME	=	raytracer1

SRC	=	src/*.c

LIB	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CFLAGS	=	-W -Wall -Wextra -pedantic

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:

		$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(LIB)

debug :
		$(BUG) -o $(NAME) $(SRC) $(CFLAGS) $(LIB)

clean	:

		$(RM) $(NAME)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all
