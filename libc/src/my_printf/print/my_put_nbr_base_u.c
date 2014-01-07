/*
** my_putnbr_base_u.c for my_printf in /home/klarma_n//Downloads/my_printf/my
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Fri Nov 18 21:11:01 2011 nicolas klarman
** Last update Fri Nov 18 22:09:26 2011 nicolas klarman
*/

#include <unistd.h>
#include <stdarg.h>
#include "../includes/my.h"
#include "../includes/my_printf.h"

int		my_put_nbr_base_u(unsigned int n, char *base)
{
  unsigned int	begin;
  unsigned int	end;
  unsigned int	len;
  int		octet;

  octet = 0;
  len = my_strlen(base);
  end = n % len;
  begin = (n - end) / len;
  if (begin != 0)
    octet = octet + my_put_nbr_base_u(begin, base);
  my_putchar(base[end]);
  octet++;
  return (octet);
}
