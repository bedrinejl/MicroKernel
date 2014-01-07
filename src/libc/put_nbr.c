/*
** my_put_nbr.c for my_put_nbr.c in /home/klarma_n//progc
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Wed Oct  5 19:17:12 2011 nicolas klarman
** Last update Mon Oct 24 12:04:49 2011 nicolas klarman
*/

#include "stdlib.h"

int	put_nbr(int nb)
{
  if ((nb / 10) != 0)
    put_nbr(nb / 10);
  else if (nb < 0)
    {
      putchar(45);
    }
  if (nb < 0 )
    {
      putchar((nb * -1) % 10 + 48);
    }
  else
    {
      putchar(nb % 10 + 48);
    }
  return 0;
}
