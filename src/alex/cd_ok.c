/*
** cd.c for  in /home/thauvi_a/rendu/shell/PSU_2015_minishell1
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Sun Jan 24 18:28:58 2016 Thauvin
** Last update Fri Apr 29 01:53:48 2016 Thauvin
*/

#include "shell.h"

char	 *my_strcpy_norm(char *dest, char *src)
{
  int   z;
  int	a;

  a = 0;
  z = 5;
  while (src[z] != '\0')
    {
      dest[a] = src[z];
      z = z + 1;
      a++;
    }
  dest[a] = '\0';
  return (dest);
}

char	*pars_home(char **env, char *home)
{
  int	a;

  a = 0;
  while (env[a][0] != 'H' || env[a][1] != 'O' || env[a][2] != 'M'
	 || env[a][3] != 'E' || env[a][4] != '=')
    a++;
  if ((home = malloc(sizeof(char) * my_strlenPATH(env[a]) + 1)) == NULL)
    exit(-42);
  home = my_strcpy_norm(home, env[a]);
  return (home);
}

void	ini_var_cd(t_var_cd *ini)
{
  ini->z = 0;
  ini->a = 0;
  ini->i = 0;
}

char	*cpy_tab_path(t_var_cd *ini, char **arg, char *path_final)
{
  if ((ini->dest = malloc(100 * sizeof(char))) == NULL)
    exit(-42);
  ini->dest = getcwd(ini->dest, 100);
  ini->z = my_strlen(ini->dest);
  if ((path_final = malloc((ini->z + my_strlen(arg[1]) + 2)
			   * sizeof(char))) == NULL)
    exit(-42);
  while (ini->a < ini->z)
    {
      path_final[ini->a] = ini->dest[ini->a];
      ini->a++;
    }
  ini->z = ini->z + my_strlen(arg[1]);
  free(ini->dest);
  path_final[ini->a] = '/';
  ini->a++;
  while (ini->a < (ini->z + 1))
    {
      path_final[ini->a] = arg[1][ini->i];
      ini->i++;
      ini->a++;
    }
  path_final[ini->a] = '\0';
  return (path_final);
}

char	*check_cd(char **arg, char *path_final, int rows, char **env)
{
  t_var_cd	ini;

  ini_var_cd(&ini);
  if (rows > 1)
    {
      if (arg[1][0] != '/')
	path_final = cpy_tab_path(&ini, arg, path_final);
      else
	{
	  ini.z = my_strlen(arg[1]);
	  if ((path_final = malloc((ini.z + 1) * sizeof(char))) == NULL)
	    exit(-42);
	  while (ini.a < ini.z)
	    {
	      path_final[ini.a] = arg[1][ini.a];
	      ini.a++;
	    }
	  path_final[ini.a] = '\0';
	}
    }
  if (arg[1] == NULL || arg[1][0] == '~')
    path_final = pars_home(env, path_final);
  return (path_final);
}
