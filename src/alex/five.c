/*
** five.c for  in /home/thauvi_a/rendu/42sh/PSU_2015_42sh/src/alex
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Thu May  5 03:24:58 2016 Thauvin
** Last update Sun Jun  5 18:40:22 2016 Theo Labory
*/

#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

void	compar_ma2d(t_var_malloc *ini, char *commande)
{
  if (commande[ini->z] != '\0')
    ini->z++;
  if (ini->cols > ini->cols2)
    ini->cols2 = ini->cols;
}

void	count_pipe(char *commande, t_second *ini)
{
  int	z;

  z = 0;
  ini->check.nb_pipe = 0;
  while (commande[z] != '\0')
    {
      if (commande[z] == '|')
	ini->check.nb_pipe++;
      z++;
    }
}

char	*cd_tild(char **arg, char *path_final, char **env)
{
  int	z;
  int	i;
  char	*home;

  i = 1;
  home = pars_home(env, path_final);
  if ((path_final = malloc(((my_strlen(home))
			    + (my_strlen(arg[1])) + 1) * sizeof(char))) == NULL)
    exit(1);
  z = my_strlen(home);
  path_final = my_strcpy(path_final, home);
  while (arg[1][i] != '\0')
    {
      path_final[z] = arg[1][i];
      z++;
      i++;
    }
  path_final[z] = '\0';
  return (path_final);
}
