/*
** double_pipe.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/src/benji
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Mon May 30 14:02:48 2016 thomas lavigne
** Last update Wed Jun  1 11:17:19 2016 thomas lavigne
*/

#include "shell.h"

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  if (str2 == NULL)
    return (-1);
  while (str1 && str2 && str1[i] != 0)
    {
      if (str1[i] != str2[i])
	return (-1);
      i++;
    }
  return (0);
}

int	size_comm(char *str, int *i, char carac)
{
  int	a;

  a = *i;
  while (str && str[a] != carac && str[a] != 0)
    {
      if (str[a] == carac && (str[a + 1] != carac || str[a + 1] != 0))
	a++;
      a++;
    }
  return (a);
}

char	*get_command(char *str, int *i, char car)
{
  char	*command;
  int	a;

  a = 0;
  while (str[*i] == ' ' || str[*i] == '\t')
    *i = *i + 1;
  if (str[*i] == 0)
    return (NULL);
  if ((command = malloc(sizeof(char) * (size_comm(str, i, car) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (str && str[*i] != car && str[*i] != 0)
    {
      command[a++] = str[*i];
      *i = *i + 1;
      if (str[*i] == car && str[*i + 1] != car && str[*i] != 0)
	{
	  command[a++] = str[*i];
	  *i = *i + 1;
	}
    }
  command[a] = 0;
  if (str[*i] == car)
    *i = *i + 2;
  return (command);
}

char	*double_pipe(char *str, char carac)
{
  char		*command;
  static int	i = 0;
  static char	*comp = NULL;

  if (my_strcmp("reset", str) == 0)
    {
      i = 0;
      comp = NULL;
      return (NULL);
    }
  if (my_strcmp(str, comp) == -1)
    {
      i = 0;
      comp = str;
    }
  if ((command = get_command(str, &i, carac)) != NULL)
    return (command);
  if (command == NULL)
    {
      i = 0;
      return (NULL);
    }
  return (NULL);
}
