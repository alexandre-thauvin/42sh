/*
** my_free.c for my_free in /home/labory_t/Rendu/PSU/PSU_2015_42sh/src/theo
** 
** Made by Theo Labory
** Login   <labory_t@epitech.net>
** 
** Started on  Wed Jun  1 13:21:34 2016 Theo Labory
** Last update Wed Jun  1 13:53:41 2016 Theo Labory
*/

#include "shell.h"

void		my_free(t_pipe *list)
{
  t_pipe	*tmp;

  tmp = list;
  while(tmp != NULL)
    {
      free(tmp);
      tmp = tmp->next;
    }
}
