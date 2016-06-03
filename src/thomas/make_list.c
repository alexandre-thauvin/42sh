/*
** make_list.c for 42sh_pipe in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/moulinette/pipe
**
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
**
** Started on  Fri Apr 29 09:56:06 2016 thomas lavigne
** Last update Thu Jun  2 21:19:51 2016 Benjamin Quastana
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

int	check_builtin(char *str, t_second *ini)
{
  int	i;

  i = 0;
  while (str[i] == ' ' && str[i] != '\0')
    i++;
  if (str[i] == 'e' && str[i + 1] == 'n' && str[i + 2] == 'v')
    return (0);
  else if (str[i] == 's' && str[i + 1] == 'e' && str[i + 2] == 't' &&
	   str[i + 3] == 'e' && str[i + 4] == 'n' && str[i + 5] == 'v')
    return (0);
  else if (str[i] == 'u' && str[i + 1] == 'n' && str[i + 2] == 's' &&
	   str[i + 3] == 'e' && str[i + 4] == 't' && str[i + 5] == 'e'
	   && str[i + 6] == 'n' && str[i + 7] == 'v')
    return (0);
  else if (str[i] == 'e' && str[i + 1] == 'x' && str[i + 2] == 'i' &&
	   str[i + 3] == 't')
    check_exit(ini->comm.arg, ini->rows_arg);
  else if (str[i] == 'c' && str[i + 1] == 'd')
    return (0);
  else
    return (-1);
  return (-1);
}

int		my_put_in_list(t_pipe **list, char *str, t_second *ini,
				t_env *ini2)
{
  t_pipe	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    exit(0);
  if (elem == NULL)
    return (1);
  elem->name = str;
  count_redirection(ini, str);
  if (ini->check.nb_redirection == 0)
    {
      elem->arg = ma2d(elem->arg, getrows_tab(str), str);
      elem->arg = my_strduptab(str);
    }
  ini_var_lanceur(ini, str, ini2);
  if (ini->check.nb_redirection != 0)
    {
      ini->comm.arg= my_strduptab(str);
      elem->arg = tab_with_redirection(ini, elem->arg);
      elem->arg[0] = ini->vpath.PATHfinal[ini->error.check];
    }
  if (my_put_in_next(str, ini, elem) == 1)
    return (1);
  /* if (check_builtin(str, ini) == -1) */
  /*   if ((ini->error.check = file_exist(ini)) == -1) */
  /*     { */
  /* 	fprintf(stderr, "%s: Command not found.\n", elem->arg[0]); */
  /* 	ini->check.nb_and = 0; */
  /* 	return (1); */
  /*     } */
  /*   else */
  /*     { */
  /* 	if (ini->check.nb_redirection == 0) */
  /* 	  elem->arg[0] = ini->vpath.PATHfinal[ini->error.check]; */
  /*     } */
  /* else */
  /*   elem->arg[0] = str; */
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

int	make_list(t_pipe **list, char **tab_pipe, t_second *ini, t_env *ini2)
{
  int	a;

  a = my_tablen(tab_pipe) - 1;
  while (a >= 0)
    if (my_put_in_list(list, tab_pipe[a--], ini, ini2) == 1)
      return (1);
  return (0);
}

void	pipe_toto(char **tab_pipe, t_second *ini, t_env *ini2)
{
  t_pipe	*list;

  list = NULL;
  if (make_list(&list, tab_pipe, ini, ini2) != 1)
    pipe_exec(list, ini2, ini);
}
