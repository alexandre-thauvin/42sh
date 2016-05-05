/*
** pipe_exec.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/moulinette/pipe
**
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
**
** Started on  Fri Apr 29 15:18:13 2016 thomas lavigne
** Last update Thu May  5 20:47:48 2016 thomas lavigne
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

void	pipe_exec2(int *fd, int p[2], t_pipe *list, t_env *ini2)
{
  dup2(*fd, 0);
  if (list->next != NULL)
    dup2(p[1], 1);
  close(p[0]);
  ini2->env2[0] = NULL;
  if (check_builtin(catch_name(list->arg[0])) == -1)
    execve(list->arg[0], list->arg, NULL);
  else
    /* exec builtin */
  exit(EXIT_FAILURE);
}

void	pipe_exec(t_pipe *list, t_env *ini2)
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
	pipe_exec2(&fd, p, list, ini2);
      else
	{
	  wait(NULL);
	  close(p[1]);
	  fd = p[0];
	  list = list->next;
	}
    }
}
