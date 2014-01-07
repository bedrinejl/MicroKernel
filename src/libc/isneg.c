/*
** my_isneg.c for my_isneg in /home/klarma_n//progc
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Wed Oct  5 11:00:01 2011 nicolas klarman
** Last update Wed Oct  5 18:24:22 2011 nicolas klarman
*/

#include "stdlib.h"

int	isneg(int n)
{
  if (n >= 0)
    {
      putchar('P');
    }
  else
    {
      putchar('N');
    }
  return 0;
}
