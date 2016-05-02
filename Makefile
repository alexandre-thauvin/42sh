##
## Makefile for  in /home/thauvi_a/rendu/Piscine_C_J10/lib/my
## 
## Made by alexandre thauvin
## Login   <thauvi_a@epitech.net>
## 
## Started on  Fri Oct  9 19:04:31 2015 alexandre thauvin
## Last update Mon May  2 16:47:33 2016 Thauvin
##

SRCS	= src/alex/main.c \
	src/alex/first.c \
	src/alex/cd_ok.c \
	src/alex/parse_buff.c \
	src/alex/env.c \
	src/alex/redirection.c \
	src/alex/separator.c \
	src/alex/third.c \
	src/alex/four.c \
	src/alex/env2.c \
	src/alex/check_path.c \
	src/alex/get_next_line.c \
	src/alex/tab_arg.c \
	src/alex/tab_path.c

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
