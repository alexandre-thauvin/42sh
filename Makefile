##
## Makefile for  in /home/thauvi_a/rendu/Piscine_C_J10/lib/my
## 
## Made by alexandre thauvin
## Login   <thauvi_a@epitech.net>
## 
## Started on  Fri Oct  9 19:04:31 2015 alexandre thauvin
## Last update Fri Apr 29 01:02:40 2016 Thauvin
##

SRCS	= src/main.c \
	src/first.c \
	src/cd_ok.c \
	src/env.c \
	src/redirection.c \
	src/separator.c \
	src/third.c \
	src/four.c \
	src/env2.c \
	src/check_path.c \
	src/get_next_line.c \
	src/tab_arg.c \
	src/tab_path.c

NAME	= 42sh

OBJS	= $(SRCS:.c=.o)

RM	= rm -rf

CC	= gcc

CFLAGS	= -W -Wextra -Wall -Werror -I include/ -g

CLIB	= -lmy -Llib

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(CLIB)

all:	$(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all
