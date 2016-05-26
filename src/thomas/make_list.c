/*
** make_list.c for 42sh_pipe in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/moulinette/pipe
**
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
**
** Started on  Fri Apr 29 09:56:06 2016 thomas lavigne
** Last update Thu May 26 15:40:25 2016 Thauvin
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
  else if (str[i] == 'e' && str[i + 1] == 'x' && str[i + 2] == 'i' &&
	   str[i + 3] == 't')
    check_exit(ini->arg, ini->rows_arg);
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
  /* printf("%s\n", str); */
  elem->arg = ma2d(elem->arg, getrows_tab(str), str);
  elem->arg = my_strduptab(str);
  ini->j = ini2->j = 0;
  ini_var_lanceur(ini, str, ini2);
  /* if (ini->nb_redirection != 0) */
  /*   { */
  /*     printf("ici\n"); */
  /*     tab_with_redirection(ini); */
  /*     elem->arg = ini->arg2; */
  /*   } */
  if (check_builtin(str, ini) == -1)
    if ((ini->check = file_exist(ini, ini->rows_PATH)) == -1)
      {
	write(2, "Command not found.\n", my_strlen("Command not found.\n"));
	ini->nb_and = 0;
	return (1);
      }
    else
      elem->arg[0] = ini->PATHfinal[ini->check];
  else
    elem->arg[0] = str;
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
