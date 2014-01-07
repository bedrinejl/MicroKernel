/*
** print_s.c for my_printf in /home/klarma_n//work/systeme_unix/my_printf/print
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Fri Nov 18 11:20:26 2011 nicolas klarman
** Last update Fri Nov 18 21:39:52 2011 nicolas klarman
*/

#include "stdlib.h"
#include "printf.h"

int	print_s(va_list *ap)
{
  putstr(va_arg(*ap, char *));
  return 0;
}
