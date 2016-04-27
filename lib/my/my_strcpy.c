/*
** my_strcpy.c for my_strcpy in /home/thauvi_a/test
**
** Made by alexandre thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Mon Oct  5 10:13:38 2015 alexandre thauvin
** Last update Wed Apr  6 15:43:11 2016 Thauvin
*/

#include "my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	z;

  z = 0;
  while (src[z] != '\0')
    {
      dest[z] = src[z];
      z = z + 1;
    }
  dest[z] = '\0';
  return (dest);
}
