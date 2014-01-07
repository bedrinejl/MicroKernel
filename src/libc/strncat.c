/*
** my_strncat.c for my_strncat in /home/klarma_n//progc/Jour_07
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Tue Oct 11 13:24:24 2011 nicolas klarman
** Last update Tue Nov 15 14:43:56 2011 nicolas klarman
*/

#include "stdlib.h"

char	*strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    i = i + 1;
  while (src[j] != '\0' && nb != 0)
    {
      dest[i] = src[j];
      j = j + 1;
      i = i + 1;
      nb = nb - 1;
    }
  return dest;
}
