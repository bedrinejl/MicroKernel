/*
** my_putnbr_base.c for my_printf in /home/klarma_n//Downloads/my_printf/my
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Fri Nov 18 21:11:26 2011 nicolas klarman
** Last update Sat Nov 19 14:46:27 2011 nicolas klarman
*/

#include "stdlib.h"

int	put_nbr_base(int n, char *base)
{
  int	bigin;
  int	end;
  int	len;
  int	octet;

  if (n == -2147483648) {
    putstr("-2147483648");
    return 0;
  }
  octet = 0;
  len = strlen(base);
  if (n < 0)
    {
      putchar('-');
      octet++;
      put_nbr_base(-n, base);
    }
  else
    {
      end = n % len;
      bigin = (n - end) / len;
      if (bigin != 0)
	octet = octet + put_nbr_base(bigin, base);
      putchar(base[end]);
      octet++;
    }
  return (octet);
}
