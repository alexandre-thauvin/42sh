/*
** make_list.c for 42sh_pipe in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/moulinette/pipe
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Fri Apr 29 09:56:06 2016 thomas lavigne
** Last update Mon May  2 17:10:38 2016 thomas lavigne
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

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
  if ((elem->arg = malloc(sizeof(char *) * getrows_tab(str)))
      == NULL) return (1);
  elem->arg = ma2d(elem->arg, getrows_tab(str), str);
  elem->arg = my_strduptab(str);
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

void	make_list(t_pipe **list, char **tab_pipe)
{
  int	a;

  a = my_tablen(tab_pipe) - 1;
  while (a >= 0)
    if (my_put_in_list(list, tab_pipe[a--]) == 1)
      return ;
}

void	pipe_toto(char **tab_pipe)
{
  t_pipe	*list;

  make_list(&list, tab_pipe);
  pipe_exec(list);
}
