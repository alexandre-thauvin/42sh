/*
** four.c for  in /home/thauvi_a/rendu/shell/PSU_2015_minishell2/src
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Thu Apr 14 05:04:54 2016 Thauvin
** Last update Thu Apr 28 15:03:43 2016 Theo Labory
*/

#include "shell.h"

void	all_exec(t_second *ini, char **env)
{
  int	fd;

  if (ini->nb_redirection == -1)
    {
      tab_with_redirection(ini);
      fd = open(ini->file_name, O_RDWR | O_CREAT, 0777);
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
    execve(ini->PATHfinal[ini->check], ini->arg, env);
  free(ini->arg);
  if (ini->pathtemp != NULL)
    free(ini->PATHfinal);
}

void	control_reach()
{
  my_printf("\n\033[1m\033[34mshell\033[37m@\033[31m42sh\033[0m-->");
}
