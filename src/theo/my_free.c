/*
** my_free.c for my_free in /home/labory_t/Rendu/PSU/PSU_2015_42sh/src/theo
** 
** Made by Theo Labory
** Login   <labory_t@epitech.net>
** 
** Started on  Wed Jun  1 13:21:34 2016 Theo Labory
** Last update Wed Jun  1 14:23:31 2016 thomas lavigne
*/

#include "shell.h"

void		free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

void		my_free(t_pipe *list)
{
  t_pipe	*tmp;
  t_pipe	*tmp2;

  tmp = list;
  while (tmp != NULL)
    {
      free_tab(tmp->arg);
      tmp2 = tmp->next;
      free(tmp);
      tmp = tmp2;
    }
}
