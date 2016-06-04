/*
** separator.c for  in /home/thauvi_a/rendu/PSU_2015_42sh/src/alex
**
** Made by
** Login   <thauvi_a@epitech.net>
**
** Started on  Thu Jun  2 11:09:11 2016
** Last update Sat Jun  4 10:26:51 2016 thomas lavigne
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

void	count_or(char *commande, t_second *ini)
{
  int	z;

  z = 0;
  ini->check.nb_or = 0;
  while (commande[z] != '\0')
    {
      if (commande[z] == '|' && commande[z + 1] == '|')
	  ini->check.nb_or = 1;
      z++;
    }
}

void	with_separator(t_second *ini, t_env *ini2)
{
  while (ini->check.nb_separator >= 0)
    {
      pars_commande(ini->comm.commande, ini);
      if (ini->vpwd.dest != NULL && ini->vpwd.dest[0] != 0)
	{
	  count_or(ini->vpwd.dest, ini);
	  count_and(ini->vpwd.dest, ini);
	  if (ini->check.nb_and == 0 && ini->check.nb_or == 0)
	    {
	      count_pipe(ini->vpwd.dest, ini);
	      count_redirection(ini, ini->vpwd.dest);
	      lanceur(ini->vpwd.dest, ini2, ini);
	    }
	  else
	    normal(ini, ini2, ini->vpwd.dest);
	}
      ini->check.nb_separator--;
    }
}

int	normal(t_second *ini, t_env *ini2, char *commande)
{
  char	*com;

  if (commande[0] == 0)
    return (0);
  ini->check.type = 0;
  count_or(commande, ini);
  count_and(commande, ini);
  if (ini->check.nb_and == 0 && ini->check.nb_or == 0)
    {
      count_redirection(ini, commande);
      count_pipe(commande, ini);
      lanceur(commande, ini2, ini);
    }
  double_pipe("reset", &ini->check.type);
  while ((com = double_pipe(commande, &ini->check.type)) != NULL
	 && (ini->check.nb_and != 0 || ini->check.nb_or != 0))
    {
      normal2(ini, com, ini2, commande);
      free(com);
    }
  return (0);
}

int	count_separator(char *commande)
{
  int	z;
  int	nb;

  z = nb = 0;
  while (commande[z] != '\0')
    {
      if (commande[z] == ';')
	nb++;
      z++;
    }
  return (nb);
}

char		*pars_commande(char *commande, t_second *ini)
{
  static int	z = 0;
  static int	i = 0;
  int		j;

  j = 0;
  while (commande[z] != ';' && commande[z] != '\0')
      z++;
  z++;
  if ((ini->vpwd.dest = malloc(z * sizeof(char))) == NULL) exit(1);
  while (commande[i] != ';')
    {
      if (commande[i] == '\0')
	{
	  ini->vpwd.dest[j] = '\0';
	  i = 0;
	  z = 0;
	  return (ini->vpwd.dest);
	}
      ini->vpwd.dest[j] = commande[i];
      j++;
      i++;
    }
  ini->vpwd.dest[j] = '\0';
  i++;
  return (ini->vpwd.dest);
}
