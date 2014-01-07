/*
** my_strlowcase.c for my_strlowcase.c in /home/klarma_n//progc/Jour_06
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 10 17:14:48 2011 nicolas klarman
** Last update Mon Oct 10 19:35:16 2011 nicolas klarman
*/

char	*my_strlowcase(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 64 && str[i] < 91)
	str[i] = str[i] + 32;
      i = i + 1;
    }
  return str;
}
