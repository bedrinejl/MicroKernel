/*
** my_find_prime_sup.c for my_find_prime_sup in /home/klarma_n//progc/lib/my
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 24 10:56:34 2011 nicolas klarman
** Last update Tue Nov 15 14:41:24 2011 nicolas klarman
*/

#include "stdlib.h"

int	is_prime_sup(int n)
{
  if (is_prime(n))
    return n;
  if (!(n % 2))
    n++;
  while (!is_prime(n))
    n += 2;
  return n;
}
