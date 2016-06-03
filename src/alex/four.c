/*
** four.c for  in /home/thauvi_a/rendu/PSU_2015_42sh/src/alex
**
** Made by
** Login   <thauvi_a@epitech.net>
**
** Started on  Thu Jun  2 11:08:49 2016
** Last update Fri Jun  3 00:50:39 2016 Alexandre Thauvin
*/

#include <stdio.h>
#include "shell.h"

int     malloc_buff(char *file_name)
{
  int   fd;
  char  *c;
  int   ret;

  fd = open(file_name, O_RDWR);
  while ((c = get_next_line(fd)) != NULL)
    {
      ret += my_strlen(c);
	   free(c);
    }
  ret++;
  close(fd);
  return (ret);
}


void	all_exec(t_second *ini, char **env)
{
  int	fd;
  /* int   fd2; */
  /* char  *buffer; */

  /* if (ini->check.nb_redirection == -2) */
  /*   { */
  /*     fd = open(ini->comm.file_name, O_RDWR); */
  /*     if ((buffer = malloc(malloc_buff(ini->comm.file_name))) == NULL) */
  /* 	exit(1); */
  /*    read(fd, buffer, malloc_buff(ini->comm.file_name)); */
  /*     fd2 = open(ini->comm.file_name2, O_RDWR | O_CREAT, 0555); */
  /*     write(fd2, buffer, malloc_buff(ini->comm.file_name)); */
  /*     close(fd); */
  /*     close(fd2); */
  /*   } */
  if (ini->check.nb_redirection == -1)
    {
      tab_with_redirection(ini, ini->comm.arg2);
      fd = open(ini->comm.file_name, O_RDWR | O_CREAT, 0555);
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
  write(1, "$>", 2);
}

void	lanceur_commande(char *commande, t_env *ini2, t_second *ini)
{
  if (ini->error.zombie == 0 && ini->vpath.pathtemp != NULL)
      wait_in_fath(ini, commande, ini2->env2, ini->comm.arg);
  if (ini->error.check2 != -1 && ini->vpath.pathtemp == NULL &&
      ini->error.zombie == 0)
    wait_in_fath(ini, commande, ini2->env2, ini->comm.arg);
}

void	ini_and_builtin(char *commande, t_env *ini2, t_second *ini)
{
  ini_var_lanceur(ini, commande, ini2);
  pars_builtenv(ini2, ini->comm.arg, ini);
  exec_cd(ini, commande, ini2);
}

void	right_redirec(t_second *ini, char **env)
{
  int	fd;

  if (ini->check.nb_redirection == 1)
    {
      tab_with_redirection(ini, ini->comm.arg2);
      fd = open(ini->comm.file_name, O_RDWR | O_CREAT, 0777);
    }
  else
    {
      /* refaire le tab redirection avec la double */
      fd = open(ini->comm.file_name, O_RDWR | O_CREAT | O_APPEND, 0666);
    }
  dup2(fd, 1);
  execve(ini->comm.arg[0], ini->comm.arg2, env);
}
