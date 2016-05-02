/*
** separator.c for  in /home/thauvi_a/rendu/shell/PSU_2015_minishell2
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Wed Apr 13 11:20:53 2016 Thauvin
** Last update Mon May  2 16:54:26 2016 Thauvin
*/

#include "shell.h"

void	with_separator(t_second *ini, t_env *ini2)
{
  while (ini->nb_separator >= 0)
    {
      pars_commande(ini->commande, ini);
      if (ini->dest != NULL && ini->dest[0] != 0)
	{
	  count_pipe(ini->dest, ini);
	  count_redirection(ini, ini->dest);
	  lanceur(ini->dest, ini2, ini);
	}
      ini->nb_separator--;
    }
}

void	normal(t_second *ini, t_env *ini2)
{
  if (ini->commande == NULL)
    exit(0);
  count_redirection(ini, ini->commande);
  count_pipe(ini->commande, ini);
  if (ini->commande != NULL && ini->commande[0] != 0)
    lanceur(ini->commande, ini2, ini);
}

void	count_pipe(char *commande, t_second *ini)
{
  int	z;

  z = 0;
  ini->nb_pipe = 0;
  while (commande[z] != '\0')
    {
      if (commande[z] == '|')
	ini->nb_pipe++;
      z++;
    }
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
    exit(-42);
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
