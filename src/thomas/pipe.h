/*
** pipe.h for pipe in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/moulinette/pipe
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Sat Apr 30 11:08:59 2016 thomas lavigne
** Last update Mon May  2 16:10:55 2016 thomas lavigne
*/

#ifndef PIPE_H_
# define PIPE_H_

typedef struct  s_pipe
{
  char  *name;
  char  **arg;
  struct s_pipe *next;
}		t_pipe;

void    pipe_exec(t_pipe *list);
int	getrows_tab(char *src);
char	**ma2d(char **dest, int rows, char *commande);
char	**my_strduptab(char *src);
int	my_strlen(char *str);

#endif
