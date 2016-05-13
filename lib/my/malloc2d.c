/*
** malloc2d.c for  in /home/thauvi_a/librairie/lib/my
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Thu Mar  3 14:58:30 2016 Thauvin
** Last update Fri May 13 18:19:37 2016 Thauvin
*/

#include <stdlib.h>

char    **malloc2d(char **dest, int rows, int cols)
{
  int   z;

  z = 0;
  rows++;
  if ((dest = malloc((1 + rows) * sizeof(char*))) == NULL)
    exit(0);
  while (z < rows)
    {
      if ((dest[z] = malloc(cols * sizeof(char) + 1)) == NULL)
	exit(0);
      z++;
    }
  dest[z] = NULL;
  return (dest);
}
