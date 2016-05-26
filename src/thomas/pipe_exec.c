/*
** pipe_exec.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/moulinette/pipe
**
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
**
** Started on  Fri Apr 29 15:18:13 2016 thomas lavigne
** Last update Thu May 26 15:41:27 2016 Thauvin
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

void	pipe_exec2(int *fd, int p[2], t_pipe *list, t_env *ini2, t_second *ini)
{
  dup2(*fd, 0);
  *fd = *fd;
  if (list->next != NULL)
    dup2(p[1], 1);
  close(p[0]);
  if (check_builtin(list->arg[0], ini) == -1)
    execve(list->arg[0], list->arg, NULL);
  else
      ini_and_builtin(list->arg[0], ini2, ini); /* ICI THAUVIN */
  exit(EXIT_FAILURE);
}

void	pipe_exec(t_pipe *list, t_env *ini2, t_second *ini)
{
  int	p[2];
  pid_t	pid;
  int	fd;
  int	i;

  fd = i = 0;
  while (list && list != NULL)
    {
      pipe(p);
      if ((pid = fork()) == -1)
	exit(EXIT_FAILURE);
      else if (pid == 0)
	pipe_exec2(&fd, p, list, ini2, ini);
      else
	{
	  wait(NULL);
	  close(p[1]);
	  fd = p[0];
	  list = list->next;
	}
    }
}
