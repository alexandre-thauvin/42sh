/*
** first.c for  in /home/thauvi_a/rendu/shell
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Tue Jan 19 15:41:41 2q016 Thauvin
** Last update Wed Jun  1 15:51:01 2016 thomas lavigne
*/

#include "shell.h"

int	file_exist(t_second *ini)
{
  int	z;
  int	a;

  a = 0;
  z = -1;
  if (ini->vpath.pathtemp == NULL)
    return (-1);
  z = access(ini->arg[0], F_OK);
  if (z == 0)
    return (0);
  while (z != 0 && ini->vpath.PATHfinal[a] != NULL)
    {
      z = access(ini->vpath.PATHfinal[a], F_OK);
      if (z == 0)
	return (a);
      a++;
    }
  ini->nb_and = 0;
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
	exit(1);
      dest = my_strcpy(dest, env[a]);
      return (dest);
    }
  else
    return (NULL);
}

void		ini_var_lanceur(t_second *ini, char *commande, t_env *ini2)
{
  int	rows_PATH;
  int	cols_PATH;

  ini->vpath.pathtemp = cpy_path(ini2->env2);
  ini->check2 = ini->check = ini->relative = ini->s = 0;
  ini->rows_arg = getrows_tab(commande);
  if (ini->vpath.pathtemp != NULL)
    {
      rows_PATH = getrows(ini->vpath.pathtemp);
      cols_PATH = getcols(ini->vpath.pathtemp);
      ini->vpath.PATH = mallocdest(ini->vpath.PATH, rows_PATH, cols_PATH);
      ini->vpath.PATH = my_strdup2d(ini->vpath.pathtemp);
    }
  ini->arg = ma2d(ini->arg, ini->rows_arg, commande);
  ini->arg = my_strduptab(commande);
  if (ini->vpath.pathtemp != NULL)
    {
      ini->vpath.PATHfinal = ma(ini->vpath.PATHfinal, rows_PATH,
			  cols_PATH, ini->arg);
      ini->vpath.PATHfinal = my_strdup_path(ini->vpath.PATH,
				      ini->vpath.pathtemp, ini->arg);
    }
  if (ini->arg[0][0] == 0)
    ini->zombie = 1;
}

int		lanceur(char *commande, t_env *ini2, t_second *ini)
{
  static int	z = 0;

  ini->zombie = 0;
  if (z == 0)
    {
      if ((ini->pwd = malloc(1024 * sizeof(char))) == NULL)
	exit(1);
      getcwd(ini->pwd, 1024);
    }
  z++;
  if (ini->nb_pipe != 0)
  {
    create_tab(commande, ini, ini2);
    return (0);
  }
  ini_and_builtin(commande, ini2, ini);
  if (ini->arg[0][0] == '.' && ini->arg[0][1] == '/')
    ini->check = check_courant(ini);
  else
    lanceur_commande(commande, ini2, ini);
  error(ini, commande, ini2);
  return (ini->check_ex);
}
