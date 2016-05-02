/*
** shell.h for  in /home/thauvi_a/rendu/shell/PSU_2015_minishell1/include
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Thu Jan 21 16:37:27 2016 Thauvin
** Last update Mon May  2 17:53:42 2016 Thauvin
*/

#ifndef SHELL_H_
# define SHELL_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include "../lib/my/my.h"
#include "get_next_line.h"

typedef struct		s_second
{
  pid_t			pid;
  pid_t			cpid;
  int			status;
  int			s;
  int			u;
  char			**PATH;
  char			**arg;
  char			**PATHfinal;
  int			rows_PATH;
  int			cols_PATH;
  int			rows_arg;
  char			*PATHok;
  int			check;
  int			check_ex;
  int			relative;
  char			*path_cd;
  int			z;
  int			zombie;
  char			*pathtemp;
  int			check2;
  int			courant;
  char			*pwd;
  char			*oldpwd;
  char			*dest;
  char			*commande;
  int			nb_separator;
  int			nb_redirection;
  char			**arg2;
  char			*file_name;
  int			j;
  int			nb_pipe;
}			t_second;

typedef struct	s_pipe
{
  char	*name;
  char	**arg;
  struct s_pipe	*next;
}		t_pipe;

typedef struct		s_var_malloc
{
  int	z;
  int	cols2;
  int	cols;
}			t_var_malloc;

typedef struct		s_tab
{
  int	z;
  char	**dest;
  int	a;
  int	c;
  int	lengh;
  int	cols;
  int	rows;
}			t_tab;

typedef struct		s_tab2
{
  int	rows;
  char	**dest;
  char	**dest2;
  int	z;
  int	c;
  int	a;
  int	w;
}			t_tab2;

typedef struct		s_tab3
{
  int	z;
  char	**dest;
  int	a;
  int	c;
  int	lengh;
  int	cols;
  int	rows;
  int	m;
}			t_tab3;

typedef struct		s_var_cd
{
  int	z;
  int	a;
  int	i;
  char	*dest;
}			t_var_cd;

typedef struct		s_env
{
  int	rows;
  int	cols;
  int	i;
  int	j;
  int	z;
  char	**temp;
  char	**env2;
}			t_env;

char	*pars_home(char **, char *);
char	*my_strcpy_norm(char *, char *);
int	check_exit(char **, int);
char	*check_cd(char **, char *, char **);
int	file_path_exist(char *);
char	**ma(char **, int, int, char **);
char	**my_strdup_path(char **, char *, char **);
int	my_strlenPATH(char *);
char	*cpy_path(char **);
int	getcols(char *);
int	getrows(char *);
char	**mallocdest(char **, int, int);
char	**my_strdup2d(char *);
int	lanceur(char *, t_env *, t_second *);
char	**my_strduptab(char *);
char	**ma2d(char **, int, char *);
int	getrows_tab(char *);
int	file_exist(t_second *, int);
void	ini_var_strdup(t_tab3 *, char *, char **);
void	end_string(t_tab2 *);
void	ini_var_strduptab(t_tab2 *, char *);
char	*cpy_tab_path(t_var_cd *, char **, char *);
void	exec_redirec(t_second *, char **, char **);
int	wait_in_fath(t_second *, char *, char **, char **);
void	get_rows_env(char **, t_env *);
void	get_cols_env(char **, t_env *);
int	strcmp_env(char **, char *);
void	my_setenv(t_env *, char **);
void	pars_builtenv(t_env *, char **, t_second *);
char	**strdup2d(char **, char **, char **, int);
char	*my_strcpy_update(char *, char **);
void	show_env(char **);
void	ini_var_tab(char **, t_env *, t_second *);
int	exec_cd(t_second *, char *, t_env *);
int	check_courant(t_second *);
void	complete_pwd(t_second *);
void	error(t_second *, char *, t_env *);
void	check_zomb(t_second *);
int	count_separator(char *);
char	*pars_commande(char *, t_second *);
void	count_pipe(char *, t_second *);
void	normal(t_second *, t_env *);
void	with_separator(t_second *, t_env *);
void	count_redirection(t_second *, char *);
int	tab_with_redirection(t_second *);
void	all_exec(t_second *, char **);
void	control_reach();
int	my_printf(const char*, ...);
void	pars_com_increm(t_second *, char *, int *, int);
void	ini_var_lanceur(t_second *, char *, t_env *);
                 /*parse_buff.c */
void	create_tab(char *, t_second *, t_env *);
int	count_pipes(char *);
int	my_strlen_space(char *, int);
		/* make_list.c */
void	pipe_toto(char **, t_second *, t_env *);
void	make_list(t_pipe **, char **, t_second *, t_env *);
int	my_tablen(char **);
int	my_put_in_list(struct s_pipe **, char *, t_second *, t_env *);
		/* pipe_exec.c */
void	pipe_exec2(int *, int p[2], t_pipe *, t_env *);
void	pipe_exec(t_pipe *, t_env *);

#endif /* SHELL_H_ */
