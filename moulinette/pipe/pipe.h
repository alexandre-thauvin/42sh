/*
** pipe.h for pipe in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/moulinette/pipe
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Sat Apr 30 11:08:59 2016 thomas lavigne
** Last update Sat Apr 30 11:12:46 2016 thomas lavigne
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

#endif
