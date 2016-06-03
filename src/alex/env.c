/*
** env.c for  in /home/thauvi_a/rendu/shell/PSU_2015_minishell2/src
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Wed Mar 30 15:42:06 2016 Thauvin
** Last update Fri Jun  3 12:05:25 2016 Alexandre Thauvin
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

void	show_env(char **env)
{
  int	z;

  z = 0;
  while (env[z] != NULL)
    {
      write(1, env[z], my_strlen(env[z]));
      write(1, "\n", 1);
      z++;
    }
}

void	my_setenv(t_env *ini2, char **arg, t_second *ini)
{
  int	z;

  z = strcmp_env(ini2->env2, arg[1]);
  if (z != 0)
    ini2->env2[z] = my_strcpy_update(ini2->env2[z], arg);
  if (arg[3] != NULL && arg[2] != NULL)
    {
      ini->error.check2 = -1;
      fprintf(stderr, "setenv : Too many arguments.\n");
      return ;
    }
  if (alpha_num(arg, ini) == -1)
    return ;
  my_setenv_norm(arg, z, ini2);
}

void	strdup2d_env(t_env *ini, int z)
{
  int	i;

  i = 0;
  while (i < z)
    {
      ini->temp[i] = my_strcpy(ini->temp[i], ini->env2[i]);
      i++;
    }
  i = ini->rows;
  ini->temp[i - 1] = NULL;
  i--;
  while (i > z)
    {
      ini->temp[i -1] = my_strcpy(ini->temp[i - 1], ini->env2[i]);
      i--;
    }
}

void	my_unenv(t_env *ini2, char **arg)
{
  int	z;

  z = strcmp_env(ini2->env2, arg[1]);
  if (z != 0)
    {
      ini2->temp = malloc2d(ini2->temp, ini2->rows - 1, ini2->cols + 1);
      strdup2d_env(ini2, z);
      free_tab(ini2->env2);
      ini2->env2 = malloc2d(ini2->env2, ini2->rows - 1, ini2->cols + 1);
      ini2->env2 = strdup2d(ini2->env2, ini2->temp, arg, 0);
      free_tab(ini2->temp);
    }
}

void	pars_builtenv(t_env *ini2, char **arg, t_second *ini)
{
  get_rows_env(ini2->env2, ini2);
  get_cols_env(ini2->env2, ini2);
  if ((my_strcmp(arg[0], "unsetenv")) == 1)
    {
      ini->error.zombie = 1;
      if (arg[1] == NULL)
	  write(2, "unsetenv: Too few arguments.\n", 29);
      else
	my_unenv(ini2, arg);
    }
  if ((my_strcmp(arg[0], "env")) == 1)
    {
      ini->error.zombie = 1;
      show_env(ini2->env2);
    }
  if ((my_strcmp(arg[0], "setenv")) == 1)
    {
      ini->error.zombie = 1;
      if (arg[1] == NULL)
	show_env(ini2->env2);
      if (arg[1] != NULL)
	my_setenv(ini2, arg, ini);
    }
}
