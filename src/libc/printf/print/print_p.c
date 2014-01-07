/*
** print_p.c for my_printf in /home/klarma_n//work/systeme_unix/my_printf/print
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Fri Nov 18 11:21:55 2011 nicolas klarman
** Last update Sun Nov 20 15:32:02 2011 nicolas klarman
*/

#include "stdlib.h"
#include "printf.h"

int    print_p(va_list *ap)
{
  putstr("0x");
  return (put_nbr_base_u(va_arg(*ap, unsigned int),
			    "0123456789abcdef") + 2);
}
