/*
** first.c for  in /home/thauvi_a/rendu/shell
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Tue Jan 19 15:41:41 2q016 Thauvin
** Last update Thu Apr 28 09:20:07 2016 Lalague-Dulac Tom
*/

#include "shell.h"

int	file_exist(t_second *ini, int rows)
{
  int	z;
  int	a;

  a = 0;
  z = -1;
  z = access(ini->arg[0], F_OK);
  if (z == 0)
    return (-1);
  while (z != 0 && a < rows)
    {
      z = access(ini->PATHfinal[a], F_OK);
      if (z == 0)
	return (a);
      a++;
    }
  return (-1);
}

int	my_strlenPATH(char *str)
{
  int	z;

  z = 5;
  while (str[z] != '\0')
    z++;
  return (z);
}

char	*cpy_path(char **env)
{
  char	*dest;
  int	a;

  a = strcmp_env(env, "PATH");
  if (env[a][5] == '\0')
    return (NULL);
  if (a != 0)
    {
      if ((dest = malloc(sizeof(char) * my_strlenPATH(env[a]) + 1)) == NULL)
	return (NULL);
      dest = my_strcpy(dest, env[a]);
      return (dest);
    }
  else
    return (NULL);
}

void		ini_var_lanceur(t_second *ini, char *commande, t_env *ini2)
{
  ini->pathtemp = cpy_path(ini2->env2);
  ini->check2 = 0;
  ini->check = 0;
  ini->relative = 0;
  ini->s = 0;
  if (ini->pathtemp != NULL)
    {
      ini->rows_PATH = getrows(ini->pathtemp);
      ini->rows_arg = getrows_tab(commande);
      ini->cols_PATH = getcols(ini->pathtemp);
      ini->PATH = mallocdest(ini->PATH, ini->rows_PATH, ini->cols_PATH);
      ini->PATH = my_strdup2d(ini->pathtemp);
    }
  ini->arg = ma2d(ini->arg, ini->rows_arg, commande);
  ini->arg = my_strduptab(commande);
  if (ini->pathtemp != NULL)
    {
      ini->PATHfinal = ma(ini->PATHfinal, ini->rows_PATH,
			  ini->cols_PATH, ini->arg);
      ini->PATHfinal = my_strdup_path(ini->PATH, ini->pathtemp, ini->arg);
    }
  if (ini->arg[0][0] == 0)
    ini->zombie = 1;
}

int		lanceur(char *commande, char **env, t_env *ini2, t_second *ini)
{
  static int	z = 0;

  ini->zombie = 0;
  if (z == 0)
    {
      if ((ini->pwd = malloc(1024 * sizeof(char))) == NULL)
	return (-1);
      getcwd(ini->pwd, 1024);
      ini_var_tab(env, ini2, ini);
    }
  z++;
  ini_var_lanceur(ini, commande, ini2);
  pars_builtenv(ini2, ini->arg, ini);
  exec_cd(ini, commande, ini2);
  if (ini->arg[0][0] == '.' && ini->arg[0][1] == '/')
    ini->check = check_courant(ini);
  else
    {
      if (ini->zombie == 0 && ini->pathtemp != NULL)
	wait_in_fath(ini, commande, ini2->env2, ini->arg);
      if (ini->check2 != -1 && ini->pathtemp == NULL && ini->zombie == 0)
	wait_in_fath(ini, commande, ini2->env2, ini->arg);
    }
  error(ini, commande, ini2);
  return (ini->check_ex);
}