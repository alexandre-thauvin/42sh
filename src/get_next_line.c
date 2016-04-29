/*
** get_next_line.c for get_next_line in /home/labory_t/Epitech/projet/CPE/CPE_2015_getnextline
**
** Made by Theo Labory
** Login   <labory_t@epitech.net>
**
** Started on  Wed Jan  6 21:14:49 2016 Theo Labory
** Last update Fri Apr 29 01:27:18 2016 Thauvin
*/

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char my_get_just_one_char(const int fd)
{
  static int	length = 0;
  static char	*buffstr;
  static char	buffer[READ_SIZE];
  char		c;

  if (length == 0)
    {
      length = read(fd, buffer, READ_SIZE);
      buffstr = (char *)&buffer;
      if(length == 0)
	return (0);
    }
  c = *buffstr;
  buffstr++;
  length--;
  return (c);
}

char *realloc_please(size_t size, char *str)
{
  char *tmp;
  int i;

  i = 0;
  tmp = str;
  str = malloc(size);
  while(tmp[i])
    {
      str[i] = tmp[i];
      i++;
    }
  str[size] = '\0';
  return (str);
}

char *get_next_line(const int fd)
{
  Getnext base;

  base.len = 0;
  base.str = malloc(READ_SIZE + 1);
  if (base.str == NULL)
    return (NULL);
  base.c = my_get_just_one_char(fd);
  while (base.c != '\0' && base.c != '\n')
    {
      base.str[base.len] = base.c;
      base.c = my_get_just_one_char(fd);
      base.len++;
      if (base.len % (READ_SIZE) == 0)
	base.str = realloc_please(base.len + READ_SIZE + 1, base.str);
    }
  base.str[base.len] = '\0';
  if (base.c == 0 && base.str[0] == 0)
    return (NULL);
  return (base.str);
}
