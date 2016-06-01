/*
** four.c for  in /home/thauvi_a/rendu/shell/PSU_2015_minishell2/src
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Thu Apr 14 05:04:54 2016 Thauvin
** Last update Wed Jun  1 15:50:01 2016 thomas lavigne
*/

#include <stdio.h>
#include "shell.h"

void	all_exec(t_second *ini, char **env)
{
  int	fd;

  if (ini->nb_redirection == -1)
    {
      tab_with_redirection(ini);
      fd = open(ini->file_name, O_RDWR | O_CREAT, 0555);
      dup2(fd, 0);
      execve(ini->arg[0], ini->arg2, env);
    }
  if (ini->check == -2)
    execve(ini->arg[0], ini->arg, env);
  if (ini->arg[0][0] == '.' && ini->arg[0][1] == '/')
    execve(ini->arg[0], ini->arg, env);
  if (ini->relative == 1)
    execve(ini->arg[0], ini->arg, env);
  if (ini->relative == 0)
      execve(ini->vpath.PATHfinal[ini->check], ini->arg, env);
  free(ini->arg);
  if (ini->vpath.pathtemp != NULL)
    free(ini->vpath.PATHfinal);
}

void	control_reach()
{
  write(1, "$>", 2);
}

void	lanceur_commande(char *commande, t_env *ini2, t_second *ini)
{
  if (ini->zombie == 0 && ini->vpath.pathtemp != NULL)
      wait_in_fath(ini, commande, ini2->env2, ini->arg);
  if (ini->check2 != -1 && ini->vpath.pathtemp == NULL && ini->zombie == 0)
    wait_in_fath(ini, commande, ini2->env2, ini->arg);
}

void	ini_and_builtin(char *commande, t_env *ini2, t_second *ini)
{
  ini_var_lanceur(ini, commande, ini2);
  pars_builtenv(ini2, ini->arg, ini);
  exec_cd(ini, commande, ini2);
}

void	right_redirec(t_second *ini, char **env)
{
  int	fd;

  if (ini->nb_redirection == 1)
    {
      tab_with_redirection(ini);
      fd = open(ini->file_name, O_RDWR | O_CREAT, 0777);
    }
  else
    {
      /* refaire le tab redirection avec la double */
      fd = open(ini->file_name, O_RDWR | O_CREAT | O_APPEND, 0666);
    }
  dup2(fd, 1);
  execve(ini->arg[0], ini->arg2, env);
}
