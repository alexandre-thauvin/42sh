/*
** make_list.c for 42sh_pipe in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/moulinette/pipe
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Fri Apr 29 09:56:06 2016 thomas lavigne
** Last update Sat Apr 30 11:20:04 2016 thomas lavigne
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "pipe.h"

int     my_put_in_list(struct s_pipe **list, char *str)
{
  struct s_pipe	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    {
      printf("Error Malloc\n");
      exit(EXIT_FAILURE);
    }
  if (elem == NULL)
    return (1);
  elem->name = str;
  elem->arg = malloc(sizeof(char *) * 2);
  elem->arg[0] = malloc(sizeof(char) * 3);
  elem->arg[0] = "ls\0";
  elem->arg[1] = NULL;
  elem->next = *list;
  *list = elem;
  return (0);
}

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

void	make_list(t_pipe **list, char *tab_pipe[4])
{
  int	a;

  a = my_tablen(tab_pipe) - 1;
  while (a >= 0)
    if (my_put_in_list(list, tab_pipe[a--]) == 1)
      return ;
}

int	main()
{
  t_pipe	*list;
  char	*tab_pipe[4];

  tab_pipe[0] = "ls";
  tab_pipe[1] = "cat";
  tab_pipe[2] = "grep";
  tab_pipe[3] = NULL;
  make_list(&list, tab_pipe);
  pipe_exec(list);
}
