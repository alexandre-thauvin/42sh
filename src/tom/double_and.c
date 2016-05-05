/*
** double_and.c for double_and.c in /home/lalagu_t/rendu/Sem2/PSU/PSU_2015_42sh/src/tom
**
** Made by Lalague-Dulac Tom
** Login   <lalagu_t@epitech.net>
**
** Started on  Tue May  3 11:31:42 2016 Lalague-Dulac Tom
** Last update Thu May  5 17:31:21 2016 Lalague-Dulac Tom
*/

#include "shell.h"

int		my_strlenspe(char *str, int i, char c)
{
  int		nb;

  nb = 0;
  while (str[i] != c)
    {
      i++;
      nb++;
    }
  return (nb);
}

char		*help(char *str, int i, int j, char *stock)
{
  if (i != 0)
    i = i + 3;
  if ((stock = malloc(my_strlenspe(str, i, '\0') + 1)) == NULL)
    return (NULL);
  while (str[i] != '&' && str[i] != '\0')
    {
      stock[j] = str[i];
      i++;
      j++;
    }
  stock[j] = '\0';
  return (stock);
}

char		*catch(char *str, int i, t_second *ini)
{
  if ((ini->stock = malloc(sizeof(str) + 1)) == NULL)
    return (NULL);
  while (str && str[i] != '\0' && str[i] != ' ' && str[i] != '&')
    {
      ini->stock[i] = str[i];
      i++;
    }
  ini->stock[i] = '\0';
  return (ini->stock);
}

void            check_if_and(char *str, int i, t_second *ini)
{
  while (str[i] != '\0')
    {
      if (str[i] == '&' && str[i + 1] == '&')
	ini->nb_and = 1;
      i++;
    }
  ini->nb_and = 0;
}

char		*double_and(char *str, t_second *ini)
{
  int		j;

  j = 0;
  if (ini->v == 0)
    {
      ini->stock = catch(str, ini->v, ini);
      ini->v++;
      return (ini->stock);
    }
  while (str && str[ini->v] != '\0')
    {
      check_if_and(str, ini->v, ini);
      if (str[ini->v] == '&' && str[ini->v + 1] == '&')
	{
	  if ((ini->stock = help(str, ini->v, j, ini->stock)) == NULL)
	    return (NULL);
	  else
	    return (ini->stock);
	  ini->v = ini->v + 2;
	}
      ini->v++;
    }
  return (NULL);
}
