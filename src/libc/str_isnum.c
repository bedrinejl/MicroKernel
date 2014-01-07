/*
** my_str_isnum.c for my_str_isnum in /home/klarma_n//progc/Jour_06
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 10 20:57:32 2011 nicolas klarman
** Last update Mon Oct 10 21:02:01 2011 nicolas klarman
*/

#include "stdlib.h"

int     str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 47 && str[i] < 58)
        i = i + 1;
      else
        return 0;
    }
  return 1;
}
