/*
** malloc2d.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/lib/my
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Sat Jun  4 14:37:44 2016 thomas lavigne
** Last update Sat Jun  4 14:37:44 2016 thomas lavigne
*/

#include <stdlib.h>

char	**malloc2d(char **dest, int rows, int cols)
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
