/*
** parse_buff.c for  in /home/quasta_b/rendu/Projets/PSU/PSU_2015_42sh/src
**
** Made by Benjamin Quastana
** Login   <quasta_b@epitech.net>
**
** Started on  Fri Apr 29 09:57:46 2016 Benjamin Quastana
** Last update Mon May  2 17:45:43 2016 Thauvin
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

int	my_strlen_space(char *str, int pos)
{
  while((str[pos] == ' ' || str[pos] == '|') && str[pos] != '\0')
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

void	create_tab(char *str, t_second *ini, t_env *ini2)
{
  int	a;
  int	x;
  int	y;
  char	**tab;
  int	i;

  a = x = y = i = 0;
  if ((tab = malloc(sizeof(*tab) * (count_pipes(str)) + 1)) == NULL)
    exit(EXIT_FAILURE);
  if (str && str != NULL)
    {
      while (str[a] != '\0')
	{
	  if ((tab[y] = malloc(20)) == NULL) exit(0);
	  while (str[a] != '|' && str[a] != '\0' && str[a] != '\n')
	    if (str[a + 1] != '|')
	      tab[y][x++] = str[a++];
	    else
	      a++;
	  tab[y++][x] = '\0';
	  x = 0;
	  a = my_strlen_space(str, a);
	}
      tab[y] = NULL;
    }
  pipe_toto(tab, ini, ini2);
}
