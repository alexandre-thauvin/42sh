/*
** my_getnbr.c for  in /home/thauvi_a/A mettre dans la lib
** 
** Made by alexandre thauvin
** Login   <thauvi_a@epitech.net>
** 
** Started on  Wed Oct 21 15:52:41 2015 alexandre thauvin
** Last update Sun Jan 24 04:59:39 2016 Thauvin
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
