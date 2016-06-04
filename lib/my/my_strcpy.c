/*
** my_strcpy.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/lib/my
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Sat Jun  4 14:38:52 2016 thomas lavigne
** Last update Sat Jun  4 14:38:53 2016 thomas lavigne
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
