/*
** make_list.c for 42sh_pipe in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/moulinette/pipe
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Fri Apr 29 09:56:06 2016 thomas lavigne
** Last update Fri Apr 29 15:13:36 2016 thomas lavigne
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_pipe
{
  char	*name;
  char	**arg;
  struct s_pipe	*next;
  struct s_pipe	*prev;
}		t_pipe;

void	show_list(t_pipe *list)
{
  t_pipe	*tmp;

  tmp = list;
  while (tmp && tmp != NULL)
    {
      printf("%s\n", tmp->name);
      tmp = tmp->next;
    }
}

int     my_put_in_list(struct s_pipe **list, char *str)
{
  struct s_pipe	*elem;
  struct s_pipe	*el;

  el = *list;
  if ((elem = malloc(sizeof(*elem))) == NULL)
    {
      printf("Error Malloc\n");
      exit(EXIT_FAILURE);
    }
  if (elem == NULL)
    return (1);
  elem->name = str;
  elem->next = *list;
  if (el != NULL)
    el->prev = elem;
  *list = elem;
  return (0);
}

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

void	make_list(t_pipe **list, char *tab_pipe[4])
{
  int	a;

  a = my_tablen(tab_pipe) - 1;
  while (a >= 0)
    if (my_put_in_list(list, tab_pipe[a--]) == 1)
      return ;
}

int	main()
{
  t_pipe	*list;
  char	*tab_pipe[4];

  tab_pipe[0] = "ls";
  tab_pipe[1] = "cat";
  tab_pipe[2] = "grep";
  tab_pipe[3] = NULL;
  make_list(&list, tab_pipe);
  show_list(list);
}

/* ls src/ | cat src/main.c | grep main
** tab[0] = dernier (grep main)
** tab[1] = cat src/main.c
** tab[2] = ls src/
*/
