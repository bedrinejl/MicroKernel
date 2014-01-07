/*
** my_swap.c for my_swap in /home/klarma_n//progc/Jour_04/ex_o1
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Thu Oct  6 09:00:51 2011 nicolas klarman
** Last update Thu Oct  6 18:58:40 2011 nicolas klarman
*/

int	swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
  return 0;
}
