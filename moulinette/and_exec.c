/*
** and_exec.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/src/thomas
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Wed May  4 13:27:10 2016 thomas lavigne
** Last update Wed May  4 13:55:43 2016 thomas lavigne
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
  char	**arg;
  struct s_list	*next;
}		t_list;

void	and_exec(t_list *command)
{
  pid_t	pid;
  int	status;

  while (command && access(command->arg[0], F_OK))
    {
      if ((pid = fork()) == -1)
	exit(EXIT_FAILURE);
      if (pid == 0)
	execve(command->arg[0], command->arg, NULL);
      else
	wait(&status);
    }
}

int	nb_arg(char *str, int i)
{
  int	size;

  size = 0;
  while (str[i] != '&' && str[i] != '\0')
    {
      size++;
      i++;
    }
  if (str[i - 1] == ' ')
    return (size - 1);
  else
    return (size);
}

int	size_arg(char *str, int i)
{
  int	size;

  size = 0;
  while (str[i] != ' ' && str[i] != '&' && str[i] != '\0')
    {
      i++;
      size++;
    }
  return (size);
}

void	parse_com(char *str, t_list *list)
{
  int	i;
  int	y;
  int	x;

  y = x = i = 0;
  while (str[i] != '\0')
    {
      if ((list->arg = malloc(sizeof(char *) * nb_arg(str, i))) == NULL)
	return ;
      while (str[i] != '&' && str[i] != '\0')
	{
	  if ((list->arg[y] = malloc(sizeof(char) * size_arg(str, i))) == NULL)
	    return ;
	  while (str[i] != ' ' && str[i] != '&' && str[i] != '\0')
	    list->arg[y][x++] = str[i++];
	  list->arg[y++][x] = 0;
	  x = 0;
	  while (str[i] == ' ')
	    i++;
	}
      while (str[i] == '&' || str[i] == ' ')
	i++;
      list->next = list;
      list = list->next;
      y = x = 0;
    }
}

int	main()
{
  char	*str;
  t_list	*list;

  list = NULL;
  str = "/bin/ls && /bin/wc";
  parse_com(str, list);
  and_exec(list);
}
