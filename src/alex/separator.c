/*
** separator.c for  in /home/thauvi_a/rendu/shell/PSU_2015_minishell2
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Wed Apr 13 11:20:53 2016 Thauvin
** Last update Wed Jun  1 15:18:24 2016 thomas lavigne
*/

#include "shell.h"

void	count_and(char *commande, t_second *ini)
{
  int	z;

  z = 0;
  ini->nb_and = 0;
  while (commande[z] != '\0')
    {
      if (commande[z] == '&' && commande[z + 1] == '&')
	ini->nb_and = 1;
      z++;
    }
}

void	with_separator(t_second *ini, t_env *ini2)
{
  char	*com;

  while (ini->nb_separator >= 0)
    {
      pars_commande(ini->commande, ini);
      if (ini->dest != NULL && ini->dest[0] != 0)
	{
	  count_and(ini->dest, ini);
	  if (ini->nb_and == 0)
	    {
	      count_pipe(ini->dest, ini);
	      count_redirection(ini, ini->dest);
	      lanceur(ini->dest, ini2, ini);
	    }
	  else
	    {
	      double_pipe("reset", '&');
	      ini->nb_and = 1;
	      while (com != NULL && ini->nb_and == 1)
		{
		  if ((com = double_pipe(ini->dest, '&')) == NULL)
		    ini->nb_and = 0;
		  if (ini->nb_and == 1)
		    {
		      count_pipe(com, ini);
		      count_redirection(ini, com);
		      lanceur(com, ini2, ini);
		    }
		  free(com);
		}
	    }
	}
      ini->nb_separator--;
    }
}

int	normal(t_second *ini, t_env *ini2)
{
  char	*com;

  if (ini->commande[0] == 0)
    return (0);
  count_and(ini->commande, ini);
  if (ini->nb_and == 0)
    {
      count_redirection(ini, ini->commande);
      count_pipe(ini->commande, ini);
      lanceur(ini->commande, ini2, ini);
    }
  else
    {
      double_pipe("reset", '&');
      while (com != NULL)
	{
	  if ((com = double_pipe(ini->commande, '&')) != NULL)
	    if (ini->nb_and == 1)
	    {
	      count_redirection(ini, com);
	      count_pipe(com, ini);
	      lanceur(com, ini2, ini);
	    }
	  free(com);
	}
    }
  return (0);
}

int	count_separator(char *commande)
{
  int	z;
  int	nb;

  z = 0;
  nb = 0;
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

  ini->j = 0;
  while (commande[z] != ';' && commande[z] != '\0')
      z++;
  z++;
  if ((ini->dest = malloc(z * sizeof(char))) == NULL)
    exit(1);
  while (commande[i] != ';')
    {
      if (commande[i] == '\0')
	{
	  ini->dest[ini->j] = '\0';
	  i = 0;
	  z = 0;
	  return (ini->dest);
	}
      ini->dest[ini->j] = commande[i];
      ini->j++;
      i++;
    }
  ini->dest[ini->j] = '\0';
  i++;
  return (ini->dest);
}
