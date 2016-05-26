/*
** my_strdup.c for  in /home/thauvi_a/rendu/Prog_elem_C/bsq/CPE_2015_BSQ_bootstrap/lib/my
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Fri Dec 18 18:28:11 2015 Thauvin
** Last update Thu May 26 15:43:51 2016 Thauvin
*/

#include "shell.h"

int	file_path_exist(char *commande)
{
  int	z;

  z = 0;
  z = access(commande, F_OK);
  if (z == 0)
    return (0);
  else
    return (-1);
}

int	check_exit(char **arg, int rows)
{
  int	z;

  z = 0;
  if ((my_strcmp("exit", arg[0])) == 1)
    {
      if (arg[1] != NULL)
	z = my_getnbr(arg[1]);
      if (rows == 1)
	z = 0;
      exit(z);
    }
  return (z);
}

char	**ma(char **dest, int rows, int cols, char **arg)
{
  int	z;
  int	a;

  z = 0;
  a = my_strlen(arg[0]);
  rows++;
  if ((dest = malloc(rows * sizeof(char*))) == NULL)
    exit(1);
  while (z < rows)
    {
      if ((dest[z] = malloc((cols + a + 2) * sizeof(char))) == NULL)
	exit(1);
      z++;
    }
  return (dest);
}

void	ini_var_strdup(t_tab3 *ini, char *path, char **arg)
{
  ini->cols = getcols(path);
  ini->rows = getrows(path);
  ini->dest = ma(ini->dest, ini->rows + 1, ini->cols, arg);
  ini->z = 0;
  ini->a = 0;
  ini->m = 0;
}

char		**my_strdup_path(char **PATH_2D, char *PATH, char **arg)
{
  t_tab3	ini;

  ini_var_strdup(&ini, PATH, arg);
  while (ini.z < ini.rows)
    {
      while (PATH_2D[ini.z][ini.a] != '\0')
	{
	  ini.dest[ini.z][ini.a] = PATH_2D[ini.z][ini.a];
	  ini.a++;
	}
      ini.dest[ini.z][ini.a] = '/';
      ini.a++;
      while (ini.m < (my_strlen(arg[0])))
	{
	  ini.dest[ini.z][ini.a] = arg[0][ini.m];
	  ini.a++;
	  ini.m++;
	}
      ini.dest[ini.z][ini.a] = '\0';
      ini.z++;
      ini.a = 0;
      ini.m = 0;
    }
  ini.dest[ini.z] = NULL;
  return (ini.dest);
}
