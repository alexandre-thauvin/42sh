/*
** second.c for  in /home/thauvi_a/rendu/shell/PSU_2015_minishell2/src
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Tue Mar 29 16:58:09 2016 Thauvin
** Last update Tue May 31 15:07:44 2016 thomas lavigne
*/

#include <stdio.h>
#include "shell.h"

void	exec_redirec(t_second *ini, char **env, char **arg)
{
  if (ini->check == -1 && ini->relative == 0 && ini->s == 0 &&
      (my_strcmp("setenv", arg[0]) == 0) &&
      (my_strcmp("unsetenv", arg[0])) == 0 && (my_strcmp("env", arg[0]) == 0))
    {
      write(2, ini->arg[0], my_strlen(ini->arg[0]));
      write(2, ": Command not found.\n", my_strlen(": Command not found.\n"));
    }
  else
    {
      if ((my_strcmp("setenv", arg[0]) == 0) &&
	  (my_strcmp("unsetenv", arg[0])) == 0 && (my_strcmp("env", arg[0]) == 0))
	{
	  if (ini->nb_redirection != 0 && ini->nb_redirection != -1)
	    right_redirec(ini, env);
	  all_exec(ini, env);
	}
    }
}

int	exec_cd(t_second *ini, char *commande, t_env *ini2)
{
  if (ini->arg[0][0] == 'c' && ini->arg[0][1] == 'd')
    {
      ini->u = 0;
      if (ini->arg[1] != NULL)
	if (ini->arg[1][0] == '-')
	  ini->u = 1;
      ini->zombie = 1;
      ini->s = 1;
      ini->path_cd = check_cd(ini->arg, ini->path_cd, ini2->env2);
      if (ini->u == 1)
	ini->u = chdir(ini->oldpwd);
      else
	ini->u = chdir(ini->path_cd);
      if (ini->u == -1)
	if (ini->arg[1] != NULL)
	  {
	    ini->check2 = -1;
	    fprintf(stderr, "%s: No such file or directory.\n", ini->arg[1]);
	  }
      if (ini->u != 1)
	complete_pwd(ini);
    }
  if ((ini->check_ex = check_exit(ini->arg, ini->rows_arg)) != 0)
    exit(ini->check_ex);
  if (commande[0] == '/')
    check_zomb(ini);
  return (0);
}

void	ini_var_tab(char **env, t_env *ini2, t_second *ini)
{
  get_rows_env(env, ini2);
  get_cols_env(env, ini2);
  ini2->env2 = malloc2d(ini2->env2, ini2->rows, ini2->cols);
  ini2->env2 = strdup2d(ini2->env2, env, ini->arg, 0);
  ini2->z++;
}

int	wait_in_fath(t_second *ini, char *commande, char **env, char **arg)
{
  if (commande[0] != '/' && (commande[0] != '.' && commande[1] != '/'))
    if ((ini->check = file_exist(ini)) == -1)
      return (0);
  if (ini->pathtemp != NULL)
    free(ini->PATH);
  ini->pid = fork();
  if (ini->pid == -1)
    write(2, "erreur\n", my_strlen("erreur fork\n"));
  if (ini->pid == 0)
    exec_redirec(ini, env, arg);
  if (ini->pid != 0 && ini->pid != -1)
    {
      if (ini->check_ex != 0)
	exit(ini->check_ex);
      ini->cpid = waitpid(ini->pid, &ini->status, 0);
      if (ini->status == 11 || ini->status == 139 || ini->status == SIGSEGV)
	write(2, "Segmentation fault\n", 19);
      if (ini->cpid != ini->pid)
	kill(ini->cpid, SIGKILL);
      if (ini->cpid == -1)
	write(2, "wait error\n", my_strlen("wait error\n"));
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_env		ini2;
  t_second	ini;
  int		i;

  i = 0;
  av = av;
  ac = ac;
  ini.tty = isatty(0);
  if (env[0] == NULL)
    return (0);
  /* signal(SIGINT, control_reach); */
  ini_var_tab(env, &ini2, &ini);
  while (42)
    {
      if (ini.tty == 1)
	write(1, "$>", 2);
      ini.commande = get_next_line(0);
      if (ini.commande == NULL)
	{
	  if (i != 0 && (ini.check2 == -1 || ini.check == -1))
	    exit(1);
	  else
	    exit(0);
	}
      ini.nb_separator = count_separator(ini.commande);
      if (ini.nb_separator != 0)
	with_separator(&ini, &ini2);
      else
	normal(&ini, &ini2);
      i++;
    }
  return (0);
}
