/*
** no_more_zomb.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/src/thomas
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Sat Jun  4 09:33:12 2016 thomas lavigne
** Last update Sat Jun  4 11:00:13 2016 thomas lavigne
*/

#include "shell.h"

int	no_zomb(char *commande)
{
  int	i;

  i = 0;
  while (commande && (commande[i] == ' ' || commande[i] == '\t') &&
	 commande[i] != 0)
    i++;
  if (commande[i] == 0)
    return (0);
  if (commande[i] == '/' && commande[i + 1] == '/')
    return (1);
  if (commande[i] == '.' && commande[i + 1] == '.')
    return (1);
  return (0);
}
