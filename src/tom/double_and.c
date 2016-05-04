/*
** double_and.c for double_and.c in /home/lalagu_t/rendu/Sem2/PSU/PSU_2015_42sh/src/tom
**
** Made by Lalague-Dulac Tom
** Login   <lalagu_t@epitech.net>
**
** Started on  Tue May  3 11:31:42 2016 Lalague-Dulac Tom
** Last update Wed May  4 22:41:05 2016 Thauvin
** Last update Wed May  4 18:44:55 2016 Lalague-Dulac Tom
*/

#include "../../include/shell.h"

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
  while (str[i] != '&' && str[i] != '\0' && str[i] != ' ')
    {
      stock[j] = str[i];
      i++;
      j++;
    }
  stock[j] = '\0';
  return (stock);
}

char		*catch(char *str, int i, char *stock)
{
  if ((stock = malloc(sizeof(str) + 1)) == NULL)
    return (NULL);
  while (str && str[i] != '\0' && str[i] != ' ' && str[i] != '&')
    {
      stock[i] = str[i];
      i++;
    }
  return (stock);
}

char		*double_and(char *str, char **tab)
{
  static int    i = 0;
  int		j;
  char		*stock;

  j = 0;
  if (i == 0)
    {
      stock = catch(str, i, stock);
      i++;
      return (stock);
    }
  while (str && str[i] != '\0')
    {
      if (str[i] == '&' && str[i + 1] == '&')
	{
	  if ((stock = help(str, i, j, stock)) == NULL)
	    return (NULL);
	  // return stock (qui est la commande) puis rappeler ma fonction avec la static
	  printf("stock = %s\n", stock);
	  i = i + 2;
	}
      i++;
    }
  return (NULL);
}

int		check_if_and(char *str, int i)
{
  while (str[i] != '\0')
    {
      if (str[i] == '&' && str[i + 1] == '&')
	{
	  //ini->nb_and = 1;
	  i = 1;
	  return (i);
	}
      i++;
    }
  //ini->nb_and = 0;
  i = 0;
  return (i);
}

int		main(int ac, char **av)
{
  char	        *str = "ls && ls -l";

  int		i;
  t_second	*ini;
  char		*tab[6];
  char		*stock;

  i = 0;
  if (ac == 1)
    return (0);
  tab[0] = "/bin\0";
  tab[1] = "/sbin\0";
  tab[2] = "/usr/bin\0";
  tab[3] = "/usr/sbin\0";
  tab[4] = "/usr/heimdal/bin\0";
  tab[5] = "/usr/heimdal/sbin\0";
  tab[6] = NULL;
  i = check_if_and(av[1], i);
  if ((stock = double_and(av[1], tab)) != NULL)
    printf("stock = %s\n", stock);
  if ((stock = double_and(av[1], tab)) != NULL)
    printf("stock = %s\n", stock);
}
