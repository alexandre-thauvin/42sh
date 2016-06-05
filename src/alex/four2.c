/*
** four2.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/src/alex
**
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
**
** Started on  Sat Jun  4 10:04:32 2016 thomas lavigne
** Last update Sun Jun  5 15:41:16 2016 Alexandre Thauvin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "get_next_line.h"

void	all_exec2(t_second *ini, int fd, char **env)
{
  ini->pip.redir = 0;
  if (ini->check.nb_redirection == -1)
    {
      tab_with_redirection(ini, ini->comm.arg2);
      if ((fd = open(ini->comm.file_name, O_RDWR)) == -1)
	{
	  fprintf(stderr, "%s: No such file or directory.\n",
		  ini->comm.file_name);
	  ini->pip.redir = -1;
	  return ;
	}
      dup2(fd, 0);
      execve(ini->comm.arg[0], ini->comm.arg2, env);
    }
  if (ini->error.check == -2)
    execve(ini->comm.arg[0], ini->comm.arg, env);
  if (ini->comm.arg[0][0] == '.' && ini->comm.arg[0][1] == '/')
    execve(ini->comm.arg[0], ini->comm.arg, env);
  if (ini->relative == 1)
    execve(ini->comm.arg[0], ini->comm.arg, env);
  if (ini->relative == 0)
    execve(ini->vpath.PATHfinal[ini->error.check], ini->comm.arg, env);
  free(ini->comm.arg);
  if (ini->vpath.pathtemp != NULL)
    free_tab(ini->vpath.PATHfinal);
}

void	control_reach()
{
  write(1, "\n$>", 3);
}
