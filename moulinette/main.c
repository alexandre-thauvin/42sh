/*
** main.c for unit_test in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/Unit_test
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Thu Apr 28 09:23:46 2016 thomas lavigne
** Last update Thu Apr 28 09:34:08 2016 thomas lavigne
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    my_putchar(str[i++]);
}

void	my_putstr_usage(char *str)
{
  my_putstr("Usage : ");
  my_putstr(str);
  my_putstr("\n");
}

int	main_test(int ac, char **av, char **env)
{
  char	*buf;

  if ((buf = malloc(256)) == NULL)
    return (1);
  my_putstr("$> ");
  while (read(0, buf, 256))
    {
							/* TEST HERE */
      free(buf);
      if ((buf = malloc(256)) == NULL)
	return (1);
      my_putstr("$> ");
    }
  return (0);
}

int	main(int ac, char **av, char **env)
{
  if (ac != 1)
    {
      my_putstr_usage(av[0]);
      return (1);
    }
  if (main_test(ac, av, env) == 1)
    return (1);
  return (0);
}
