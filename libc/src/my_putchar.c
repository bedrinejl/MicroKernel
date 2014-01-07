/*
** my_putchar.c for my_putchar in /home/klarma_n//progc/lib/my
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 24 11:01:03 2011 nicolas klarman
** Last update Mon Oct 24 11:02:16 2011 nicolas klarman
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}
