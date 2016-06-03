/*
** env3.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/src/alex
**
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
**
** Started on  Fri Jun  3 10:28:27 2016 thomas lavigne
** Last update Fri Jun  3 11:50:27 2016 Alexandre Thauvin
*/

#include <stdlib.h>
#include "shell.h"

void	my_setenv_norm(char **arg, int z, t_env *ini2)
{
  if (z == 0 && arg[2] == NULL)
    {
      ini2->temp = malloc2d(ini2->temp, ini2->rows + 1, ini2->cols + 2);
      ini2->temp = strdup2d(ini2->temp, ini2->env2, arg, 1);
      free_tab(ini2->env2);
      ini2->env2 = malloc2d(ini2->env2, ini2->rows + 1, ini2->cols + 2);
      ini2->env2 = strdup2d(ini2->env2, ini2->temp, arg, 0);
      free_tab(ini2->temp);
    }
  if (z == 0 && arg[2] != NULL)
    {
      ini2->temp = malloc2d(ini2->temp, ini2->rows + 1, ini2->cols + 2);
      ini2->temp = strdup2d(ini2->temp, ini2->env2, arg, 2);
      free_tab(ini2->env2);
      ini2->env2 = malloc2d(ini2->env2, ini2->rows + 1, ini2->cols + 2);
      ini2->env2 = strdup2d(ini2->env2, ini2->temp, arg, 0);
      free_tab(ini2->temp);
    }
}
