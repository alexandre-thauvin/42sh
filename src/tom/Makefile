##
## Makefile for Makefile in /home/lalagu_t/rendu/Sem2/PSU/PSU_2015_42sh
## 
## Made by Lalague-Dulac Tom
## Login   <lalagu_t@epitech.net>
## 
## Started on  Tue May  3 11:35:22 2016 Lalague-Dulac Tom
## Last update Tue May  3 11:37:29 2016 Lalague-Dulac Tom
##

CC	=	gcc

RM	=	rm -f

NAME	=	exec

SRC	=	double_and.c

OBJ	=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all	:	$(NAME)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	clean fclean re
