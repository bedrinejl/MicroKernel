/*
** print_b.c for my_printf in /home/klarma_n//work/systeme_unix/my_printf/print
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Sat Nov 19 10:04:23 2011 nicolas klarman
** Last update Sun Nov 20 15:29:03 2011 nicolas klarman
*/

#include "stdlib.h"
#include "printf.h"

int	print_b(va_list *ap)
{
  return (put_nbr_base_u(va_arg(*ap, unsigned int), "01"));
}
