/*
** my_strncmp.c for my_strncmp in /home/klarma_n//progc/Jour_06
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 10 16:18:50 2011 nicolas klarman
** Last update Mon Oct 10 19:28:43 2011 nicolas klarman
*/

#include "stdlib.h"

int	strncmp(char *s1, char *s2, int n)
{
  int   i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && n > 1)
    {
      i = i + 1;
      n = n - 1;
    }
  return s1[i] - s2[i];
}
