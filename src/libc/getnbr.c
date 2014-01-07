/*
** my_getnbr.c for my_getnbr in /home/klarma_n//progc/Jour_04
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Tue Oct 11 09:34:27 2011 nicolas klarman
** Last update Sun Nov 20 14:00:49 2011 nicolas klarman
*/

#include "stdlib.h"

int	check(int a, int b, int c);

int	getnbr(char *str)
{
  int	reto;
  int	flag;
  int	nega;

  reto = 0;
  flag = 0;
  nega = 1;

  while (str[flag] != '\0' && (str[flag] == 43 || str[flag] == 45))
    {
      if (str[flag] == 45)
	nega = nega * -1;
      flag = flag + 1;
    }
  while (str[flag] != '\0' && str[flag] < 58 && str[flag] > 47)
    {
      if (check(reto, (reto * 10 + nega * (str[flag] - 48)), nega) == 1)
	reto = (reto * 10 + nega * (str[flag] - 48));
      else
	return  (0);
      flag = flag + 1;
    }
  return reto;
}

int	check(int a, int b, int c)
{
  if (c > 0)
    {
      if (a > b)
	return 0;
      return 1;
    }

  if (a < b)
    return (0);
  return (1);
}
