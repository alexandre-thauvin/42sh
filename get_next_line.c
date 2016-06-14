/*
** get_next_line.c for get_next in /home/quasta_b/rendu/Projet C/Alum1/CPE_2015_Allum1/lib/my
** 
** Made by benjamin quastana
** Login   <quasta_b@epitech.net>
** 
** Started on  Fri Feb 26 10:12:51 2016 benjamin quastana
** Last update Tue Jun 14 09:13:17 2016 Benjamin Quastana
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char	my_get_char(const int fd)
{
  static char	buf[READ_SIZE];
  static char	*str;
  static int	a = 0;
  char	c;

  if (a == 0)
    {
      a = read(fd, buf, READ_SIZE);
      str = (char*)&buf;
      if (a == 0)
	return (0);
    }
  c = *str;
  str++;
  a--;
  return (c);
}

char	*my_realloc(char *str, size_t size)
{
  int	a;
  char	*str1;

  str1 = str;
  str = malloc(size);
  a = 0;
  while (str1[a])
    str[a] = str1[a++];
  str[a] = 0;
  free(str1);
  return (str);
}

char *get_next_line(const int fd)
{
  char	c;
  char	*str;
  int	a;

  str = malloc(READ_SIZE + 1);
  if (str == NULL)
    return (0);
  a = 0;
  c = my_get_char(fd);
  while (c != '\n' && c != '\0')
    {
      str[a] = c;
      c = my_get_char(fd);
      a++;
      if (a % (READ_SIZE + 1) == 0)
	str = realloc(str, a + READ_SIZE + 1);
    }
  str[a] = 0;
  if (c == 0 && str[0] == 0)
    return (0);
  return (str);
}

int	main(int ac, char **av)
{
  int	fd;

  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (-1);
  printf("%s\n", get_next_line(fd));
}
