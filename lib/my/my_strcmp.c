/*
** my_strcmp.c for  in /home/thauvi_a/lib
**
** Made by alexandre thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Tue Oct  6 11:19:55 2015 alexandre thauvin
** Last update Tue May 31 19:47:44 2016 Thauvin
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
