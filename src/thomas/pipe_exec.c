/*
** pipe_exec.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/moulinette/pipe
**
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
**
** Started on  Fri Apr 29 15:18:13 2016 thomas lavigne
** Last update Mon May  2 18:58:27 2016 Thauvin
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
  execve(list->arg[0], list->arg, NULL);
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

/*void	pipe_exec(char ***cmd)
{
  int	p[2];
  pid_t	pid;
  int	fd = 0;
  int	i = 0;

  while (cmd && *cmd != NULL)
    {
      pipe(p);
      if ((pid = fork()) == -1)
	exit(EXIT_FAILURE);
      else if (pid == 0)
	{
	  dup2(fd, 0);
	  if (*(cmd + 1) != NULL)
	    dup2(p[1], 1);
	  close(p[0]);
	  execvp((*cmd)[0], *cmd);
	  exit(EXIT_FAILURE);
	}
      else
	{
	  wait(NULL);
	  close(p[1]);
	  fd = p[0];
	  cmd++;
	}
    }
}

void	main()
{
  char	*ls[] = {"ls", NULL};
  char	*grep[] = {"grep", "pipe", NULL};
  char	*wc[] = {"wc", NULL};
  char	*cat[] = {"cat", "-e", NULL};
  char	**cmd[] = {ls, grep, wc, cat, NULL};

  pipe_exec(cmd);
  return (0);
}*/
