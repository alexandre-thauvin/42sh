/*
** my_strdup.c for  in /home/thauvi_a/rendu/Prog_elem_C/bsq/CPE_2015_BSQ_bootstrap/lib/my
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Fri Dec 18 18:28:11 2015 Thauvin
** Last update Thu Apr 28 09:23:10 2016 Lalague-Dulac Tom
*/

#include "shell.h"

int	getrows(char *src)
{
  int	z;
  int	nb;

  nb = 0;
  z = 5;
  while (z < my_strlen(src))
    {
      while (src[z] != ':' && z < my_strlen(src))
	z++;
      nb++;
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
  while (z < my_strlen(src))
    {
      lengh = 0;
      while (src[z] != ':' && z < my_strlen(src))
	{
	  z++;
	  lengh++;
	}
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
  rows++;
  if ((dest = malloc(rows * sizeof(char*))) == NULL)
    return (NULL);
  while (z < rows)
    {
      if ((dest[z] = malloc(cols * sizeof(char) + 1)) == NULL)
	return (NULL);
      z++;
    }
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
      ini.c++;
    }
  ini.dest[ini.z][ini.a] = '\0';
  ini.dest[ini.z + 1] = NULL;
  return (ini.dest);
}
