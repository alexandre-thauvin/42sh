/*
** pipe_exec.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/moulinette/pipe
**
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
**
** Started on  Fri Apr 29 15:18:13 2016 thomas lavigne
** Last update Fri Jun  3 22:21:13 2016 thomas lavigne
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "shell.h"

void	pipe_exec2(int p[2], t_pipe *list, t_env *ini2, t_second *ini)
{
  int	fd2;

  dup2(ini->pip.fd, 0);
  if (list->next != NULL)
    dup2(p[1], 1);
  close(p[0]);
  if (check_builtin(list->arg[0], ini) == -1)
    {
      if (ini->check.nb_redirection != 0)
	{
	  fd2 = open(ini->comm.file_name, O_RDWR);
	  dup2(fd2, 0);
	  execve(list->arg[0], list->arg, NULL);
	}
      else
	execve(list->arg[0], list->arg, NULL);
    }
  else
      ini_and_builtin(list->arg[0], ini2, ini);
  exit(EXIT_FAILURE);
}

void	pipe_exec(t_pipe *list, t_env *ini2, t_second *ini)
{
  int	p[2];
  pid_t	pid;
  int	i;
  t_pipe *save;

  ini->pip.fd = i = 0;
  save = list;
  while (list && list != NULL)
    {
      pipe(p);
      if ((pid = fork()) == -1)
	exit(EXIT_FAILURE);
      else if (pid == 0)
	pipe_exec2(p, list, ini2, ini);
      else
	{
	  wait(NULL);
	  close(p[1]);
	  ini->pip.fd = p[0];
	  list = list->next;
	}
    }
  my_free(save);
}
