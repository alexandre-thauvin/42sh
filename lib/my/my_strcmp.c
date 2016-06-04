/*
** my_strcmp.c for 42sh in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/lib/my
** 
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
** 
** Started on  Sat Jun  4 14:38:37 2016 thomas lavigne
** Last update Sat Jun  4 14:38:39 2016 thomas lavigne
*/

int	my_strcmp(char *s1, char *s2)
{
  int	z;

  z = 0;

  while (s1[z] != '\0' && s1[z] == s2[z] && s2[z] != '\0')
    z++;
  if (s1[z] == '\0' && s2[z] == '\0')
    return (1);
  return (0);
}
