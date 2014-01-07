/*
** my_putstr_o.c for my_putstr.c in /home/klarma_n//progc/Jour_04/ex_02
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Thu Oct  6 09:02:52 2011 nicolas klarman
** Last update Sat Nov 19 11:18:25 2011 nicolas klarman
*/

#include "stdlib.h"
#include "printf.h"

int	putstr_o(char *str)
{
  int	i;

  i = 0;
  while ((str[i]) != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  putchar('\\');
	  if (str[i] < 8)
	    putstr("00");
	  else if (str[i] < 64)
	    putchar('0');
	  put_nbr_base(str[i], "01234567");
	}
      else
	putchar(str[i]);
      i = i + 1;
    }
  return (i);
}
