/*
** my_str_islower.c for my_str_islower in /home/klarma_n//progc/Jour_06
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 10 21:09:39 2011 nicolas klarman
** Last update Mon Oct 10 21:13:17 2011 nicolas klarman
*/

int     my_str_islower(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 96 && str[i] < 123)
        i = i + 1;
      else
        return 0;
    }
  return 1;
}
