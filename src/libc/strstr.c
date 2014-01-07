/*
** my_strstr.c for my_strstr in /home/klarma_n//progc/Jour_06
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 10 12:16:46 2011 nicolas klarman
** Last update Mon Oct 10 15:14:47 2011 nicolas klarman
*/

#include "stdlib.h"

char	*strstr(char *str, char *to_find)
{
  int   i;
  int	j;
  int	start;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (to_find[0] == str[i])
	{
	  start = i;
	  while (to_find[j] == str[i])
	    {
	      if (to_find[j + 1] == '\0')
		{
		  return &str[start];
		}
	      i = i + 1;
	      j = j + 1;
	    }
	}
      j = 0;
      i = i + 1;
    }
  return 0;
}
