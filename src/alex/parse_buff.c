/*
** parse_buff.c for  in /home/quasta_b/rendu/Projets/PSU/PSU_2015_42sh/src
**
** Made by Benjamin Quastana
** Login   <quasta_b@epitech.net>
**
** Started on  Fri Apr 29 09:57:46 2016 Benjamin Quastana
** Last update Thu May 26 15:06:36 2016 Thauvin
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

int	my_strlen_space(char *str, int pos)
{
  while ((str[pos] == ' ' || str[pos] == '|') && str[pos] != '\0')
    pos++;
  return (pos);
}

int	count_pipes(char *str)
{
  int	i;
  int	a;

  i = a = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '|')
	a++;
      i++;
    }
  return (a);
}

int	clean_mal(char *str, int i)
{
  int	nb;

  nb = 0;
  while (str[i] != '|' && str[i] != '\0' && str[i] != '\n')
    if (str[i + 1] != '|')
      {
	nb++;
	i++;
      }
    else
      i++;
  return (nb + 1);
}

void		create_tab(char *str, t_second *ini, t_env *ini2)
{
  t_benji	var;

  var.a = var.x = var.y = var.i = 0;
  if ((var.tab = malloc(sizeof(*var.tab) * (count_pipes(str) + 2))) == NULL)
    exit(1);
  if (str && str != NULL)
    {
      while (str[var.a] != '\0')
	{
	  if ((var.tab[var.y] = malloc(clean_mal(str, var.a))) == NULL)
	    exit(1);
	  while (str[var.a] != '|' && str[var.a] != '\0' && str[var.a] != '\n')
	    if (str[var.a] != '|')
	      var.tab[var.y][var.x++] = str[var.a++];
	    else
	      var.a++;
	  var.tab[var.y++][var.x] = '\0';
	  var.x = 0;
	  var.a = my_strlen_space(str, var.a);
	}
      var.tab[var.y] = NULL;
    }
  pipe_toto(var.tab, ini, ini2);
}
