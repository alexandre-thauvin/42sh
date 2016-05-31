/*
** alpha_num.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/save 42sh/PSU_2015_42sh/src/thomas
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Tue May 31 15:21:41 2016 thomas lavigne
** Last update Tue May 31 18:05:44 2016 thomas lavigne
*/

#include "shell.h"

int	alpha_num(char **arg, t_second *ini)
{
  int	i;
  int	x;

  x = i = 0;
  while (arg && arg[i] != NULL)
    {
      if ((arg[i][0] < 'a' || arg[i][0] > 'z') &&
	  (arg[i][0] < 'A' || arg[i][0] > 'Z'))
	  {
	    fprintf(stderr, "setenv: Variable ");
	    fprintf(stderr, "name must begin with a letter.\n");
	    ini->check = -1;
	    return (-1);
	  }
      while (arg[i][x] != 0)
      	{
      	  if ((arg[i][x] < '0' || arg[i][x] > '9') &&
      	      (arg[i][x] < 'a' || arg[i][x] > 'z') &&
      	      (arg[i][x] < 'A' || arg[i][x] > 'Z'))
	    {
	      fprintf(stderr, "setenv: Variable name must contain ");
	      fprintf(stderr, "alphanumeric characters.\n");
	      ini->check = -1;
	      return (-1);
	    }
      	  x++;
      	}
      x = 0;
      i++;
    }
  return (0);
}
