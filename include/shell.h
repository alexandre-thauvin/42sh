/*
** shell.h for  in /home/thauvi_a/rendu/PSU_2015_42sh
**
** Made by Alexandre Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Sun Jun  5 14:26:48 2016 Alexandre Thauvin
** Last update Sun Jun  5 18:13:56 2016 Theo Labory
*/

#ifndef SHELL_H_
# define SHELL_H_

# include <sys/wait.h>
# include "../lib/my/my.h"

typedef struct		s_path
{
  char                  **PATH;
  char                  **PATHfinal;
  char			*path_cd;
  char			*pathtemp;
}			t_path;

typedef struct		s_pwd
{
  char			*pwd;
  char			*oldpwd;
  char			*dest;
}			t_pwd;

typedef struct		s_error
{
  int			check;
  int			check2;
  int			check_ex;
  int			status;
  int			zombie;
  int			doublons;
}			t_error;

typedef struct		s_check
{
  int			nb_separator;
  int			nb_redirection;
  int			nb_pipe;
  int			nb_and;
  int			nb_or;
  int			type;
}			t_check;

typedef struct		s_comm
{
  char			*file_name2;
  char			*file_name;
  char			*commande;
  char			**arg;
  char			**arg2;
}			t_comm;

typedef struct		s_pipe
{
  char			*name;
  char			**arg;
  int			fd;
  int			redir;
  struct s_pipe		*next;
}			t_pipe;

typedef struct		s_second
{
  struct s_path		vpath;
  struct s_pwd		vpwd;
  struct s_error	error;
  struct s_check	check;
  struct s_comm		comm;
  struct s_pipe		pip;
  pid_t			pid;
  pid_t			cpid;
  int			s;
  int			u;
  int			rows_arg;
  int			relative;
}			t_second;

typedef struct		s_benji
{
  int			a;
  int			x;
  int			y;
  char			**tab;
  int			i;
}			t_benji;

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

/*
** cd_ok.c
*/
char	*pars_home(char **, char *);
char	*my_strcpy_norm(char *, char *);
char	*check_cd(char **, char *, char **);
char	*cpy_tab_path(t_var_cd *, char **, char *);
void	ini_var_cd(t_var_cd *);

/*
** check_path.c
*/
int	check_exit(char **, int);
int	file_path_exist(char *);
char	**ma(char **, int, int, char **);
char	**my_strdup_path(char **, char *, char **);
void	ini_var_strdup(t_tab3 *, char *, char **);

/*
** first.c
*/
int	my_strlenPATH(char *);
int	lanceur(char *, t_env *, t_second *);
int	file_exist(t_second *);
char	*cpy_path(char **);
void	ini_var_lanceur(t_second *, char *, t_env *);

/*
** tab_path.c
*/
int	getcols(char *);
int	getrows(char *);
char	**mallocdest(char **, int, int);
char	**my_strdup2d(char *);

/*
** tab_arg.c
*/
char	**my_strduptab(char *);
char	**ma2d(char **, int, char *);
int	getrows_tab(char *);
void	end_string(t_tab2 *);
void	ini_var_strduptab(t_tab2 *, char *);

/*
** main.c
*/
void	exec_redirec(t_second *, char **, char **);
int	wait_in_fath(t_second *, char *, char **, char **);
int	exec_cd(t_second *, char *, t_env *);
void	ini_var_tab(char **, t_env *, t_second *);

/*
** wait_in_path.c
*/
void	wait_in_fath_norm(t_second *);

/*
** env3.c
*/
void	my_setenv_norm(char **, int, t_env *);

/*
** env2.c
*/
void	get_rows_env(char **, t_env *);
void	get_cols_env(char **, t_env *);
int	strcmp_env(char **, char *);
char	**strdup2d(char **, char **, char **, int);
char	*my_strcpy_update(char *, char **);

/*
** env.c
*/
void	my_setenv(t_env *, char **, t_second *);
void	pars_builtenv(t_env *, char **, t_second *);
void	my_unenv(t_env *, char **);
void	strdup2d_env(t_env *, int);
void	show_env(char **);

/*
** third.c
*/
int	check_courant(t_second *);
void	complete_pwd(t_second *);
void	error(t_second *, char *, t_env *);
void	check_zomb(t_second *);
void	exec_cd_tiret(t_second *);

/*
** separator.c
*/
int	count_separator(char *);
int	normal(t_second *, t_env *, char *);
char	*pars_commande(char *, t_second *);
void	count_pipe(char *, t_second *);
void	with_separator(t_second *, t_env *);

/*
** redirection.c
*/
char	**tab_with_redirection(t_second *, char **);
int	check_arg_redirec(t_second *, int);
void	count_redirection(t_second *, char *);

/*
** four.c
*/
int	malloc_buff(char *);
void	all_exec(t_second *, char **);
void	lanceur_commande(char *, t_env *, t_second *);
void	ini_and_builtin(char *, t_env *, t_second *);
void	right_redirec(t_second *, char **);

/*
** four2.c
*/
void	all_exec2(t_second *, int , char **);
void	control_reach();

/*
** separator_next.c
*/
void	count_and(char *, t_second *);
void	normal2(t_second *, char *, t_env *, char *);

/*
** five.c
*/
void	compar_ma2d(t_var_malloc *, char *);
void	free_tab(char **);
char	*cd_tild(char **, char *, char **);

/*
** lib/my/my_printf.c
*/
int	my_printf(const char*, ...);

/*
**parse_buff.c
*/
void	create_tab(char *, t_second *, t_env *);
int	count_pipes(char *);
int	my_strlen_space(char *, int);

/*
** make_list.c
*/
void	pipe_toto(char **, t_second *, t_env *);
int	make_list(t_pipe **, char **, t_second *, t_env *);
int	my_tablen(char **);
int	my_put_in_list(struct s_pipe **, char *, t_second *, t_env *);
int	check_builtin(char *, t_second *);
char	*catch_name(char *);

/*
** pipe_exec.c
*/
void	pipe_exec2(int p[2], t_pipe *, t_env *, t_second *);
void	pipe_exec(t_pipe *, t_env *, t_second *);

/*
** alpha_num.c
*/
int	alpha_num(char **, t_second *);

/*
** double.c
*/
char	*double_pipe(char *, int *);

/*
**my_free.c
*/
void	my_free(t_pipe *);

/*
** exec_next.c
*/
int	my_put_in_next(char *, t_second *, t_pipe *);

/*
** verif_cd.c
*/
int	cd_perm(char *, t_second *);

/*
** double2.c
*/
void	get_type(char *, int *, int);
void	double2(char *, int *, char *, int *);

/*
**double.c
*/
int	my_strcmp_toto(char *, char *);
int	size_com(char *, int *);
char	*get_command(char *, int *);
char	*double_pipe(char *, int *);

/*
** redic_verif.c
*/
int	redir_verif(char *, t_second *);
int	last_check(int *, t_second *);
void	check_error_redir(char *);
void	redir_verif2(char *, int *, int *);

/*
** no_more_zomb.c
*/
int	no_zomb(char *);

/*
** check_end.c
*/
int	check_end(t_second *);

#endif /* !SHELL_H_ */
