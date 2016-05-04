/*
** redirection.c for  in /home/thauvi_a/rendu/shell/PSU_2015_minishell2/src
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Wed Apr 13 18:35:25 2016 Thauvin
** Last update Tue May  3 12:21:05 2016 Theo Labory
*/

#include "shell.h"

int	tab_with_redirection(t_second *ini)
{
  int	z;

  z = 0;
  while (ini->arg[z] != NULL)
    z++;
  z = z - 2;
  ini->arg2 = malloc2d(ini->arg2, z, 100);
  z = 0;
  while (ini->arg[z] != NULL && ini->arg[z][0] != '>' &&
	 ini->arg2[z] != NULL && ini->arg[z][0] != '<')
    {
      ini->arg2[z] = my_strcpy(ini->arg2[z], ini->arg[z]);
      z++;
    }
  ini->arg2[z] = NULL;
  if (ini->arg[z + 1] == NULL)
    {
      ini->nb_redirection = 0;
      return (0);
    }
  if ((ini->file_name = malloc((my_strlen(ini->arg[z + 1]) + 1)
			       * sizeof(char))) == NULL)
    exit(-42);
  ini->file_name = my_strcpy(ini->file_name, ini->arg[z + 1]);
  ini->arg[z] = NULL;
  return (0);
}

void	count_redirection(t_second *ini, char *commande)
{
  int	z;

  z = 0;
  ini->nb_redirection = 0;
  while (commande[z] != '\0')
    {
      if (commande[z] == '>')
	ini->nb_redirection = 1;
      if (commande[z] == '<')
	ini->nb_redirection = -1;
      z++;
    }
}
