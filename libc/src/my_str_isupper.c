/*
** my_str_isupper.c for my_is_upper in /home/klarma_n//progc/Jour_06
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 10 21:18:24 2011 nicolas klarman
** Last update Mon Oct 10 21:19:08 2011 nicolas klarman
*/

int     my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 64 && str[i] < 91)
        i = i + 1;
      else
        return 0;
    }
  return 1;
}
