/*
** get_next_line.c for  in /home/thauvi_a/librairie/get_next_line_2
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Wed Mar  2 17:17:21 2016 Thauvin
** Last update Tue May  3 14:20:08 2016 thomas lavigne
*/

#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

char	*my_realloc(char *ptr, size_t size)
{
  char	*tmp;
  int	i;

  if (ptr == NULL)
    return (NULL);
  tmp = ptr;
  if ((ptr = malloc(size)) == NULL)
    return (NULL);
  i = 0;
  while (tmp && tmp[i] != '\0')
    {
      ptr[i] = tmp[i];
      i++;
    }
  free(tmp);
  return (ptr);
}

char	get_c(const int fd)
{
  static char buff[READ_SIZE];
  static char *ptr_buff;
  static int len = 0;
  char	c;

  if (len == 0)
    {
      len = read(fd, buff, READ_SIZE);
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
  if ((str = malloc(READ_SIZE + 1)) == NULL)
    exit(EXIT_FAILURE);
  if (str == NULL)
    return (0);
  c = get_c(fd);
  while (c != '\n' && c != '\0')
    {
      str[len] = c;
      c = get_c(fd);
      len++;
      if (len % (READ_SIZE + 1) == 0)
	str = my_realloc(str, len + READ_SIZE + 1);
    }
  str[len] = '\0';
  if (c == 0 && str[0] == 0)
    return (0);
  return (str);
}
