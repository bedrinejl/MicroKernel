/*
** my_str_isalpha.c for my_str_isalpha in /home/klarma_n//progc/Jour_06
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 10 20:44:00 2011 nicolas klarman
** Last update Mon Oct 10 20:54:17 2011 nicolas klarman
*/

int	my_str_isalpha(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 64 && str[i] < 91 || str[i] > 96 && str[i] < 123)
	i = i + 1;
      else
	return 0;
    }
  return 1;
}
