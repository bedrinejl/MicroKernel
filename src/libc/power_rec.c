/*
** my_power_rec.c for my_power_rec in /home/klarma_n/
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Fri Oct  7 14:38:11 2011 nicolas klarman
** Last update Fri Oct  7 19:00:39 2011 nicolas klarman
*/

#include "stdlib.h"

int	power_rec(int nb, int power)
{
  int	n1;
  int	n2;

  if (nb < 0)
    return 0;
  if (power == 0)
    return 1;
  n2 = power_rec(nb, power - 1);
  n1 = nb * n2;
  if ((n1 / nb) != n2)
    {
      return 0;
    }
  else
    return n1;
}
