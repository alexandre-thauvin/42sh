/*
** pipe_exec.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/moulinette/pipe
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Fri Apr 29 15:18:13 2016 thomas lavigne
** Last update Fri Apr 29 15:49:20 2016 thomas lavigne
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	pipe_exec(char ***cmd)
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

int	main()
{
  //  t_pipe	*list;
  char	*ls[] = {"ls", NULL};
  char	*grep[] = {"grep", "pipe", NULL};
  char	*wc[] = {"wc", NULL};
  char	*cat[] = {"cat", "-e", NULL};
  char	**cmd[] = {ls, grep, wc, cat, NULL};

  pipe_exec(cmd);
  return (0);
}
