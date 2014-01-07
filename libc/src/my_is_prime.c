/*
** my_is_prime.c for my_is_prime in /home/klarma_n//progc/lib/my
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 24 10:55:42 2011 nicolas klarman
** Last update Mon Oct 24 10:55:45 2011 nicolas klarman
*/

/*
**
*/
int	my_is_prime(int n)
{
  int	i;

  if (n < 2)
    return 0;
  if (n == 2)
    return 1;
  if (!(n % 2))
    return 0;
  i = 3;
  while (n > (i * i))
    {
      if (!(n % i))
	return 0;
      i += 2;
    }
  return 1;
}
