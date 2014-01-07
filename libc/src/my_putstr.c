/*
** my_putstr.c for my_putstr.c in /home/klarma_n//progc/Jour_04/ex_02
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Thu Oct  6 09:02:52 2011 nicolas klarman
** Last update Thu Oct  6 18:57:16 2011 nicolas klarman
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while ((str[i]) != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
