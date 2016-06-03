/*
** redic_verif.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/save 42sh/PSU_2015_42sh/src/thomas
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Thu Jun  2 16:11:26 2016 thomas lavigne
** Last update Fri Jun  3 10:28:55 2016 Benjamin Quastana
*/

#include "shell.h"

int	last_check(int *save, t_second *ini)
{
  if (save[0] > 1 || save[1] > 1)
    {
      ini->error.check2 = 1;
      return (1);
    }
  if (save[2] > 0 && (save[0] > 0 || save[1] > 0))
    {
      ini->error.check2 = 1;
      return (1);
    }
  if (save[3] > 0)
    {
      ini->error.check2 = 1;
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

int	check_error_redir(char *str)
{
  int	i;
  int	pos;

  pos = i = 0;
  while (str && str[i] != 0)
    {
      if (str[i] == '<')
	if (pos == 2)
	  {
	    printf("Ambiguous input redirect.\n");
	    return (0);
	  }
	else
	  pos++;
      if (str[i] == '>')
	if (pos == 2)
	  {
	    printf("Ambiguous output redirect.\n");
	    return (0);
	  }
	else
	  pos++;
      i++;
    }
  return (0);
}

int	redir_verif(char *str, t_second *ini)
{
  int	i;
  int	save[4];

  printf("%s\n", str);
  save[0] = save[1] = save[2] = save[3] = 0;
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
    {
      if (check_error_redir(str) == 0)
	return (1);
    }
  else
    return (0);
  return (0);
}
