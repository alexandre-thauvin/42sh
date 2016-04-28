/*
** third.c for  in /home/thauvi_a/rendu/shell/PSU_2015_minishell2/src
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Sun Apr 10 18:19:32 2016 Thauvin
** Last update Thu Apr 28 09:31:14 2016 Lalague-Dulac Tom
*/

#include "shell.h"

void	check_zomb(t_second *ini)
{
  ini->check2 = file_path_exist(ini->arg[0]);
  if (ini->check2 != -1)
    ini->relative = 1;
  else
    ini->zombie = 1;
}

void	error(t_second *ini, char *commande, t_env *ini2)
{
  if (ini->check != -1 && (commande[0] == '.' && commande[1] == '/'))
    wait_in_fath(ini, commande, ini2->env2, ini->arg);
  if (ini->check2 == -1 || ini->check == -1 ||
      (ini->pathtemp == NULL && ini->zombie == 0 && ini->check2 == -1))
    {
      write(2, ini->arg[0], my_strlen(ini->arg[0]));
      write(2, ": Command not found.\n", my_strlen(": Command not found.\n"));
    }
}

int	check_courant(t_second *ini)
{
  if ((access(ini->arg[0], F_OK)) == 0)
    return (0);
  else
    return (-1);
  return (-1);
}

void	complete_pwd(t_second *ini)
{
  if (ini->arg[1][0] == '-')
    {
      if ((ini->oldpwd = malloc((my_strlen(ini->pwd) + 2) * sizeof(char))) == NULL)
	return ;
      ini->oldpwd = my_strcpy(ini->oldpwd, ini->pwd);
      free(ini->pwd);
      if ((ini->pwd = malloc(1024 * sizeof(char))) == NULL)
	return ;
      getcwd(ini->pwd, 1024);
    }
  if (ini->arg[1][0] != '-')
    {
      if ((ini->oldpwd = malloc((my_strlen(ini->pwd) + 2) * sizeof(char))) == NULL)
	return ;
      ini->oldpwd = my_strcpy(ini->oldpwd, ini->pwd);
      free(ini->pwd);
      if ((ini->pwd = malloc((my_strlen(ini->path_cd) + 1) * sizeof(char))) == NULL)
	return ;
      ini->pwd = my_strcpy(ini->pwd, ini->path_cd);
    }
}
