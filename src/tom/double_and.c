/*
** double_and.c for double_and.c in /home/lalagu_t/rendu/Sem2/PSU/PSU_2015_42sh/src/tom
** 
** Made by Lalague-Dulac Tom
** Login   <lalagu_t@epitech.net>
** 
** Started on  Tue May  3 11:31:42 2016 Lalague-Dulac Tom
** Last update Tue May  3 12:16:40 2016 Lalague-Dulac Tom
*/

#include "../../include/shell.h"

char            *recup_command(char *buff)
{
  int           i;
  char          *str;

  i = 0;
  if ((str = malloc(sizeof(buff) + 1)) == NULL)
    return (NULL);
  if (buff[0] == '/')
    return (NULL);
  while (buff && buff[i] != ' ' && buff[i] != '\0' && buff[i] != '\n')
    {
      str[i] = buff[i];
      i++;
    }
  str[i] = '\0';
}

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
  while (str[i] != '&' && str[i] != '\0')
    i++;
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

void		double_and(char *str, char **tab)
{
  int		i;
  int		j;
  char		*stock;
  char		*name;

  i = j = 0;
  while (str && str[i] != '\0')
    {
      stock = help(str, i, j, stock);
      printf("stock = %s\n", stock);
      if ((name = recup_command(stock)) != NULL)
        /* if (check_builtin de alex == 0)
	   res = 1;
	   if (check_exec de alex == 0)
	   {
	     printf("COMMAND NOT FOUND\n");
	     - rappeler la boucle principale du 42sh
	     (car on a trouvé aucun match au niveau de la commande donc le && se stoppe)
	   }
	*/
      i++;
    }
}

int		main()
{
  char	        *str = "ls && ls";
  char		*tab[6];

  tab[0] = "/bin\0";
  tab[1] = "/sbin\0";
  tab[2] = "/usr/bin\0";
  tab[3] = "/usr/sbin\0";
  tab[4] = "/usr/heimdal/bin\0";
  tab[5] = "/usr/heimdal/sbin\0";
  tab[6] = NULL;
  double_and(str, tab);
}
