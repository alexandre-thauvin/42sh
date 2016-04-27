/*
** malloc2d.c for  in /home/thauvi_a/librairie/lib/my
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Thu Mar  3 14:58:30 2016 Thauvin
** Last update Thu Apr 14 19:17:32 2016 Thauvin
*/

#include <stdlib.h>

char    **malloc2d(char **dest, int rows, int cols)
{
  int   z;

  z = 0;
  rows++;
  dest = malloc((1 + rows) * sizeof(char*));
  while (z < rows)
    {
      dest[z] = malloc(cols * sizeof(char) + 1);
      z++;
    }
  dest[z] = NULL;
  return (dest);
}
