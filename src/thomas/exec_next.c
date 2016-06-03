/*
** exec_next.c for  in /home/quasta_b/rendu/Projets/PSU/PSU_2015_42sh/src/thomas
**
** Made by Benjamin Quastana
** Login   <quasta_b@epitech.net>
**
** Started on  Thu Jun  2 21:16:56 2016 Benjamin Quastana
** Last update Fri Jun  3 12:10:45 2016 Alexandre Thauvin
*/

#include <stdio.h>
#include "shell.h"

int	my_put_in_next(char *str, t_second *ini, t_pipe *elem)
{
  if (check_builtin(str, ini) == -1)
    if ((ini->error.check = file_exist(ini)) == -1)
      {
	fprintf(stderr, "%s: Command not found.\n", elem->arg[0]);
	ini->check.nb_and = 0;
	return (1);
      }
    else
      {
	if (ini->check.nb_redirection == 0)
	  elem->arg[0] = ini->vpath.PATHfinal[ini->error.check];
      }
  else
    elem->arg[0] = str;
  return (0);
}
