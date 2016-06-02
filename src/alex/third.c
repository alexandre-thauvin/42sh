/*
** third.c for  in /home/thauvi_a/rendu/shell/PSU_2015_minishell2/src
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Sun Apr 10 18:19:32 2016 Thauvin
** Last update Thu Jun  2 20:25:32 2016 thomas lavigne
*/

#include "shell.h"

void	check_zomb(t_second *ini)
{
  ini->error.check2 = file_path_exist(ini->comm.arg[0]);
  if (ini->error.check2 != -1)
    ini->relative = 1;
  else
    ini->error.zombie = 1;
}

void	error(t_second *ini, char *commande, t_env *ini2)
{
  if (ini->error.check != -1 && (commande[0] == '.' && commande[1] == '/'))
    wait_in_fath(ini, commande, ini2->env2, ini->comm.arg);
  if ((ini->error.check2 == -1 || ini->error.check == -1 ||
       (ini->vpath.pathtemp == NULL && ini->error.zombie == 0 &&
	ini->error.check2 == -1)) && ini->error.zombie != 1)
    {
      ini->check.nb_and = 0;
      write(2, ini->comm.arg[0], my_strlen(ini->comm.arg[0]));
      write(2, ": Command not found.\n", my_strlen(": Command not found.\n"));
    }
}

int	check_courant(t_second *ini)
{
  if ((access(ini->comm.arg[0], F_OK)) == 0)
    return (0);
  else
    return (-1);
  return (-1);
}

void	exec_cd_tiret(t_second *ini)
{
  if ((ini->vpwd.oldpwd = malloc((my_strlen(ini->vpwd.pwd) + 2)
			    * sizeof(char))) == NULL)
    exit(1);
  ini->vpwd.oldpwd = my_strcpy(ini->vpwd.oldpwd, ini->vpwd.pwd);
  free(ini->vpwd.pwd);
  if ((ini->vpwd.pwd = malloc(1024 * sizeof(char))) == NULL)
    exit(1);
  getcwd(ini->vpwd.pwd, 1024);
}

void	complete_pwd(t_second *ini)
{
  ini->u = 0;
  if (ini->comm.arg[1] != NULL)
    if (ini->comm.arg[1][0] == '-')
      ini->u = 1;
  if (ini->u == 1)
    exec_cd_tiret(ini);
  else
    {
      if ((ini->vpwd.oldpwd = malloc((my_strlen(ini->vpwd.pwd) + 2)
				* sizeof(char))) == NULL)
	exit(1);
      ini->vpwd.oldpwd = my_strcpy(ini->vpwd.oldpwd, ini->vpwd.pwd);
      free(ini->vpwd.pwd);
      if ((ini->vpwd.pwd = malloc((my_strlen(ini->vpath.path_cd) + 1)
			     * sizeof(char))) == NULL)
	exit(1);
      ini->vpwd.pwd = my_strcpy(ini->vpwd.pwd, ini->vpath.path_cd);
    }
}
