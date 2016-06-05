/*
** check_end.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/src/alex
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Sun Jun  5 13:46:55 2016 thomas lavigne
** Last update Sun Jun  5 21:34:09 2016 thomas lavigne
*/

#include "shell.h"

int	check_end(t_second *ini)
{
  if (ini->error.check2 == -1 || ini->error.check == -1
      || ini->pip.redir == -1 || ini->error.status != 0)
    return (-1);
  return (0);
}
