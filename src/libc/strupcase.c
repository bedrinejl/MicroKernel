/*
** my_strupcase.c for my_strupcase in /home/klarma_n//progc/Jour_06
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 10 16:41:37 2011 nicolas klarman
** Last update Mon Oct 10 19:31:02 2011 nicolas klarman
*/

#include "stdlib.h"

char	*strupcase(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 96 && str[i] < 123)
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return str;
}
