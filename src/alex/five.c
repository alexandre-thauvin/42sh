/*
** five.c for  in /home/thauvi_a/rendu/42sh/PSU_2015_42sh/src/alex
**
** Made by Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Thu May  5 03:24:58 2016 Thauvin
** Last update Thu May  5 03:32:25 2016 Thauvin
*/

#include "shell.h"

void	compar_ma2d(t_var_malloc *ini, char *commande)
{
  if (commande[ini->z] != '\0')
    ini->z++;
  if (ini->cols > ini->cols2)
    ini->cols2 = ini->cols;
}
