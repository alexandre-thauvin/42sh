/*
** make_list.c for 42sh_pipe in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/moulinette/pipe
**
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
**
** Started on  Fri Apr 29 09:56:06 2016 thomas lavigne
** Last update Mon May  2 18:56:33 2016 Thauvin
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

int     my_put_in_list(struct s_pipe **list, char *str, t_second *ini, t_env *ini2)
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
  elem->arg = ma2d(elem->arg, getrows_tab(str), str);
  elem->arg = my_strduptab(str);
  ini->j = 0;
  ini2->j = 0;
  ini_var_lanceur(ini, str, ini2);
  ini->check = file_exist(ini, ini->rows_PATH);
  elem->arg[0] = ini->PATHfinal[ini->check];
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

void	make_list(t_pipe **list, char **tab_pipe, t_second *ini, t_env *ini2)
{
  int	a;

  a = my_tablen(tab_pipe) - 1;
  while (a >= 0)
    if (my_put_in_list(list, tab_pipe[a--], ini, ini2) == 1)
      return ;
}

void	pipe_toto(char **tab_pipe, t_second *ini, t_env *ini2)
{
  t_pipe	*list;

  list = NULL;
  make_list(&list, tab_pipe, ini, ini2);
  pipe_exec(list, ini2);
}
