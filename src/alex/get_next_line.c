/*
** get_next_line.c for  in /home/thauvi_a/librairie/get_next_line_2
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Wed Mar  2 17:17:21 2016 Thauvin
** Last update Wed May 25 20:01:30 2016 Thauvin
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

char		get_c(const int fd)
{
  static char	buff[READ_SIZE];
  static char	*ptr_buff;
  static int	len = 0;
  char		c;

  if (len == 0)
    {
      if ((len = read(fd, buff, READ_SIZE)) == -1)
	exit(1);
      ptr_buff = (char*)&buff;
      if (len == 0)
	return (0);
    }
  c = *ptr_buff;
  ptr_buff++;
  len--;
  return (c);
}

char	*get_next_line(const int fd)
{
  char	c;
  char	*str;
  int	len;

  len = 0;
  if ((str = malloc(READ_SIZE + 2)) == NULL || !memset(str, 0, READ_SIZE + 2))
    exit(1);
  if (str == NULL)
    return (0);
  c = get_c(fd);
  while (c != '\n' && c != '\0')
    {
      str[len] = c;
      c = get_c(fd);
      len++;
      if (len % (READ_SIZE + 1) == 0)
	if ((str = realloc(str, len + READ_SIZE + 2)) == NULL)
	    exit(1);
    }
  str[len] = '\0';
  if (c == 0 && str[0] == 0)
    return (0);
  return (str);
}
