/*
** wait_int_path2.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/src/alex
**
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
**
** Started on  Fri Jun  3 10:35:52 2016 thomas lavigne
** Last update Sun Jun  5 13:01:14 2016 thomas lavigne
*/

#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

void	wait_in_fath_norm(t_second *ini)
{
  if (ini->pid != 0 && ini->pid != -1)
    {
      if (ini->error.check_ex != 0)
	exit(ini->error.check_ex);
      ini->cpid = waitpid(ini->pid, &ini->error.status, 0);
      if (ini->error.status == 11 || ini->error.status == 139 ||
	  ini->error.status == SIGSEGV)
	write(2, "Segmentation fault\n", 19);
      if  (WEXITSTATUS(ini->error.status) != 0)
	{
	  ini->check.nb_or = 1;
	  ini->check.nb_and = 0;
	}
      if (ini->cpid != ini->pid)
	kill(ini->cpid, SIGKILL);
      if (ini->cpid == -1)
	write(2, "wait error\n", my_strlen("wait error\n"));
    }
}
