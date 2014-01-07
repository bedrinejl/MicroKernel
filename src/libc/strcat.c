/*
** my_strcat.c for my_strcat in /home/klarma_n//progc/Jour_07
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Tue Oct 11 11:26:35 2011 nicolas klarman
** Last update Sat Nov  5 18:37:32 2011 nicolas klarman
*/

#include "stdlib.h"

char	*strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    i = i + 1;
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  return dest;
}
