/*
** my_strdup.c for  in /home/thauvi_a/rendu/Prog_elem_C/bsq/CPE_2015_BSQ_bootstrap/lib/my
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Fri Dec 18 18:28:11 2015 Thauvin
** Last update Thu Apr 28 09:22:28 2016 Lalague-Dulac Tom
*/

#include "shell.h"

int	getrows_tab(char *src)
{
  int	z;
  int	nb;

  nb = 1;
  z = 0;
  while (z < my_strlen(src))
    {
      if ((src[z] == 32 || src[z] == '\t') &&
	 src[z + 1] != 32 && (z + 1) < my_strlen(src))
	{
	  nb++;
	}
      z++;
    }
  return (nb);
}

char		**ma2d(char **dest, int rows, char *commande)
{
  t_var_malloc	ini;

  ini.z = 0;
  ini.cols2 = 0;
  while (commande[ini.z] != '\0')
    {
      ini.cols = 0;
      while (commande[ini.z] != ' ' && ini.z < my_strlen(commande) &&
	     commande[ini.z] != '\t')
	{
	  ini.cols++;
	  ini.z++;
	}
      ini.z++;
      if (ini.cols > ini.cols2)
	ini.cols2 = ini.cols;
    }
  ini.z = 0;
  if ((dest = malloc((rows + 1) * sizeof(char*))) == NULL)
    return (NULL);
  while (ini.z < rows)
    {
      if ((dest[ini.z] = malloc(ini.cols2 * sizeof(char) + 1)) == NULL)
	return (NULL);
      ini.z++;
    }
  return (dest);
}

void	ini_var_strduptab(t_tab2 *ini, char *src)
{
  ini->rows = getrows_tab(src);
  ini->dest = ma2d(ini->dest, ini->rows, src);
  ini->z = 0;
  ini->c = 0;
  ini->a = 0;
  ini->w = 0;
}

void	end_string(t_tab2 *ini)
{
  ini->dest[ini->z][ini->a] = '\0';
  ini->z++;
  ini->a = 0;
}

char		**my_strduptab(char *src)
{
  t_tab2	ini;

  ini_var_strduptab(&ini, src);
  while (ini.z < ini.rows && ini.c < my_strlen(src))
    {
      while (src[ini.c] == ' ' || src[ini.c] == '\t')
	{
	  ini.c++;
	  if (ini.w == 1 && src[ini.c] != 32 && ini.c < my_strlen(src)
	      && src[ini.c] != '\t')
	    {
	      end_string(&ini);
	    }
	}
      if (src[ini.c] != 32 && ini.c < my_strlen(src) && src[ini.c] != '\t')
	{
	  ini.dest[ini.z][ini.a] = src[ini.c];
	  ini.a++;
	  ini.c++;
	}
      ini.w = 1;
    }
  ini.dest[ini.z][ini.a] = '\0';
  ini.dest[ini.z + 1] = NULL;
  return (ini.dest);
}
