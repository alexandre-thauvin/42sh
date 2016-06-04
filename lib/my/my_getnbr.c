/*
** my_getnbr.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/lib/my
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Sat Jun  4 14:38:08 2016 thomas lavigne
** Last update Sat Jun  4 14:38:08 2016 thomas lavigne
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	z;
  int	type;
  int	res;

  z = 0;
  type = 1;
  res = 0;
  if (str[0] == '-')
    {
      z = z + 1;
      type = 0;
    }
  while (str[z] != '\0')
    {
      str[z] = str[z] - '0';
      res = res + str[z];
      if (str[z + 1] != '\0')
	res = res * 10;
      z = z + 1;
    }
  if (type == 0)
    res = res * -1;
  return (res);
}
