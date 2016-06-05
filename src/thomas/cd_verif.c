/*
** cd_verif.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/src/thomas
**
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
**
** Started on  Thu Jun  2 19:28:39 2016 thomas lavigne
** Last update Sun Jun  5 12:44:17 2016 thomas lavigne
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "shell.h"

int	perm(mode_t const mode)
{
  if (mode & S_IROTH)
    return (0);
  else
    return (1);
  if (mode & S_IWOTH)
    return (1);
  else
    return (0);
  return (0);
}

int	cd_perm(char *str, t_second *ini)
{
  struct stat buf;

  ini->error.check2 = -1;
  if (stat(str, &buf) == -1)
    {
      fprintf(stderr, "%s: No such file or directory.\n", ini->comm.arg[1]);
      return (1);
    }
  if (perm(buf.st_mode) == 1)
    {
      fprintf(stderr, "%s: Permission denied.\n", str);
      return (1);
    }
  return (0);
}
