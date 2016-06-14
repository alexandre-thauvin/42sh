/*
** get_next_line.h for  in /home/quasta_b/rendu/Projet C/Alum1/CPE_2015_Allum1/lib/my
** 
** Made by benjamin quastana
** Login   <quasta_b@epitech.net>
** 
** Started on  Fri Feb 26 10:13:28 2016 benjamin quastana
** Last update Thu Mar 10 10:45:08 2016 benjamin quastana
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# ifndef READ_SIZE
# define READ_SIZE (14)
# endif	/* !READ_SIZE */

char *get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
