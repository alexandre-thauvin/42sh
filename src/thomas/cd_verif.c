/*
** cd_verif.c for  in /home/thauvi_a/rendu/PSU_2015_42sh/src/alex
**
** Made by Alexandre Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Sun Jun  5 14:26:24 2016 Alexandre Thauvin
** Last update Sun Jun  5 14:26:32 2016 Alexandre Thauvin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "shell.h"

int	perm(mode_t const mode)
{
  if (S_ISDIR(mode))
    {
      if (mode & S_IROTH)
	return (0);
      else
	return (1);
      if (mode & S_IWOTH)
	return (1);
      else
	return (0);
    }
  else
    return (1);
  return (0);
}

int	cd_perm(char *str, t_second *ini)
{
  struct stat buf;

  ini->error.check2 = -1;
  if (stat(str, &buf) == -1)
    {
      if (ini->comm.arg[1][0] == '~')
	fprintf(stderr, "%s: No such file or directory.\n", str);
      else
	fprintf(stderr, "%s: No such file or directory.\n", ini->comm.arg[1]);
      return (1);
    }
  if (perm(buf.st_mode) == 1)
    {
      if (S_ISDIR(buf.st_mode))
	fprintf(stderr, "%s: Permission denied.\n", ini->comm.arg[1]);
      else
	fprintf(stderr, "%s: Not a directory.\n", ini->comm.arg[1]);
      return (1);
    }
  return (0);
}
