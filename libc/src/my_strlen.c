/*
** my_strlen.c for my_strlen in /home/klarma_n//progc/Jour_04/ex_03
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Thu Oct  6 09:06:43 2011 nicolas klarman
** Last update Thu Oct  6 18:58:04 2011 nicolas klarman
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return i;
}
