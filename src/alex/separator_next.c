/*
** separator_next.c for  in /home/quasta_b/rendu/Projets/PSU/PSU_2015_42sh/src/alex
**
** Made by Benjamin Quastana
** Login   <quasta_b@epitech.net>
**
** Started on  Fri Jun  3 10:40:11 2016 Benjamin Quastana
** Last update Sat Jun  4 10:28:17 2016 thomas lavigne
*/

#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

void	count_and(char *commande, t_second *ini)
{
  int   z;

  z = 0;
  ini->check.nb_and = 0;
  while (commande[z] != '\0')
    {
      if (commande[z] == '&' && commande[z + 1] == '&')
        ini->check.nb_and = 1;
      z++;
    }
}

void	normal2(t_second *ini, char *com, t_env *ini2, char *commande)
{
  if (ini->check.type == 1 && ini->check.nb_and == 1)
    {
      count_redirection(ini, com);
      count_pipe(com, ini);
      lanceur(com, ini2, ini);
      if (ini->check.nb_and == 0)
	{
	  while (ini->check.type != 2 &&
		 (double_pipe(commande, &ini->check.type)) != NULL);
	}
    }
  else if (ini->check.nb_or == 1  && ini->check.type == 2)
    {
      count_redirection(ini, com);
      count_pipe(com, ini);
      lanceur(com, ini2, ini);
      if (ini->check.nb_or == 0)
	{
	  while (ini->check.type != 1 &&
		 (double_pipe(commande, &ini->check.type)) != NULL);
	}
    }
}
