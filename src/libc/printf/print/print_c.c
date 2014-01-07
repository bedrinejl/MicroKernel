/*
** print_c.c for my_printf in /home/klarma_n//work/systeme_unix/my_printf/print
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Fri Nov 18 11:20:38 2011 nicolas klarman
** Last update Fri Nov 18 21:39:13 2011 nicolas klarman
*/

#include "stdlib.h"

int    print_c(va_list *ap)
{
  putchar(va_arg(*ap, int));
  return (1);
}
