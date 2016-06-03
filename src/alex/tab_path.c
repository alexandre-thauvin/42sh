/*
** my_strdup.c for  in /home/thauvi_a/rendu/Prog_elem_C/bsq/CPE_2015_BSQ_bootstrap/lib/my
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Fri Dec 18 18:28:11 2015 Thauvin
** Last update Fri Jun  3 11:54:02 2016 Alexandre Thauvin
*/

#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

int	getrows(char *src)
{
  int	z;
  int	nb;

  nb = 0;
  z = 5;
  while (src && src[z] != '\0')
    {
      while (src[z] != ':' && src[z] != '\0')
	z++;
      nb++;
      if (src[z] != '\0')
	z++;
    }
  return (nb);
}

int	getcols(char *src)
{
  int	z;
  int	lengh;
  int	lengh2;

  z = 5;
  lengh2 = 0;
  while (src && src[z] != '\0')
    {
      lengh = 0;
      while (src && src[z] != ':' && src[z] != '\0')
	{
	  z++;
	  lengh++;
	}
      if (src[z] != '\0')
	z++;
      if (lengh > lengh2)
	lengh2 = lengh;
    }
  return (lengh2);
}

char	**mallocdest(char **dest, int rows, int cols)
{
  int	z;

  z = 0;
  if ((dest = malloc((rows + 1) * sizeof(char*))) == NULL)
    exit(1);
  while (z < rows)
    {
      if ((dest[z] = malloc((cols + 2) * sizeof(char))) == NULL)
	exit(1);
      z++;
    }
  dest[z] = NULL;
  return (dest);
}

char		**my_strdup2d(char *src)
{
  t_tab		ini;

  ini.cols = getcols(src);
  ini.rows = getrows(src);
  ini.dest = mallocdest(ini.dest, ini.rows, ini.cols);
  ini.z = 0;
  ini.c = 5;
  ini.a = 0;
  while (src[ini.c] != '\0')
    {
      if (src[ini.c] == ':')
	{
	  ini.dest[ini.z][ini.a] = '\0';
	  ini.c++;
	  ini.z++;
	  ini.a = 0;
	}
      ini.dest[ini.z][ini.a] = src[ini.c];
      ini.a++;
      if (src[ini.c] != '\0')
	ini.c++;
    }
  ini.dest[ini.z][ini.a] = '\0';
  ini.dest[ini.z + 1] = NULL;
  return (ini.dest);
}
