/*
** my_strlen.c for my_strlen in /home/thauvi_a/rendu/Piscine_C_J04
**
** Made by alexandre thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Thu Oct  1 22:01:38 2015 alexandre thauvin
** Last update Wed Apr  6 15:48:59 2016 Thauvin
** Last update Thu Nov 12 17:29:07 2015 Thauvin Alexandre
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
