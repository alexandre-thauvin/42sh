/*
** double_pipe.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/src/benji
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Mon May 30 14:02:48 2016 thomas lavigne
** Last update Fri Jun  3 11:55:48 2016 thomas lavigne
*/

#include <stdlib.h>
#include "shell.h"

int	my_strcmp_toto(char *str1, char *str2)
{
  int	x;

  x = 0;
  while (str1 && str2 && str1[x] != 0)
    {
      if (str1[x] != str2[x])
	return (-1);
      x++;
    }
  return (0);
}

int	size_comm(char *str, int *i)
{
  int	a;

  a = *i;
  while (str && str[a] != '&' && str[a] != '|' && str[a] != 0)
    {
      if (str[a] == '|' && (str[a + 1] != '|' || str[a + 1] != 0))
	a++;
      if (str[a] == '&' && (str[a + 1] != '&' || str[a + 1] != 0))
	a++;
      a++;
    }
  return (a);
}

char	*get_command(char *str, int *i)
{
  char	*command;
  int	a;

  a = 0;
  while (str && (str[*i] == ' ' || str[*i] == '\t'))
    *i = *i + 1;
  if (str[*i] == 0)
    return (NULL);
  if ((command = malloc(sizeof(char) * (size_comm(str, i) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (str && str[*i] != '&' && str[*i] != '|' && str[*i] != 0)
    {
      command[a++] = str[*i];
      *i = *i + 1;
      double2(str, i, command, &a);
    }
  command[a] = 0;
  if (str[*i] == '&' || str[*i] == '|')
    *i = *i + 2;
  return (command);
}

char	*double_pipe(char *str, int *type)
{
  char		*command;
  static int	i = 0;
  static char	*comp = NULL;

  get_type(str, type, i);
  if (my_strcmp_toto("reset", str) == 0)
    {
      i = 0;
      comp = NULL;
      return (NULL);
    }
  if (my_strcmp_toto(str, comp) == -1)
    {
      i = 0;
      comp = str;
    }
  if ((command = get_command(str, &i)) != NULL)
    return (command);
  if (command == NULL)
    {
      i = 0;
      return (NULL);
    }
  return (NULL);
}
