/*
** double2.c for shell.h in /home/lavign_t/rendu/C/PSU/42sh
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Fri Jun  3 11:50:06 2016 thomas lavigne
** Last update Fri Jun  3 11:55:08 2016 thomas lavigne
*/

#include "shell.h"

void	get_type(char *str, int *type, int i)
{
  while (str && str[i] != 0)
    {
      if ((str[i] == '|' && str[i + 1] != '|') && str[i + 1] != 0)
        i++;
      if ((str[i] == '&' && str[i + 1] != '&') && str[i + 1] != 0)
	i++;
      if (str[i] == '|' && str[i + 1] == '|')
        {
          *type = 2;
          return ;
        }
      if (str[i] == '&' && str[i + 1] == '&')
        {
          *type = 1;
          return ;
        }
      i++;
    }
}

void	double2(char *str, int *i, char *command, int *a)
{
  if (str[*i] == '|' && str[*i + 1] != '|' && str[*i] != 0)
    {
      command[*a] = str[*i];
      *a = *a + 1;
      *i = *i + 1;
    }
  if (str[*i] == '&' && str[*i + 1] != '&' && str[*i] != 0)
    {
      command[*a] = str[*i];
      *a = *a + 1;
      *i = *i + 1;
    }
}
