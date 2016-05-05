/*
** make_list.c for 42sh_pipe in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/moulinette/pipe
**
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
**
** Started on  Fri Apr 29 09:56:06 2016 thomas lavigne
** Last update Thu May  5 20:51:59 2016 thomas lavigne
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

int	size_name(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != ' ' && str[i] != '\0')
    i++;
  return (i);
}

char	*catch_name(char *str)
{
  char	*finale;
  int	i;

  i = 0;
  if ((finale = malloc(size_name(str))) == NULL)
    exit(EXIT_FAILURE);
  while (str[i] != ' ' && str[i] != '\0')
    {
      finale[i] = str[i];
      i++;
    }
  return (finale);
}

int	check_builtin(char *str)
{
  if (my_strcmp("cd", str) == 1)
    {
      free(str);
      return (0);
    }
  else if (my_strcmp("env", str) == 1)
    {
      free(str);
      return (0);
    }
  else if (my_strcmp("exit", str) == 1)
    {
      free(str);
      return (0);
    }
  else if (my_strcmp("setenv", str) == 1)
    {
      free(str);
      return (0);
    }
  else if (my_strcmp("unsetenv", str) == 1)
    {
      free(str);
      return (0);
    }
  else
    {
      free(str);
      return (-1);
    }
}

int		my_put_in_list(t_pipe **list, char *str, t_second *ini,
				t_env *ini2)
{
  t_pipe	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    exit(EXIT_FAILURE);
  if (elem == NULL)
    return (1);
  elem->name = str;
  elem->arg = ma2d(elem->arg, getrows_tab(str), str);
  elem->arg = my_strduptab(str);
  ini->j = ini2->j = 0;
  ini_var_lanceur(ini, str, ini2);
  if ((ini->check = file_exist(ini, ini->rows_PATH)) == -1)
    if (check_builtin(catch_name(str)) == -1) /* remplacer par celui de thauv */
      {
       write(2, "Command not found.\n", my_strlen("Command not found.\n"));
	ini->nb_and = 0;
	return (1);
      }
    else
      elem->arg[0] = str;
  else
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
    pipe_exec(list, ini2);
}
