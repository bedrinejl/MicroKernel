/*
** my_square_root.c for my_square_root in /home/klarma_n//progc/lib/my
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 24 10:55:13 2011 nicolas klarman
** Last update Tue Nov 15 14:43:46 2011 nicolas klarman
*/

#include "stdlib.h"

int	square_root(int n)
{
  int	i;
  int	root;

  if (n < 1)
    return 0;
  if (n == 1)
    return 1;
  i = 2;
  root = 1;
  while (n > (i * i))
    {
      if (!(n % (i * i)))
	{
	  root = root * i;
	  n = n / (i * i);
	  if (n == 1)
	    return root;
	}
      i++;
    }
  return 0;
}
