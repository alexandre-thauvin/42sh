/*
** key.c for 42sh_bonus in /home/lavign_t/rendu/C/PSU/42sh/PSU_2015_42sh/src/thomas
**
** Made by thomas lavigne
** Login   <lavign_t@epitech.net>
**
** Started on  Wed May  4 14:57:01 2016 thomas lavigne
** Last update Fri May  6 09:45:10 2016 thomas lavigne
*/

#include <ncurses/curses.h>
#include <stdio.h>

void	init_all()
{
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, true);
  erase();
}

int	main()
{
  int	c;
  char	buf[4000];

  init_all();
  nodelay(stdscr, true);
  while (42)
    {
      c = getch();
      if (c == KEY_UP)
	printf("KEY_UP\n");
      else if (c == KEY_DOWN)
	printf("KEY_DOWN\n");
      else if (c == 27)
	{
	  clrtoeol();
	  refresh();
	  endwin();
	  return (0);
	}
      else
	{
	  read(0, buf, 4000);
	  printf("READ OK\n");
	}
    }
  clrtoeol();
  refresh();
  endwin();
  return (0);
}
