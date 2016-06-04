##
## Makefile for Makefile in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh
## 
## Made by thomas lavigne
## Login   <lavign_t@epitech.net>
## 
## Started on  Sat Jun  4 09:20:59 2016 thomas lavigne
## Last update Sat Jun  4 10:08:11 2016 thomas lavigne
##

SRCS	=	src/alex/main.c			\
		src/alex/first.c		\
		src/alex/cd_ok.c		\
		src/alex/parse_buff.c		\
		src/alex/env.c			\
		src/alex/redirection.c		\
		src/alex/separator.c		\
		src/alex/third.c		\
		src/alex/four.c			\
		src/alex/four2.c		\
		src/alex/env2.c			\
		src/alex/env3.c			\
		src/alex/check_path.c		\
		src/alex/get_next_line.c	\
		src/alex/tab_arg.c		\
		src/alex/tab_path.c		\
		src/thomas/make_list.c		\
		src/thomas/pipe_exec.c		\
		src/thomas/exec_next.c		\
		src/alex/five.c			\
		src/thomas/alpha_num.c		\
		src/tom/double.c		\
		src/theo/my_free.c		\
		src/thomas/cd_verif.c		\
		src/alex/wait_in_path2.c	\
		src/tom/double2.c		\
		src/alex/separator_next.c	\
		src/thomas/redic_verif.c        \
		src/thomas/no_more_zomb.c	\

NAME	= 42sh

OBJS	= $(SRCS:.c=.o)

RM	= rm -rf

CC	= gcc

CFLAGS	= -W -Wextra -Wall -Werror -I include/ -g

CLIB	= -lmy -Llib

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(CLIB)

all:		$(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
