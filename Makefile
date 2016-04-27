##
## Makefile for  in /home/thauvi_a/rendu/Piscine_C_J10/lib/my
## 
## Made by alexandre thauvin
## Login   <thauvi_a@epitech.net>
## 
## Started on  Fri Oct  9 19:04:31 2015 alexandre thauvin
## Last update Wed Apr 27 20:30:24 2016 Thauvin
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

SRCS2	= lib/my/my_getnbr.c \
	lib/my/my_strcpy.c \
	lib/my/my_strlen.c \
	lib/my/malloc2d.c \
	lib/my/my_strcmp.c

SRCS3	= my_getnbr.o \
	my_strcpy.o \
	my_strlen.o \
	malloc2d.o \
	my_strcmp.o

NAME	= 42sh

OBJS	= $(SRCS:.c=.o)

RM	= rm -rf

CC	= gcc

CCLIB	= gcc -Wextra -Wall -Werror -c

CFLAGS	= -Wextra -Wall -Werror -I include/

AR	= ar rc

RAN	= ranlib

CLIB	= -lmy -Llib

LIB	= lib/libmy.a

all: $(NAME)

$(NAME): $(OBJS)
	$(CCLIB) $(SRCS2)
	$(AR) $(LIB) $(SRCS3)
	$(RAN) $(LIB)
	$(RM) $(SRCS3)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(CLIB)

all:	$(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all
