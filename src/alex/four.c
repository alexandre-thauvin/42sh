/*
** four.c for  in /home/thauvi_a/rendu/PSU_2015_42sh/src/alex
**
** Made by
** Login   <thauvi_a@epitech.net>
**
** Started on  Thu Jun  2 11:08:49 2016
** Last update Thu Jun  2 17:31:44 2016 Theo Labory
*/

#include <stdio.h>
#include "shell.h"

void	all_exec(t_second *ini, char **env)
{
  int	fd;

  if (ini->check.nb_redirection == -1)
    {
      tab_with_redirection(ini, ini->arg2);
      fd = open(ini->file_name, O_RDWR | O_CREAT, 0555);
      dup2(fd, 0);
      execve(ini->arg[0], ini->arg2, env);
    }
  if (ini->error.check == -2)
    execve(ini->arg[0], ini->arg, env);
  if (ini->arg[0][0] == '.' && ini->arg[0][1] == '/')
    execve(ini->arg[0], ini->arg, env);
  if (ini->relative == 1)
    execve(ini->arg[0], ini->arg, env);
  if (ini->relative == 0)
      execve(ini->vpath.PATHfinal[ini->error.check], ini->arg, env);
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
  if (ini->error.zombie == 0 && ini->vpath.pathtemp != NULL)
      wait_in_fath(ini, commande, ini2->env2, ini->arg);
  if (ini->error.check2 != -1 && ini->vpath.pathtemp == NULL &&
      ini->error.zombie == 0)
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

  if (ini->check.nb_redirection == 1)
    {
      tab_with_redirection(ini, ini->arg2);
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
