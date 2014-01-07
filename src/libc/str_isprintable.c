/*
** my_str_isprintable.c for my_str_isprintable in /home/klarma_n//progc/Jour_06
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 10 21:30:46 2011 nicolas klarman
** Last update Mon Oct 10 22:04:01 2011 nicolas klarman
*/

#include "stdlib.h"

int     str_isprintable(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] == 127)
        return 0;
      i = i + 1;
    }
  return 1;
}
