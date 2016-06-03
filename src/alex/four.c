/*
** four.c for  in /home/thauvi_a/rendu/PSU_2015_42sh/src/alex
**
** Made by
** Login   <thauvi_a@epitech.net>
**
** Started on  Thu Jun  2 11:08:49 2016
** Last update Sat Jun  4 00:14:14 2016 thomas lavigne
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "shell.h"

int     malloc_buff(char *file_name)
{
  int   fd;
  char  *c;
  int   ret;
  int	nb;

  fd = open(file_name, O_RDWR);
  ret = nb = 0;
  while ((c = get_next_line(fd)) != NULL)
    {
      nb++;
      ret += my_strlen(c);
      free(c);
    }
  ret += nb;
  ret++;
  close(fd);
  return (ret);
}


void	all_exec(t_second *ini, char **env)
{
  int	fd;
  int   fd2;
  char  *buffer;

  if (ini->check.nb_redirection == -2)
    {
      tab_with_redirection(ini, ini->comm.arg2);
      if ((ini->comm.file_name2 = malloc((my_strlen(ini->comm.arg[4]) + 1)
					 * sizeof(char))) == NULL)
	exit(1);
      ini->comm.file_name2 = my_strcpy(ini->comm.file_name2, ini->comm.arg[4]);
      if ((buffer = malloc((malloc_buff(ini->comm.file_name))
			   * sizeof(char))) == NULL)
  	exit(1);
      fd = open(ini->comm.file_name, O_RDWR);
      read(fd, buffer, malloc_buff(ini->comm.file_name));
      close(fd);
      fd2 = open(ini->comm.file_name2, O_RDWR | O_CREAT, 0666);
      write(fd2, buffer, malloc_buff(ini->comm.file_name));
      close(fd2);
      return ;
    }
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
  redir_verif(commande, ini);
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
      fd = open(ini->comm.file_name, O_RDWR | O_CREAT, 0666);
    }
  if (ini->check.nb_redirection == 2)
    {
      tab_with_redirection(ini, ini->comm.arg2);
      fd = open(ini->comm.file_name, O_RDWR | O_APPEND | O_CREAT, 0666);
      }
  dup2(fd, 1);
  execve(ini->comm.arg[0], ini->comm.arg2, env);
}
