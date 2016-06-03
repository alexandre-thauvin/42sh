/*
** env2.c for  in /home/thauvi_a/rendu/shell/PSU_2015_minishell2/src
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Sun Apr  3 16:30:00 2016 Thauvin
** Last update Fri Jun  3 11:49:46 2016 Alexandre Thauvin
*/

#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

void	get_rows_env(char **env, t_env *ini2)
{
  ini2->rows = 0;
  while (env[ini2->rows] != NULL)
    ini2->rows++;
}

void	get_cols_env(char **env, t_env *ini2)
{
  int	z;
  int	i;

  i = 0;
  z = 0;
  ini2->cols = 0;
  while (env[i] != NULL)
    {
      while (env[i][z] != '\0')
	z++;
      if (z > ini2->cols)
	ini2->cols = z;
      z = 0;
      i++;
    }
}

int	strcmp_env(char **env, char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (env[i] != NULL)
    {
      while (env[i][j] == str[j] && str[j] != '\0')
	j++;
      if ((j != 0 && env[i][j - 1] == '=') || str[j] == '\0')
	return (i);
      else
	{
	  i++;
	  j = 0;
	}
    }
  return (0);
}

char	*my_strcpy_update(char *dest, char **src)
{
  int	i;
  int	u;

  i = 0;
  u = 0;
  while (src[1][u] != '\0')
    {
      dest[i] = src[1][u];
      u++;
      i++;
    }
  dest[i] = '=';
  i++;
  u = 0;
  if (src[2] != NULL)
    {
      while (src[2][u] != '\0')
	{
	  dest[i] = src[2][u];
	  i++;
	  u++;
	}
    }
  dest[i] = '\0';
  return (dest);
}

char	**strdup2d(char **dest, char **src, char **str, int u)
{
  int	z;

  z = 0;
  while (src[z] != NULL)
    {
      dest[z] = my_strcpy(dest[z], src[z]);
      z++;
    }
  if (u == 1)
    {
      dest[z] = my_strcpy(dest[z], str[1]);
      dest[z][my_strlen(str[1])] = '=';
      dest[z][my_strlen(str[1]) + 1] = '\0';
      dest[z + 1] = NULL;
    }
  if (u == 0)
      dest[z] = NULL;
  if (u == 2)
    {
      dest[z] = my_strcpy_update(dest[z], str);
      dest[z + 1] = NULL;
    }
  return (dest);
}
