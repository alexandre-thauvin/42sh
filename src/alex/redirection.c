/*
** redirection.c for  in /home/thauvi_a/rendu/shell/PSU_2015_minishell2/src
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Wed Apr 13 18:35:25 2016 Thauvin
** Last update Fri Jun  3 01:14:31 2016 Alexandre Thauvin
*/

#include "shell.h"

int	check_arg_redirec(t_second *ini, int z)
{
  if (ini->comm.arg[z + 1] == NULL)
    {
      ini->check.nb_redirection = 0;
      return (-1);
    }
  return (0);
}

char	**tab_with_redirection(t_second *ini, char **arg2)
{
  int	z;

  z = 0;
  while (ini->comm.arg[z] != NULL)
    z++;
  z = z - 2;
  arg2 = malloc2d(arg2, z, 100);
  z = 0;
  while (ini->comm.arg[z] != NULL && ini->comm.arg[z][0] != '>' &&
	 arg2[z] != NULL && ini->comm.arg[z][0] != '<')
    {
      arg2[z] = my_strcpy(arg2[z], ini->comm.arg[z]);
      z++;
    }
  arg2[z] = NULL;
  if ((check_arg_redirec(ini, z)) == -1)
      return (NULL);
  if ((ini->comm.file_name = malloc((my_strlen(ini->comm.arg[z + 1]) + 1)
			       * sizeof(char))) == NULL)
    exit(1);
  ini->comm.file_name = my_strcpy(ini->comm.file_name, ini->comm.arg[z + 1]);
  ini->comm.arg[z] = NULL;
  return (arg2);
}

void	count_redirection(t_second *ini, char *commande)
{
  int	z;

  z = 0;
  ini->check.nb_redirection = 0;
  while (commande[z] != '\0')
    {
      if (commande[z] == '<')
	ini->check.nb_redirection = -1;
      if (commande[z] == '>')
	{
	  if (ini->check.nb_redirection == -1)
	    ini->check.nb_redirection = -2;
	  else
	    ini->check.nb_redirection = 1;
	}
      if (commande[z] == '>' && commande[z + 1] == '>')
	ini->check.nb_redirection = 2;
      z++;
    }
}
