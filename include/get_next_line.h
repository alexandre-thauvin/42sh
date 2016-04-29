/*
** get_next_line.h for get_next_line in /home/labory_t/Epitech/projet/CPE/CPE_2015_getnextline
** 
** Made by Theo Labory
** Login   <labory_t@epitech.net>
** 
** Started on  Wed Jan  6 21:15:30 2016 Theo Labory
** Last update Thu Jan 21 15:26:33 2016 Theo Labory
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#include <stdlib.h>
#include <unistd.h>

# ifndef READ_SIZE
#  define READ_SIZE (14)
# endif /* !READ_SIZE */

typedef struct	getnext
{
  char		c;
  char		*str;
  int		len;
}Getnext;

char		*get_next_line(const int fd);
char		*realloc_please(size_t size, char *str);
char		my_get_just_one_char(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
