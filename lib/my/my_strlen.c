/*
** my_strlen.c for lib in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/lib/my
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Sat Jun  4 14:37:29 2016 thomas lavigne
** Last update Sat Jun  4 14:37:30 2016 thomas lavigne
*/

#include <stdlib.h>
#include "my.h"

int	my_strlen(char *str)
{
  int	z;

  z = 0;
  if (str == NULL)
    return (0);
  while (str[z] != '\0')
    z++;
  return (z);
}
