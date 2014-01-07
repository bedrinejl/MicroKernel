/*
** my_sort_int_tab.c for my_sort_int_tab in /home/klarma_n//progc/lib/my
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 24 10:53:43 2011 nicolas klarman
** Last update Mon Oct 24 10:53:56 2011 nicolas klarman
*/

/*
**
*/
void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	max;

  while (size > 0)
    {
      i = 1;
      max = 0;
      while (i < size)
	{
	  if (tab[i] > tab[max])
	    max = i;
	}
      size--;
      i = tab[max];
      tab[max] = tab[size];
      tab[size] = i;
    }
}
