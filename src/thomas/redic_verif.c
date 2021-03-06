/*
** redic_verif.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/save 42sh/PSU_2015_42sh/src/thomas
**
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
**
** Started on  Thu Jun  2 16:11:26 2016 thomas lavigne
** Last update Sat Jun  4 09:56:22 2016 thomas lavigne
*/

#include <stdio.h>
#include "shell.h"

int	last_check(int *save, t_second *ini)
{
  if (save[0] > 1 || save[1] > 1)
    {
      ini->error.doublons = -1;
      return (1);
    }
  if (save[2] > 0 && (save[0] > 0 || save[1] > 0))
    {
      ini->error.doublons = -1;
      return (1);
    }
  if (save[3] > 0)
    {
      ini->error.doublons = -1;
      return (1);
    }
  return (0);
}

void	redir_verif2(char *str, int *save, int *i)
{
  if (str[*i] == '>' && str[*i + 1] == '>')
    {
      save[2]++;
      *i = *i + 1;
    }
  if (str[*i] == '<' && str[*i + 1] == '<')
    {
      save[3]++;
      *i = *i + 1;
    }
}

int	check_error_redir2(char *str, int i, int *pos)
{
  if (str[i] == '>' && str[i + 1] != '>')
    {
      if (*pos == 2)
	{
	  fprintf(stderr, "Ambiguous output redirect.\n");
	  return (1);
	}
      else
	*pos = *pos + 1;
    }
  return (0);
}

void	check_error_redir(char *str)
{
  int	i;
  int	pos;

  i = 0;
  pos = 1;
  while (str && str[i] != 0)
    {
      if (str[i] == '<')
	{
	  if (pos == 2)
	    {
	      fprintf(stderr, "Ambiguous input redirect.\n");
	      return ;
	    }
	  else pos++;
	}
      if (check_error_redir2(str, i, &pos) == 1) return ;
     i++;
    }
}

int	redir_verif(char *str, t_second *ini)
{
  int	i;
  int	save[4];

  i = save[0] = save[1] = save[2] = save[3] = 0;
  ini->error.doublons = 0;
  while (str && str[i] != 0)
    {
      if (str[i] == '>' && str[i + 1] != '>')
      	save[0]++;
      if (str[i] == '<' && str[i + 1] != '<')
	save[1]++;
      redir_verif2(str, save, &i);
      i++;
    }
  if (last_check(save, ini) == 1)
    check_error_redir(str);
  else
    return (0);
  return (0);
}
