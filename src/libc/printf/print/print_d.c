/*
** print_d.c for my_printf in /home/klarma_n//work/systeme_unix/my_printf/print
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Fri Nov 18 11:20:51 2011 nicolas klarman
** Last update Sat Nov 19 14:45:08 2011 nicolas klarman
*/

#include "stdlib.h"
#include "printf.h"

int	print_d(va_list *ap)
{
  return (put_nbr_base(va_arg(*ap, int), "0123456789"));
}
