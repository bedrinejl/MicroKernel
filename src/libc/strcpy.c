/*
** my_strcpy.c for my_strcpy.c in /home/klarma_n//progc/Jour_06
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 10 10:30:05 2011 nicolas klarman
** Last update Tue Oct 11 13:42:51 2011 nicolas klarman
*/

#include "stdlib.h"

char	*strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return dest;
}
