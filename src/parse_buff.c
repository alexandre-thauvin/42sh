/*
** parse_buff.c for  in /home/quasta_b/rendu/Projets/PSU/PSU_2015_42sh/src
** 
** Made by Benjamin Quastana
** Login   <quasta_b@epitech.net>
** 
** Started on  Fri Apr 29 09:57:46 2016 Benjamin Quastana
** Last update Fri Apr 29 15:31:33 2016 Benjamin Quastana
*/

#include <unistd.h>
#include <stdlib.h>

int	my_strlen_space(char *str, int pos)
{
  while(str[pos] == ' ' || str[pos] == '|' && str[pos] != '\0')
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

char    **create_tab(char *str)
{
  int   a;
  int   x;
  int   y;
  char  **tab;

  a = x = y = 0;
  if ((tab = malloc(sizeof(*tab) * (count_pipes(str)) + 1)) == NULL)
    exit(EXIT_FAILURE);
  if (str && str != NULL)
    {
      while (str[a] != '\0')
	{
	  if ((tab[y] = malloc(20)) == NULL) return (NULL);
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
  my_showtab(tab);
  return (tab);
}
