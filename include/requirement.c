/*
** str_tab.c for  in /home/quasta_b/rendu/Piscine2/SBMLparser/src
** 
** Made by Benjamin Quastana
** Login   <quasta_b@epitech.net>
** 
** Started on  Mon Jun 13 09:20:14 2016 Benjamin Quastana
** Last update Wed Jun 15 09:04:49 2016 Benjamin Quastana
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	count_words(char *str)
{
  int	w;
  int	i;

  i = 0;
  w = 0;
  while (str && str[i] != '\0')
    {
      if ((str[i] > 64 && str[i] < 91) || 
	  (str[i] > 96 && str[i] < 123) ||
	  (str[i] >= '0' && str[i] <= '9'))
	{
	  w++;
	  while ((str[i] > 64 && str[i] < 91) || 
		 (str[i] > 96 && str[i] < 123) ||
		 (str[i] >= '0' && str[i] <= '9'))
	    i++;
	}
      else
	i++;
    }
  return (w);
} 

int	my_strlen(char *str, int pos)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  if (str)
    {
      if ((str[pos] > 64 && str[pos] < 91) || 
	  (str[pos] > 96 && str[pos] < 123) ||
	  (str[pos] >= '0' && str[pos] <= '9'))
	{
	  a = 1;
	  while ((str[pos] > 64 && str[pos] < 91) || 
		 (str[pos] > 96 && str[pos] < 123) ||
		 (str[i] >= '0' && str[i] <= '9'))
	    {
	      pos++;
	      i++;
	    }
	}
      else if (a != 1)
	pos++;
    }
  return (i);
}

char	**my_strtowordtab_synthesis(char *str)
{
  int	i;
  int	y;
  int	x;
  char	**tab;

  i = y = x = 0;
  if ((tab = malloc(sizeof (*tab) * count_words(str))) == NULL) return (NULL);
  while (str && str[i] != '\0')
    {
      if ((tab[y] = malloc(my_strlen(str, i))) == NULL) return (NULL);
      if ((str[i] > 64 && str[i] < 91) ||
	  (str[i] > 96 && str[i] < 123) ||
	  (str[i] >= '0' && str[i] <= '9'))
	{
	  while ((str[i] > 64 && str[i] < 91) ||
		 (str[i] > 96 && str[i] < 123) ||
		 (str[i] >= '0' && str[i] <= '9'))
	    tab[y][x++] = str[i++];
	  tab[y][x] = '\0';
	  x = 0;
	  y++;
	}
      else
	i++;
    }
  tab[y] = NULL;
  y = 0;
  while (tab[y] != NULL)
    printf("%s\n", tab[y++]);
  return (tab);
}

int	main(int ac, char **av)
{
  int	fd;
  int	i;
  char	**tab;
  char	buff[4096];

  i = 0;
  fd = open(av[1], O_RDONLY);
  read(fd, buff, 4096);
  my_strtowordtab_synthesis(buff);
}
